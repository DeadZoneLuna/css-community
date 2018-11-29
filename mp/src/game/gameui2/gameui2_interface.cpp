/*
Hyperborea (c) by Nicolas @ https://github.com/NicolasDe

Hyperborea is licensed under a
Creative Commons Attribution-ShareAlike 4.0 International License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-sa/4.0/>.
*/

#if !defined( _X360 )
#include <windows.h>
#endif
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <io.h>
#include <tier0/dbg.h>
#include <direct.h>

#ifdef SendMessage
#undef SendMessage
#endif

#include "FileSystem.h"
#include "GameUI2_Interface.h"
#include "BasePanel.h"
//#include "Sys_Utils.h"
#include "string.h"
#include "tier0/icommandline.h"

// interface to engine
//#include "EngineInterface.h"
//#include "VGuiSystemModuleLoader.h"
#include "bitmap/TGALoader.h"
//#include "GameConsole.h"
//#include "LoadingDialog.h"
//#include "CDKeyEntryDialog.h"
//#include "ModInfo.h"

// vgui2 interface
// note that GameUI2 project uses ..\vgui2\include, not ..\utils\vgui\include
#include "vgui/Cursor.h"
#include "tier1/KeyValues.h"
#include "vgui/ILocalize.h"
#include "vgui/IPanel.h"
#include "vgui/IScheme.h"
#include "vgui/IVGui.h"
#include "vgui/ISystem.h"
#include "vgui_controls/Menu.h"
#include "vgui_controls/PHandle.h"
#include "tier3/tier3.h"
#include "matsys_controls/matsyscontrols.h"
#include "tier0/dbg.h"
#include "gameui2_util.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

//-----------------------------------------------------------------------------
// Purpose: Used By Steam
//-----------------------------------------------------------------------------
static CSteamAPIContext SteamAPIContext;
CSteamAPIContext *SteamAPI = &SteamAPIContext;

//-----------------------------------------------------------------------------
// Purpose:
//-----------------------------------------------------------------------------
static IGameClientExports *GameClientExports = NULL;
IGameClientExports *GetClientExports()
{
	return GameClientExports;
}

//-----------------------------------------------------------------------------
// Purpose: singleton accessor
//-----------------------------------------------------------------------------
static CDllDemandLoader StaticGameUI("GameUI");
static GameUI2 StaticGameUI2;
GameUI2& GetGameUI2()
{
	return StaticGameUI2;
}

EXPOSE_SINGLE_INTERFACE_GLOBALVAR(GameUI2, IGameUI2, GAMEUI2_DLL_INTERFACE_VERSION, StaticGameUI2);

//-----------------------------------------------------------------------------
// Purpose: Initialization
//-----------------------------------------------------------------------------
void GameUI2::Initialize(CreateInterfaceFn AppFactory)
{
	MEM_ALLOC_CREDIT();
	ConnectTier1Libraries(&AppFactory, 1);
	ConnectTier2Libraries(&AppFactory, 1);
	ConVar_Register(FCVAR_CLIENTDLL);
	ConnectTier3Libraries(&AppFactory, 1);

	EngineClient = (IVEngineClient*)AppFactory(VENGINE_CLIENT_INTERFACE_VERSION, NULL);
	EngineSound = (IEngineSound*)AppFactory(IENGINESOUND_CLIENT_INTERFACE_VERSION, NULL);
	EngineVGui = (IEngineVGui*)AppFactory(VENGINE_VGUI_VERSION, NULL);
	EngineSurface = (vgui::ISurface*)AppFactory(VGUI_SURFACE_INTERFACE_VERSION, NULL);
	SoundEmitterSystemBase = (ISoundEmitterSystemBase*)AppFactory(SOUNDEMITTERSYSTEM_INTERFACE_VERSION, NULL);
	RenderView = (IVRenderView*)AppFactory(VENGINE_RENDERVIEW_INTERFACE_VERSION, NULL);
	Video = (IVideoServices*)AppFactory(VIDEO_SERVICES_INTERFACE_VERSION, NULL);
	MaterialSystem = (IMaterialSystem*)AppFactory(MATERIAL_SYSTEM_INTERFACE_VERSION, NULL);
	MaterialSystemSurface = (IMatSystemSurface*)AppFactory(MAT_SYSTEM_SURFACE_INTERFACE_VERSION, NULL);
	GameUIFuncs = (IGameUIFuncs*)AppFactory(VENGINE_GAMEUIFUNCS_VERSION, NULL);

	CreateInterfaceFn GameUIFactory = StaticGameUI.GetFactory();
	if (GameUIFactory)
		GameUI = (IGameUI*)GameUIFactory(GAMEUI_INTERFACE_VERSION, NULL);

	// Init Steam
	SteamAPI_InitSafe();
	SteamAPI->Init();

	if (EngineClient == nullptr ||
		EngineSound == nullptr ||
		EngineVGui == nullptr ||
		EngineSurface == nullptr ||
		SoundEmitterSystemBase == nullptr ||
		RenderView == nullptr ||
		Video == nullptr ||
		MaterialSystem == nullptr ||
		MaterialSystemSurface == nullptr ||
		GameUIFuncs == nullptr ||
		GameUI == nullptr)
		Error("GameUI2::Initialize() failed to get necessary interfaces.\n");

	GetBasePanel()->Create();

	if (GetBasePanel() != nullptr)
	{
		ConColorMsg(Color(255, 255, 0, 255), "Overriding original menu...\n");

		GameUI->SetMainMenuOverride(GetBasePanel()->GetVPanel());

		AnimationController = new vgui::AnimationController(GetBasePanel());
		AnimationController->SetProportional(false);
		AnimationController->SetScheme(GetBasePanel()->GetScheme());
	}
	else
	{
		ConColorMsg(Color(255, 255, 0, 255), "BasePanel initialization has failed.\n");
	}
}

