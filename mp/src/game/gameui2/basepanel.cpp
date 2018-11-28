/*
Hyperborea (c) by Nicolas @ https://github.com/NicolasDe

Hyperborea is licensed under a
Creative Commons Attribution-ShareAlike 4.0 International License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-sa/4.0/>.
*/

#include "basepanel.h"
#include "./GameUI/IGameUI.h"
#include "ienginevgui.h"
#include "engine/ienginesound.h"
//#include "EngineInterface.h"
#include "tier0/dbg.h"
#include "ixboxsystem.h"
#include "GameUI2_Interface.h"
#include "game/client/IGameClientExports.h"
#include "gameui/igameconsole.h"
#include "inputsystem/iinputsystem.h"
#include "FileSystem.h"
#include "tier2/renderutils.h"

// BaseModUI High-level windows
//#include "gameconsole.h"
#include "vgui/IVGui.h"
#include "vgui/ISystem.h"
#include "vgui/ISurface.h"
#include "vgui/ILocalize.h"
#include "vgui_controls/AnimationController.h"
//#include "gameui2_util.h"
#include "vguimatsurface/imatsystemsurface.h"
#include "materialsystem/imaterialsystem.h"
#include "materialsystem/imesh.h"
#include "tier0/icommandline.h"
#include "fmtstr.h"
#include "smartptr.h"
//#include "nb_header_footer.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

static BasePanel* gBasePanel;
BasePanel* GetBasePanel()
{
	return gBasePanel;
}

BasePanel::BasePanel(vgui::VPANEL Parent) : BaseClass(nullptr)
{
	// Set Steam overlay position
	if ( SteamAPI && SteamAPI->SteamUtils() )
		SteamAPI->SteamUtils()->SetOverlayNotificationPosition( k_EPositionTopRight );

	SetParent(Parent);
	SetPaintBorderEnabled(false);
	SetPaintBackgroundEnabled(false);
	SetKeyBoardInputEnabled(true);
	SetMouseInputEnabled(true);
	SetProportional(false);
	SetVisible(false);
	SetPostChildPaintEnabled(true);

	g_pVGuiLocalize->AddFile("resource2/localization/gameui2_%language%.txt");

	MainMenuPanel = new MainMenu(nullptr);
	MainMenuHelperPanel = new MainMenuHelper(MainMenuPanel, nullptr);
	MainMenuHelperPanel->SetParent(this);
}

vgui::VPANEL BasePanel::GetVPanel()
{
	return BaseClass::GetVPanel();
}

void BasePanel::Create()
{
	ConColorMsg(Color(0, 148, 255, 255), "Trying to create BasePanel...\n");

	if (gBasePanel == nullptr)
	{
		gBasePanel = new BasePanel(GetGameUI2().GetRootPanel());
		ConColorMsg(Color(0, 148, 255, 255), "BasePanel created.\n");
	}
	else
	{
		ConColorMsg(Color(0, 148, 255, 255), "BasePanel already exists.\n");
	}
}

void BasePanel::OnThink()
{
	SetBounds(0, 0, GetGameUI2().GetViewport().x, GetGameUI2().GetViewport().y);

	BaseClass::OnThink();
}

void BasePanel::PaintBlurMask()
{
	BaseClass::PaintBlurMask();

	if (GetGameUI2().IsInLevel() == true)
	{
		vgui::surface()->DrawSetColor(Color(255, 255, 255, 255));
		vgui::surface()->DrawFilledRect(0, 0, GetWide(), GetTall());
	}
}