/*
Hyperborea (c) by Nicolas @ https://github.com/NicolasDe

Hyperborea is licensed under a
Creative Commons Attribution-ShareAlike 4.0 International License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-sa/4.0/>.
*/
#include "gameui2_interface.h"
#include "basepanel.h"

#include "vgui/IVGui.h"
#include "vgui/ISurface.h"
#include "vgui/ILocalize.h"

#include "tier0/icommandline.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

static BasePanel* gBasePanel;
BasePanel* GetBasePanel()
{
	return gBasePanel;
}

BasePanel::BasePanel(vgui::VPANEL Parent) : BaseClass(nullptr)
{
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