//-----------------------------------------------------------------------------
// Purpose: connects to client interfaces
//-----------------------------------------------------------------------------
void GameUI2::Connect(CreateInterfaceFn GameFactory)
{
	GameClientExports = (IGameClientExports *)GameFactory(GAMECLIENTEXPORTS_INTERFACE_VERSION, NULL);

	AchievementMGR = EngineClient->GetAchievementMgr();

	if (!GameClientExports)
	{
		Error("GameUI2::Connect() failed to get necessary interfaces\n");
	}
}

//-----------------------------------------------------------------------------
// Purpose: Called to Shutdown the GameUI2 system
//-----------------------------------------------------------------------------
void GameUI2::Shutdown()
{
	// Shutdown Steam
	SteamAPI->Clear();

	ConVar_Unregister();
	DisconnectTier3Libraries();
	DisconnectTier2Libraries();
	DisconnectTier1Libraries();
}

//-----------------------------------------------------------------------------
// Purpose:
//-----------------------------------------------------------------------------
void GameUI2::OnInitialize()
{
	ConColorMsg(Color(255, 148, 0, 255), "On Initialize\n");

	GetBasePanel()->SetVisible(true);
	GetBasePanel()->GetMainMenuPanel()->Activate();
}

//-----------------------------------------------------------------------------
// Purpose:
//-----------------------------------------------------------------------------
void GameUI2::OnShutdown()
{
	ConColorMsg(Color(255, 148, 0, 255), "On Shutdown\n");
}

void GameUI2::OnUpdate()
{
//	ConColorMsg(Color(255, 148, 0, 255), "On Update: %f\n", GetTime());
	
	if (AnimationController != nullptr)
		AnimationController->UpdateAnimations(GetTime());
}

//-----------------------------------------------------------------------------
// Purpose:
//-----------------------------------------------------------------------------
void GameUI2::OnLevelInitializePreEntity()
{
	ConColorMsg(Color(255, 148, 0, 255), "On Level Initialize Pre Entity\n");
}

//-----------------------------------------------------------------------------
// Purpose:
//-----------------------------------------------------------------------------
void GameUI2::OnLevelInitializePostEntity()
{
	ConColorMsg(Color(255, 148, 0, 255), "On Level Initialize Post Entity\n");
}

//-----------------------------------------------------------------------------
// Purpose:
//-----------------------------------------------------------------------------
void GameUI2::OnLevelShutdown()
{
	ConColorMsg(Color(255, 148, 0, 255), "On Level Shutdown\n");

	if (AnimationController != nullptr)
	{
		AnimationController->UpdateAnimations(GetTime());
		AnimationController->RunAllAnimationsToCompletion();
	}
}

//-----------------------------------------------------------------------------
// Purpose: returns true if we're currently playing the game
//-----------------------------------------------------------------------------
bool GameUI2::IsInLevel()
{
	if (EngineClient->IsInGame() == true && EngineClient->IsLevelMainMenuBackground() == false)
		return true;

	return false;
}

//-----------------------------------------------------------------------------
// Purpose: returns true if we're at the main menu and a background level is loaded
//-----------------------------------------------------------------------------
bool GameUI2::IsInBackgroundLevel()
{
//	if ((EngineClient->IsInGame() == true && EngineClient->IsLevelMainMenuBackground() == true) || EngineClient->IsInGame() == false) // ?!
	if (EngineClient->IsLevelMainMenuBackground() == true || EngineClient->IsInGame() == false)
		return true;

	return false;
}

