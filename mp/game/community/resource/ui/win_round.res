"Resource/UI/Win_Round.res"
{
	"UpperPanel"
	{
		"ControlName"	"Panel"
		"xpos"			"5"
		"ypos"			"5"
		"zpos"			"1"
		"wide"			"210"
		"tall"			"35"
		"visible"		"1"
		"PaintBackgroundType"	"2"
		"bgcolor_override" "80 80 80 160"
		"RoundedCorners"	"3"
	}

	"WinLabel"
	{	
		"ControlName"	"Label"
		"font"			"WinPanelLarge"
		"xpos"			"0"
		"ypos"			"8"
		"zpos"			"2"
		"wide"			"220"
		"tall"			"16"
		"autoResize"	"0"
		"visible"		"1"
		"textAlignment"	"center"
		"fgcolor_override"	"184 0 0 255"
	}
	
	"WinDescription"
	{
		"ControlName"	"Label"
		"font"			"WinPanelTiny"
		"xpos"			"0"
		"ypos"			"27"
		"zpos"			"2"
		"wide"			"220"
		"tall"			"10"
		"autoResize"	"0"
		"pinCorner"		"0"
		"visible"		"1"
		"enabled"		"1"
		"labelText"		"%WIN_DESCRIPTION%"
		"textAlignment"	"center"
		"fgcolor_override"	"204 204 204 255"
	}

	"TimerIcon"
	{
		"ControlName"			"Label"
		"fieldName"				"IconTimer"
		"xpos"					"0"
		"ypos"					"-1"
		"zpos"					"2"
		"wide"					"10"
		"tall"					"12"
		"visible"				"1"
		"enabled"				"1"
		"font"					"WinPanelClock"
		"labelText"				"e"
		"fgcolor_override"		"69 151 229 255"
		"pin_to_sibling"		"TimerText"
		"pin_corner_to_sibling"	"5"
		"pin_to_sibling_corner"	"7"
	}
	
	"TimerText"
	{
		"ControlName"			"Label"
		"fieldName"				"TimerText"
		"font"					"WinPanelTiny"
		"xpos"					"190"
		"ypos"					"27"
		"zpos"					"2"
		"wide"					"46"
		"tall"					"10"
		"visible"				"1"
		"enabled"				"1"
		"labelText"				"%TIMER_TEXT%"
		"textAlignment"			"west"
		"fgcolor_override"		"204 204 204 255"
	}

	"MiddlePanel"
	{
		"ControlName"	"EditablePanel"
		"xpos"			"5"
		"ypos"			"45"
		"zpos"			"1"
		"wide"			"210"
		"tall"			"43"
		"visible"		"1"
		"bgcolor_override" "80 80 80 160"
		"RoundedCorners"	"0"
		
		"MVP_Background_Star"
		{
			"ControlName"	"ImagePanel"
			"xpos"			"-5"
			"ypos"			"-10"
			"zpos"			"2"
			"wide"			"100"
			"tall"			"100"
			"visible"		"1"
			"image"			"../hud/win_panel_bgstar"
			"drawcolor"		"0 40 50 80"
			"scaleImage"	"1"	
		}	
	}

	"MVP_AvatarGlow"
	{
		"ControlName"	"ImagePanel"
		"xpos"			"2"
		"ypos"			"36"
		"zpos"			"2"
		"wide"			"64"
		"tall"			"64"
		"visible"		"1"
		"enabled"		"1"
		"image"			"../hud/avatar_glow_64"
		"drawcolor"		"80 80 80 255"
		"scaleImage"	"1"	
	}	

	"MVP_Avatar"
	{
		"ControlName"	"CAvatarImagePanel"
		"xpos"			"18"
		"ypos"			"51"
		"zpos"			"3"
		"wide"			"32"
		"tall"			"32"
		"visible"		"1"
		"enabled"		"1"
		"scaleImage"	"1"	
	}	

	"MVP_Text"
	{
		"ControlName"	"Label"
		"font"			"WinPanelTiny"
		"xpos"			"55"
		"ypos"			"48"
		"zpos"			"3"
		"wide"			"150"
		"tall"			"37"
		"visible"		"1"
		"enabled"		"1"
		"labelText"		"%MVP_TEXT%"
		"textAlignment"	"west"
		"wrap"			"1"
		"fgcolor_override"	"204 204 204 255"
	}
	
	"MVP_Foreground_Star"
	{
		"ControlName"	"ImagePanel"
		"xpos"			"4"
		"ypos"			"43"
		"zpos"			"4"
		"wide"			"27"
		"tall"			"27"
		"visible"		"1"
		"image"			"../hud/win_panel_mvpstar"
		"scaleImage"	"1"	
	}	

	"LowerPanel"
	{
		"ControlName"	"Panel"
		"xpos"			"5"
		"ypos"			"93"
		"zpos"			"1"
		"wide"			"210"
		"tall"			"40"
		"visible"		"1"
		"PaintBackgroundType"	"2"
		"bgcolor_override" "80 80 80 160"
		"RoundedCorners"	"12"
	}

	"FunFact"
	{
		"ControlName"	"Label"
		"font"			"WinPanelTiny"
		"xpos"			"10"
		"ypos"			"95"
		"zpos"			"2"
		"wide"			"200"
		"tall"			"35"
		"autoResize"	"0"
		"visible"		"1"
		"enabled"		"1"
		"labelText"		"%FUNFACT%"
		"textAlignment"	"north-west"
		"wrap"			"1"
		"fgcolor_override"	"204 204 204 255"
	}
}