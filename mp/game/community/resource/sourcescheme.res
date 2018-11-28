#base "SourceSchemeBase.res"
Scheme
{
	Colors
	{
		// HUD		
		"White"				"227 227 227 200"
		"OffWhite"			"227 227 227 200"
		"DullWhite"			"125 125 125 200"
		"TransparentBlack"		"0 0 0 200"
		"Blank"				"0 0 0 0"
		"Black"				"54 54 54 200"	
		"BlackTran"			"54 54 54 200"
		"Gray"				"177 177 177 200"
		"ButtonHover"		"74 74 74 200"
		"WhiteBG"			"225 225 225 200"
		"HudBG"				"54 54 54 200"	
		
		// TF2
	    "TFDarkBrown"               "60 56 53 200"
	    "TFDarkBrownTransparent"    "60 56 53 200"
	    "TFTanBright"               "236 227 203 200"
	    "TFTanLight"                "100 100 100 200"
	    "TFTanMedium"               "80 80 80 200"
	    
	    "TFTanLightBright"          "229 223 211 200"
	    "TFTanLightDark"            "96 90 78 200"
	    
	    "TFOrangeBright"            "156 82 33 200"
	    
	    "TFTextBright"              "251 236 203 200"
	    "TFTextLight"               "201 188 162 200"
	    "TFTextMedium"              "131 121 104 200"
	    "TFTextMediumDark"          "104 96 83 200"
	    "TFTextBlack"               "42 39 37 200"
	    "TFTextDull"                "131 121 104 200"

	    "TFMediumBrown"		"69 64 58 200"

	    "QuickListBGDeselected"		"42 42 42 200"
	    "QuickListBGSelected"               "80 80 80 200"
	    
	    "Blank"				"0 0 0 0"

		"ControlBG"			"74 74 74 200"		// background color of controls
		"ControlDarkBG"		"104 104 104 200"	// darker background color; used for background of scrollbars
		"WindowBG"			"64 64 64 200"		// background color of text edit panes (chat, text entries, etc.)
		"SelectionBG"		"100 100 100 200"		// background color of any selected text or menu item
		"SelectionBG2"		"64 64 64 200"		// selection background in window w/o focus
		"ListBG"			"77 77 77 200"		// background of server browser, buddy list, etc.
	}
	BaseSettings
	{
		// scheme-specific colors
		Border.Bright					"200 200 200 200"
		Border.Dark						"40 40 40 200"
		Border.Selection				"0 0 0 200"	//default/selected button

		Button.TextColor				"196 196 196 200"
		Button.BgColor					"120 120 120 200"
		Button.ArmedTextColor			"White"
		Button.ArmedBgColor				"ButtonHover"
		Button.DepressedTextColor		"White"
		Button.DepressedBgColor			"Blank"
		Button.FocusBorderColor			"Blank"
		
		CheckButton.TextColor			"OffWhite"
		CheckButton.SelectedTextColor	"White"
		CheckButton.BgColor				"HudBG"
		CheckButton.HighlightFgColor	"WhiteBG"
		CheckButton.ArmedBgColor		"Blank"
		CheckButton.DepressedBgColor	"Blank"
		CheckButton.Border1  			"Black"
		CheckButton.Border2  			"Black"
		CheckButton.Check				"White"
		CheckButton.DisabledBgColor	   	"Blank"

		ToggleButton.SelectedTextColor	"TFTextBright"
		
		ComboBoxButton.ArrowColor		"DullWhite"
		ComboBoxButton.ArmedArrowColor	"White"
		ComboBoxButton.BgColor			"Blank"
		ComboBoxButton.DisabledBgColor	"Blank"
		
		RadioButton.TextColor			"DullWhite"
		RadioButton.SelectedTextColor	"White"
		RadioButton.ArmedTextColor		"TFTextMedium"
		
		Frame.BgColor					"82 82 82 200"
		Frame.OutOfFocusBgColor			"90 90 90 200"
		FrameGrip.Color1				"200 200 200 200"
		FrameGrip.Color2				"225 225 225 200"
		FrameTitleButton.FgColor		"200 200 200 200"
		FrameTitleBar.Font				"UiBold"
		FrameTitleBar.TextColor			"White"
		FrameTitleBar.DisabledTextColor	"200 200 200 200"
		
		Label.TextDullColor				"DullWhite"
		Label.TextColor					"OffWhite"
		Label.TextBrightColor			"White"
		Label.SelectedTextColor			"White"
		Label.BgColor					"Blank"
		Label.DisabledFgColor1			"117 117 117 200"
		Label.DisabledFgColor2			"30 30 30 200"
		
		ListPanel.TextColor					"OffWhite"
		ListPanel.BgColor					"54 54 54 200"
		ListPanel.SelectedBgColor			"WhiteBG"
		ListPanel.SelectedOutOfFocusBgColor	"100 100 100 200"
		
		MainMenu.TextColor			"White"
		MainMenu.ArmedTextColor		"HudBG"
		MainMenu.Inset				"32"
		
		Menu.TextInset					"6"
		Menu.FgColor			"White"
		Menu.BgColor					"24 24 24 200"
		Menu.ArmedFgColor		"WhiteBG"
		Menu.ArmedBgColor				"WhiteBG"
		Menu.DividerColor		"BorderDark"
		
		ScrollBarButton.FgColor				"White"
		ScrollBarButton.BgColor				"Blank"
		ScrollBarButton.ArmedFgColor		"White"
		ScrollBarButton.ArmedBgColor		"Blank"
		ScrollBarButton.DepressedFgColor	"White"
		ScrollBarButton.DepressedBgColor	"Blank"

		ScrollBarSlider.FgColor				"100 100 100 200"
		ScrollBarSlider.BgColor				"70 70 70 200"
		
		Slider.NobColor				"108 108 108 200"
		Slider.TextColor			"180 180 180 200"
		Slider.TrackColor			"31 31 31 200"
		Slider.DisabledTextColor1	"117 117 117 200"
		Slider.DisabledTextColor2	"30 30 30 200"
		
		TextEntry.TextColor			"OffWhite"
		TextEntry.DisabledTextColor	"DullWhite"
		TextEntry.SelectedBgColor	"WhiteBG"
		
		// Borrowed from CS:S SourceScheme
		Frame.TitleTextInsetX			14
		Frame.ClientInsetY				9
		Frame.ClientInsetX				8
		Frame.FocusTransitionEffectTime	"0.3"
		Frame.TransitionEffectTime		"0.3"
		Frame.AutoSnapRange				"0"
		FrameTitleButton.BgColor		"Blank"
		FrameTitleButton.DisabledFgColor	"200 200 200 200"
		FrameTitleButton.DisabledBgColor	"Blank"
		FrameSystemButton.FgColor		"Blank"
		FrameSystemButton.BgColor		"Blank"
		FrameSystemButton.Icon			""
		FrameSystemButton.DisabledIcon	""
		FrameTitleBar.BgColor			"Blank"			//Title Bar
		FrameTitleBar.DisabledBgColor	"Blank"
		GraphPanel.FgColor				"White"
		GraphPanel.BgColor				"TransparentBlack"
		ListPanel.TextBgColor				"Blank"
		ListPanel.SelectedTextColor			"Black"
		ListPanel.EmptyListInfoTextColor	"OffWhite"
		Menu.TextColor					"White"
		Menu.ArmedTextColor				"Black"
		Panel.FgColor					"DullWhite"
		Panel.BgColor					"Blank"
		ProgressBar.FgColor				"White"
		ProgressBar.BgColor				"TransparentBlack"
		PropertySheet.TextColor			"OffWhite"
		PropertySheet.SelectedTextColor	"White"
		PropertySheet.TransitionEffectTime	"0.25"
		RichText.TextColor				"OffWhite"
		RichText.BgColor				"54 54 54 200"
		RichText.SelectedTextColor		"Black"
		RichText.SelectedBgColor		"WhiteBG"
		ScrollBar.Wide					17
		SectionedListPanel.HeaderTextColor	"White"
		SectionedListPanel.HeaderBgColor	"Blank"
		SectionedListPanel.DividerColor		"Black"
		SectionedListPanel.TextColor		"DullWhite"
		SectionedListPanel.BrightTextColor	"White"
		SectionedListPanel.BgColor			"HudBG"
		SectionedListPanel.SelectedTextColor			"Black"
		SectionedListPanel.SelectedBgColor				"WhiteBG"
		SectionedListPanel.OutOfFocusSelectedTextColor	"Black"
		SectionedListPanel.OutOfFocusSelectedBgColor	"100 100 100 200"
		TextEntry.BgColor			"64 64 64 242"									//Enter field
		TextEntry.CursorColor		"OffWhite"
		TextEntry.DisabledBgColor	"Blank"
		TextEntry.SelectedTextColor	"Black"
		TextEntry.OutOfFocusSelectedBgColor	"100 100 100 128"
		TextEntry.FocusEdgeColor	"0 0 0 196"
		ToggleButton.SelectedTextColor	"White"
		Tooltip.TextColor			"0 0 0 196"
		Tooltip.BgColor				"WhiteBG"
		TreeView.BgColor			"TransparentBlack"
		WizardSubPanel.BgColor		"Blank"
		MainMenu.DepressedTextColor	"150 150 150 128"
		MainMenu.MenuItemHeight		"25"
		MainMenu.Backdrop			"0 0 0 156"
		Console.TextColor			"OffWhite"
		Console.DevTextColor		"White"
		NewGame.TextColor			"White"
		NewGame.FillColor			"14 14 14 200"
		NewGame.SelectionColor		"WhiteBG"
		NewGame.DisabledColor		"128 128 128 196"
	}
	
	Fonts
	{
		"MainMenuFont"
		{
			"1"	[$WIN32]
			{
				"name"		"StratumNo2-Bold"
				"tall"		"24"
				"weight"	"500"
				"additive"	"0"
				"antialias" "1"
			}
		}
		"MenuLarge"
		{
			"1"	[$X360]
			{
				"tall_hidef"		"24"
			}
		}
		"ServerBrowserTitle"
		{
			"1"
			{
				"name"		"StratumNo2"
				"tall"		"35"
				"tall_lodef"	"40"
				"weight"	"500"
				"additive"	"0"
				"antialias" "1"
			}
		}
		"Default" [$OSX]
		{
			"1"
			{
				"name"		"StratumNo2"
				"tall"		"14"
				"weight"	"500"
			}
		}
		"ServerBrowserSmall"
		{
			"1"
			{
				"name"		"StratumNo2"
				"tall"		"16"
				"weight"	"0"
				"range"		"0x0000 0x017F" //	Basic Latin, Latin-1 Supplement, Latin Extended-A
				"yres"	"480 599"
			}
			"2"
			{
				"name"		"StratumNo2"
				"tall"		"16"
				"weight"	"0"
				"range"		"0x0000 0x017F" //	Basic Latin, Latin-1 Supplement, Latin Extended-A
				"yres"	"600 767"
			}
			"3"
			{
				"name"		"StratumNo2"
				"tall"		"16"
				"weight"	"0"
				"range"		"0x0000 0x017F" //	Basic Latin, Latin-1 Supplement, Latin Extended-A
				"yres"	"768 1023"
				"antialias"	"1"
			}
			"4"
			{
				"name"		"StratumNo2"
				"tall"		"19"
				"weight"	"0"
				"range"		"0x0000 0x017F" //	Basic Latin, Latin-1 Supplement, Latin Extended-A
				"yres"	"1024 1199"
				"antialias"	"1"
			}
			"5"
			{
				"name"		"StratumNo2"
				"tall"		"19"
				"weight"	"0"
				"range"		"0x0000 0x017F" //	Basic Latin, Latin-1 Supplement, Latin Extended-A
				"yres"	"1200 6000"
				"antialias"	"1"
			}
		}	
		AchievementItemTitle	[$WIN32]
		{
			"1"
			{
				"name"		"StratumNo2" [!$OSX]
				"name"		"StratumNo2" [$OSX]
				"weight"		"1500"
				"tall"			"16" [!$OSX]
				"tall"			"18" [$OSX]
				"antialias"		"1"
			}
		}
		AchievementItemTitleLarge	[$WIN32]
		{
			"1"
			{
				"name"		"StratumNo2" [!$OSX]
				"name"		"StratumNo2" [$OSX]
				"weight"		"1500"
				"tall"			"18" [!$OSX]
				"tall"			"19" [$OSX]
				"antialias"		"1"
			}
		}
		AchievementItemDescription	[$WIN32]
		{
			"1"
			{
				"name"		"StratumNo2" [!$OSX]
				"name"		"StratumNo2" [$OSX]
				"weight"		"1000"
				"tall"			"14" [!$OSX]
				"tall"			"12" [$OSX]
				"antialias"		"1" [!$OSX]
			}
		}

	}
	CustomFontFiles
	{
		"1" "resource/Medium.otf"
	}	
}