//-----------------------------------------------------------------------------
// Purpose: returns true if we're in a multiplayer game
//-----------------------------------------------------------------------------
bool GameUI2::IsInMultiplayer()
{
	return (IsInLevel() == true && EngineClient->GetMaxClients() > 1);
}

//-----------------------------------------------------------------------------
// Purpose: returns true if we're in a loading state
//-----------------------------------------------------------------------------
bool GameUI2::IsInLoading()
{
	return (EngineClient->IsDrawingLoadingImage() == true || EngineClient->GetLevelName() == 0) || (IsInLevel() == false && IsInBackgroundLevel() == false);
}

//-----------------------------------------------------------------------------
// Purpose: converts a string into localize text
//-----------------------------------------------------------------------------
wchar_t* GameUI2::ConvertToLocalizedString(const char* Text)
{
	// The alt. version of LocalizedString if something is wrong with current one:
	// wchar_t* LocalizedString = new wchar_t[2048];
	wchar_t* LocalizedString = (wchar_t*)malloc(sizeof(wchar_t) * 2048);
	
	if (Text[0] == '#' && g_pVGuiLocalize != nullptr)
	{
		wchar_t* TempString = g_pVGuiLocalize->Find(Text);
		if (TempString != nullptr)
		{
			const size_t TextSize = wcslen(TempString) + 1;
			wcsncpy(LocalizedString, TempString, TextSize);
			LocalizedString[TextSize - 1] = 0;
		}
		else
		{
			const size_t TextSize = strlen(Text) + 1;
			mbstowcs(LocalizedString, Text, TextSize);
		}
	}
	else
	{
		const size_t TextSize = strlen(Text) + 1;
		mbstowcs(LocalizedString, Text, TextSize);
	}

	return LocalizedString;
}

//-----------------------------------------------------------------------------
// Purpose:
//-----------------------------------------------------------------------------
void GameUI2::SetView(const CViewSetup& ViewSetup)
{
	View = ViewSetup;
}

//-----------------------------------------------------------------------------
// Purpose:
//-----------------------------------------------------------------------------
void GameUI2::SetFrustum(VPlane* Plane)
{
	Frustum = Plane;
}

//-----------------------------------------------------------------------------
// Purpose:
//-----------------------------------------------------------------------------
void GameUI2::SetMaskTexture(ITexture* Texture)
{
	MaskTexture = Texture;
}

//-----------------------------------------------------------------------------
// Purpose:
//-----------------------------------------------------------------------------
void GameUI2::SetRenderContext(IMatRenderContext* Context)
{
	RenderContext = Context;
}

//-----------------------------------------------------------------------------
// Purpose:
//-----------------------------------------------------------------------------
Vector2D GameUI2::GetViewport() const
{
//	return Vector2D(View.width, View.height);
	int32 ViewportX, ViewportY;
	EngineClient->GetScreenSize(ViewportX, ViewportY);
	return Vector2D(ViewportX, ViewportY);
}

//-----------------------------------------------------------------------------
// Purpose:
//-----------------------------------------------------------------------------
vgui::VPANEL GameUI2::GetRootPanel() const
{
	return EngineVGui->GetPanel(PANEL_GAMEUIDLL);
}

//-----------------------------------------------------------------------------
// Purpose:
//-----------------------------------------------------------------------------
vgui::VPANEL GameUI2::GetVPanel() const
{
	return GetBasePanel()->GetVPanel();
}

CON_COMMAND(gameui2, "List of arguments: version, help")
{
	if (args.ArgC() > 1)
	{
		if (Q_stristr(args.Arg(1), "version"))
		{
			ConColorMsg(Color(0, 148, 255, 255), "\nLabel:\t");
			Msg("%s\n", GAMEUI2_DLL_INTERFACE_VERSION);

			ConColorMsg(Color(0, 148, 255, 255), "Date:\t");
			Msg("%s\n", __DATE__);

			ConColorMsg(Color(0, 148, 255, 255), "Time:\t");
			Msg("%s\n", __TIME__);
		}
		else if (Q_stristr(args.Arg(1), "help"))
		{
			Msg("\nVisit ");
			ConColorMsg(Color(0, 148, 255, 255), "https://github.com/SourceEnginePlayground/Hyperborea");
			Msg(" to get the latest version or report an issue\n");
		}
	}
	else
	{
		ConColorMsg(Color(0, 148, 255, 255), "\nList of arguments: ");
		Msg("version, help\n");
	}
}