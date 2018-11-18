/*
Hyperborea (c) by Nicolas @ https://github.com/NicolasDe

Hyperborea is licensed under a
Creative Commons Attribution-ShareAlike 4.0 International License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-sa/4.0/>.
*/
#include "gameui2_interface.h"
#include "panel_options.h"

#include "ienginevgui.h"
#include "vgui/ILocalize.h"
#include "vgui/ISurface.h"
#include "vgui/IVGui.h"

#ifdef MFS
#ifdef fuck
//#include "BasePanel.h"
#include "vgui_controls/PropertySheet.h"
#endif
#include "panel_options_SubKeyboard.h"
/*#include "panel_options_SubMouse.h"
#include "panel_options_SubAudio.h"
#include "panel_options_SubVideo.h"*/
#endif

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

#ifdef MFS
#ifdef fuck //This null is just so wrong, aight?
Panel_Options::Panel_Options(vgui::VPANEL Parent, const char* PanelName) : BaseClass(nullptr, PanelName), PropertyDialog(nullptr, PanelName)
{
	vgui::HScheme Scheme = vgui::scheme()->LoadSchemeFromFile("resource/schemepanel.res", "SchemePanel");
	Frame2D::SetScheme(Scheme);
#else
Panel_Options::Panel_Options(vgui::VPANEL Parent, const char* PanelName) : BaseClass(nullptr, PanelName)
{
	vgui::HScheme Scheme = vgui::scheme()->LoadSchemeFromFile("resource/schemepanel.res", "SchemePanel");
	SetScheme(Scheme);
#endif
#else
Panel_Options::Panel_Options(vgui::VPANEL Parent, const char* PanelName) : Frame2D(nullptr, PanelName)
{
	vgui::HScheme Scheme = vgui::scheme()->LoadSchemeFromFile("resource2/schemepanel.res", "SchemePanel");
	SetScheme(Scheme);
#endif

#ifdef fuck //todo:can we static_cast this shit?
	AnimationController = new vgui::AnimationController((dynamic_cast<Frame2D *>(this)));
#else
	AnimationController = new vgui::AnimationController(this);
#endif
	AnimationController->SetScheme(Scheme);
	AnimationController->SetProportional(false);

#ifdef fuck
	Frame2D::SetProportional(false);
	Frame2D::SetPaintBorderEnabled(false);
	Frame2D::SetPaintBackgroundEnabled(false);
	Frame2D::SetDeleteSelfOnClose(true);
	Frame2D::SetTitleBarVisible(false);
	Frame2D::SetSizeable(false);
	Frame2D::SetMoveable(false);
	Frame2D::SetEnabled(true);
	Frame2D::SetVisible(false);
	Frame2D::SetParent(Parent);

	Frame2D::Activate();
#else
	SetProportional(false);
	SetPaintBorderEnabled(false);
	SetPaintBackgroundEnabled(false);
	SetDeleteSelfOnClose(true);
	SetTitleBarVisible(false);
	SetSizeable(false);
	SetMoveable(false);
	SetEnabled(true);
	SetVisible(false);
	SetParent(Parent);

	Activate();
#endif

	#ifdef MFS
#ifdef fuck
#if 0
	m_pOptionsSubKeyboard = new COptionsSubKeyboard(dynamic_cast<Frame2D *>(this));
	m_pOptionsSubMouse = new COptionsSubMouse(dynamic_cast<Frame2D *>(this));
	m_pOptionsSubAudio = new COptionsSubAudio(dynamic_cast<Frame2D *>(this));
#endif
	//m_pOptionsSubVideo = new COptionsSubVideo(dynamic_cast<Frame2D *>(this));

	AddPage(new COptionsSubKeyboard(dynamic_cast<Frame2D *>(this)), "#GameUI_Keyboard");
	/*AddPage(new COptionsSubMouse(dynamic_cast<Frame2D *>(this)), "#GameUI_Mouse");
	AddPage(new COptionsSubAudio(dynamic_cast<Frame2D *>(this)), "#GameUI_Audio");
	AddPage(m_pOptionsSubVideo, "#GameUI_Video");*/
#else
#ifdef fuck2
#if 0
	m_pOptionsSubKeyboard = new COptionsSubKeyboard(this);
	m_pOptionsSubMouse = new COptionsSubMouse(this);
	m_pOptionsSubAudio = new COptionsSubAudio(this);
#endif
	//m_pOptionsSubVideo = new COptionsSubVideo(this);

	m_PDialog->AddPage(new COptionsSubKeyboard(dynamic_cast<Panel *>(this)), "#GameUI_Keyboard");
	/*m_PDialog->AddPage(new COptionsSubMouse(this), "#GameUI_Mouse");
	m_PDialog->AddPage(new COptionsSubAudio(this), "#GameUI_Audio");
	m_PDialog->AddPage(m_pOptionsSubVideo, "#GameUI_Video");*/
#endif
#endif
	#endif
	
	PanelTitle = GetGameUI2().ConvertToLocalizedString("#GameUI2_TitleOptions");
	PanelTitle = wcsupr(PanelTitle);

#ifdef fuck
	ButtonDone = new Button_Panel((dynamic_cast<Frame2D *>(this)), (dynamic_cast<Frame2D *>(this)), "");
	ButtonApply = new Button_Panel((dynamic_cast<Frame2D *>(this)), (dynamic_cast<Frame2D *>(this)), "");
	ButtonBack = new Button_Panel((dynamic_cast<Frame2D *>(this)), (dynamic_cast<Frame2D *>(this)), "action_back");
#else
	ButtonDone = new Button_Panel(this, this, "");
	ButtonApply = new Button_Panel(this, this, "");
	ButtonBack = new Button_Panel(this, this, "action_back");
#endif

	ButtonDone->SetButtonText("#GameUI2_Done");
	ButtonDone->SetButtonDescription("");

	ButtonApply->SetButtonText("#GameUI2_Apply");
	ButtonApply->SetButtonDescription("");

	ButtonBack->SetButtonText("#GameUI2_Back");
	ButtonBack->SetButtonDescription("");

#ifdef fuck
	SetApplyButtonVisible(true);
	GetPropertySheet()->SetTabWidth(84);
#endif
}

#ifdef MFS
//-----------------------------------------------------------------------------
// Purpose: Opens the gamma dialog directly
//-----------------------------------------------------------------------------
void Panel_Options::OpenGammaDialog()
{
	//m_pOptionsSubVideo->OpenGammaDialog();
}
#endif

void Panel_Options::ApplySchemeSettings(vgui::IScheme* Scheme)
{
	BaseClass::ApplySchemeSettings(Scheme);

#ifdef fuck
	BackgroundGradientTop = Frame2D::GetSchemeColor("Panel.Background.Gradient.Top", Scheme);
	BackgroundGradientBottom = Frame2D::GetSchemeColor("Panel.Background.Gradient.Bottom", Scheme);

	TitleColor = Frame2D::GetSchemeColor("Panel.Title.Color", Scheme);
#else
	BackgroundGradientTop = GetSchemeColor("Panel.Background.Gradient.Top", Scheme);
	BackgroundGradientBottom = GetSchemeColor("Panel.Background.Gradient.Bottom", Scheme);

	TitleColor = GetSchemeColor("Panel.Title.Color", Scheme);
#endif

	TitleOffsetX = atof(Scheme->GetResourceString("Panel.Title.OffsetX"));
	TitleOffsetY = atof(Scheme->GetResourceString("Panel.Title.OffsetY"));

	TitleFont = Scheme->GetFont("Panel.Title.Font");
}

void Panel_Options::Animations()
{
	if (AnimationController != nullptr)
		AnimationController->UpdateAnimations(GetGameUI2().GetTime());

#ifdef fuck
	Frame2D::SetBounds(0, 0, GetGameUI2().GetViewport().x, GetGameUI2().GetViewport().y);
#else
	SetBounds(0, 0, GetGameUI2().GetViewport().x, GetGameUI2().GetViewport().y);
#endif
}

void Panel_Options::OnThink()
{
	BaseClass::OnThink();

	SetContentBounds();
	Animations();

#ifdef fuck
	if (Frame2D::IsVisible() == false)
#else
	if (IsVisible() == false)
#endif
	{
		ConColorMsg(Color(0, 148, 255, 255), "Options panel is not visible, running all animations to completion...\n");

		if (AnimationController != nullptr)
			AnimationController->RunAllAnimationsToCompletion();
	}
}

void Panel_Options::SetContentBounds()
{	
#ifdef fuck
	ContentW = (Frame2D::GetWide() / 100) * 75;
#else
	ContentW = (GetWide() / 100) * 75;
#endif
	if (ContentW > 1920)
		ContentW = 1920;
	else if (ContentW < 800)
		ContentW = 800;

#ifdef fuck
	ContentH = (Frame2D::GetTall() / 100) * 75;
#else
	ContentH = (GetTall() / 100) * 75;
#endif
	if (ContentH > 1080)
		ContentH = 1080;
	else if (ContentH < 600)
		ContentH = 600;

#ifdef fuck
	ContentX0 = Frame2D::GetWide() / 2 - ContentW / 2;
	ContentY0 = Frame2D::GetTall() / 2 - ContentH / 2;
#else
	ContentX0 = GetWide() / 2 - ContentW / 2;
	ContentY0 = GetTall() / 2 - ContentH / 2;
#endif

	ContentX1 = ContentX0 + ContentW;
	ContentY1 = ContentY0 + ContentH;
}

void Panel_Options::Paint()
{
	BaseClass::Paint();

	DrawBackground();
	DrawTitle();
	DrawTabs();
	DrawBasicButtons();
}

void Panel_Options::PaintBlurMask()
{
	BaseClass::PaintBlurMask();
}

void Panel_Options::DrawBackground()
{
	vgui::surface()->DrawSetColor(BackgroundGradientTop);
#ifdef fuck
	vgui::surface()->DrawFilledRectFade(0, 0, Frame2D::GetWide() + 0, Frame2D::GetTall() + 0, 255, 0, false);
#else
	vgui::surface()->DrawFilledRectFade(0, 0, GetWide() + 0, GetTall() + 0, 255, 0, false);
#endif

	vgui::surface()->DrawSetColor(BackgroundGradientBottom);
#ifdef fuck
	vgui::surface()->DrawFilledRectFade(0, 0, Frame2D::GetWide() + 0, Frame2D::GetTall() + 0, 0, 255, false);
#else
	vgui::surface()->DrawFilledRectFade(0, 0, GetWide() + 0, GetTall() + 0, 0, 255, false);
#endif
}


void Panel_Options::DrawTitle()
{
	if (PanelTitle == nullptr)
		return;
	
	vgui::surface()->DrawSetTextColor(TitleColor);
	vgui::surface()->DrawSetTextFont(TitleFont);

	vgui::surface()->GetTextSize(TitleFont, PanelTitle, TitleSizeX, TitleSizeY);
	TitlePositionX = ContentX0 + TitleOffsetX;
	TitlePositionY = ContentY0 + TitleOffsetY;
	
	vgui::surface()->DrawSetTextPos(TitlePositionX, TitlePositionY);
	vgui::surface()->DrawPrintText(PanelTitle, wcslen(PanelTitle));
}

void Panel_Options::DrawTabs()
{
	// TEST!
	int32 X0, Y0;
	ButtonDone->GetPos(X0, Y0);
	
	int8 ObjectHeight = 48;
	int16 ContentHeight = Y0 - (TitlePositionY - TitleOffsetY + TitleSizeY);
	int8 ObjectsPerHeight = ContentHeight / ObjectHeight;

	for (int8 i = 0; i < ObjectsPerHeight; i++)
	{
		if (i % 2)
			vgui::surface()->DrawSetColor(Color(0, 0, 0, 20));
		else
			vgui::surface()->DrawSetColor(Color(255, 255, 255, 1));

		int32 ObjectY = TitlePositionY + TitleSizeY + (ObjectHeight * (i + 1)) - ObjectHeight;
		vgui::surface()->DrawFilledRect(ContentX0, ObjectY, ContentW + ContentX0, ObjectHeight + ObjectY);
	}
	// TEST!
}

void Panel_Options::DrawBasicButtons()
{
	ButtonDone->SetPos(ContentX0, ContentY1 - ButtonDone->GetTall());
	ButtonDone->SetVisible(true);

	int32 X0, Y0;
	ButtonDone->GetPos(X0, Y0);
	
	//MFS, Was ButtonDone->GetWide()
	ButtonApply->SetPos(X0 + ButtonApply->GetWide(), ContentY1 - ButtonApply->GetTall());
	ButtonApply->SetVisible(true);
	
	ButtonBack->SetPos(ContentX1 - ButtonBack->GetWide(), ContentY1 - ButtonBack->GetTall());
	ButtonBack->SetVisible(true);
}

void Panel_Options::OnCommand(char const* Command)
{
	if (Q_stristr(Command, "action_back"))
	{
#ifdef fuck
		Frame2D::Close();
#else
		Close();
#endif
	}
	else
	{
		BaseClass::OnCommand(Command);
	}
}

CON_COMMAND(gameui2_openoptionsdialog, "")
{
	new Panel_Options(GetGameUI2().GetVPanel(), "");
}