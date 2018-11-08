"Resource/UI/HudAchievementTrackerItem.res"
{	
	"HudAchievementTrackerItem"
	{
		"ControlName"	"EditablePanel"
		"fieldName"		"HudAchievementTrackerItem"
		"xpos"			"0"		[$WIN32]
		"ypos"			"0"		[$WIN32]
		"zpos"			"30"
		"wide"			"250"
		"tall"			"29"
		"visible"		"1"
		"enabled"		"1"	
		//"bgcolor_override"		"255 0 0 255"

		"PaintBackgroundType"	"2"
	}
	
	"AchievementName"
	{
		"ControlName"	"Label"
		"fieldName"		"AchievementName"
		"labeltext"		""
		"xpos"			"5"
		"ypos"			"0"
		"wide"			"170"
		"tall"			"8"
		"zpos"			"40"
		"textinsetx"	"5"
		"font"			"Default"
		"TextAlignment"		"north-west"
		"fgcolor_override"		"235 226 202 255"
		"visible"		"1"
	}
	
	"AchievementNameGlow"
	{
		"ControlName"	"Label"
		"fieldName"		"AchievementNameGlow"
		"labeltext"		""
		"xpos"			"5"
		"ypos"			"0"
		"wide"			"170"
		"tall"			"8"
		"zpos"			"40"
		"fgcolor_override"		"235 226 202 255"
		"font"			"Default"
		"textinsetx"	"5"
		"textAlignment"		"north-west"
		"visible"		"1"
	}
	
	"AchievementDesc"
	{
		"ControlName"	"Label"
		"fieldName"		"AchievementDesc"
		"labeltext"		""
		"xpos"			"5"
		"ypos"			"8"
		"wide"			"170"
		"tall"			"10"
		"zpos"			"40"
		"textinsetx"	"5"
		"font"			"HUDAchievementTiny"
		"wrap"			"1"
		"TextAlignment"		"north-west"
		"fgcolor_override"		"235 226 202 255"
		"visible"		"1"
	}
	
	"ProgressBarBG"
	{
		"ControlName"		"ImagePanel"
		"fieldName"		"ProgressBarBG"
		"xpos"		"7"
		"ypos"		"19"
		"wide"		"100"
		"tall"		"6"
		"fillcolor"	 "250 234 201 51"
		"zpos"			"40"
		"visible"		"0"
		"enabled"		"1"
	}
	
	"ProgressBar" // current completed
	{
		"ControlName"	"ImagePanel"
		"fieldName"		"ProgressBar"
		"xpos"			"7"
		"ypos"			"19"
		"wide"			"0"
		"tall"			"6"
		"fillcolor"		"251 235 202 255"
		"zpos"			"50"
		"visible"		"0"
		"enabled"		"1"
	}
}