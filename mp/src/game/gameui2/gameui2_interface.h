/*
Hyperborea (c) by Nicolas @ https://github.com/NicolasDe

Hyperborea is licensed under a
Creative Commons Attribution-ShareAlike 4.0 International License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-sa/4.0/>.
*/
#pragma once

#include "igameui2.h"
#include "steam/steam_api.h"
#include "cdll_int.h"
#include "engine/ienginesound.h"
#include "ienginevgui.h"
#include "SoundEmitterSystem/isoundemittersystembase.h"
#include "ivrenderview.h"
#include "view_shared.h"
#include "GameUI/IGameUI.h"
#include "IGameUIFuncs.h"
#include "vgui_controls/AnimationController.h"
#include "VGuiMatSurface/IMatSystemSurface.h"
#include "materialsystem/imaterialsystem.h"
#include "video/ivideoservices.h"
#include "vgui/ISurface.h"
#include "game/client/IGameClientExports.h"
#include "iachievementmgr.h"
#include "vgui_controls/Panel.h"
#include "vgui_controls/PHandle.h"
#include "convar.h"

extern IMatSystemSurface *g_pMatSystemSurface;

class GameUI2 : public IGameUI2
{
public:
	virtual void Initialize(CreateInterfaceFn AppFactory);
	virtual void Connect(CreateInterfaceFn GameFactory);
	virtual void Shutdown();

	virtual void OnInitialize();
	virtual void OnShutdown();
	virtual void OnUpdate();
	virtual void OnLevelInitializePreEntity();
	virtual void OnLevelInitializePostEntity();
	virtual void OnLevelShutdown();

	virtual bool IsInLevel();
	virtual bool IsInBackgroundLevel();
	virtual bool IsInMultiplayer();
	virtual bool IsInLoading();

	virtual void SetView(const CViewSetup& ViewSetup);
	virtual void SetFrustum(VPlane* Plane);
	virtual void SetMaskTexture(ITexture* Texture);
	virtual void SetRenderContext(IMatRenderContext* Context);

	virtual wchar_t* ConvertToLocalizedString(const char* Text);

	virtual Vector2D GetViewport() const;
	virtual vgui::VPANEL GetRootPanel() const;
	virtual	vgui::VPANEL GetVPanel() const;

	virtual vgui::AnimationController* GetAnimationController() const { return AnimationController; }

	virtual float GetTime() const { return Plat_FloatTime(); }
	virtual CViewSetup GetView() const { return View; }
	virtual VPlane* GetFrustum() const { return Frustum; }
	virtual ITexture* GetMaskTexture() const { return MaskTexture; }
	virtual IMatRenderContext* GetRenderContext() const { return RenderContext; }

	virtual IVEngineClient* GetEngineClient() const { return EngineClient; }
	virtual IEngineSound* GetEngineSound() const { return EngineSound; }
	virtual IEngineVGui* GetEngineVGui() const { return EngineVGui; }
	virtual vgui::ISurface* GetEngineSurface() const { return EngineSurface; }
	virtual ISoundEmitterSystemBase* GetSoundEmitterSystemBase() const { return SoundEmitterSystemBase; }
	virtual IVRenderView* GetRenderView() const { return RenderView; }
	virtual IVideoServices* GetVideo() const { return Video; }
	virtual IMaterialSystem* GetMaterialSystem() const { return MaterialSystem; }
	virtual IMatSystemSurface* GetMaterialSystemSurface() const { return MaterialSystemSurface; }
	virtual IAchievementMgr* GetAchievements() const { return AchievementMGR; }
	virtual IGameUIFuncs* GetGameUIFuncs() const { return GameUIFuncs; }
	virtual IGameUI* GetGameUI() const { return GameUI; }

private:
	CViewSetup View;
	VPlane* Frustum;
	ITexture* MaskTexture;
	IMatRenderContext* RenderContext;

	vgui::AnimationController* AnimationController;

	IVEngineClient* EngineClient;
	IEngineSound* EngineSound;
	IEngineVGui* EngineVGui;
	vgui::ISurface *EngineSurface;
	ISoundEmitterSystemBase* SoundEmitterSystemBase;
	IVRenderView* RenderView;
	IVideoServices *Video;
	IMaterialSystem* MaterialSystem;
	IMatSystemSurface* MaterialSystemSurface;
	IAchievementMgr *AchievementMGR;
	IGameUIFuncs *GameUIFuncs;
	IGameUI* GameUI;
};

// Purpose: singleton accessor
extern GameUI2& GetGameUI2();

// expose client interface
extern IGameClientExports *GetClientExports();

// used by steam
// todo find a better place for this
extern CSteamAPIContext *SteamAPI;