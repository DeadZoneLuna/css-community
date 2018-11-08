//This governs all the elements of the achievement popup info panel
//The glow portion is controlled by the parent class and is instead loaded from Achievement_Glow.res

"Resource/UI/Achievement_Popup.res"
{	

	"InfoPanel"
	{
		"ControlName"	"CCSAchivementInfoPanel"
		"fieldName"		"InfoPanel"
		"xpos"						"c-125"	
		"ypos"						"56"
		"zpos"						"1"
		"wide"						"250"
		"tall"						"40"
		"autoResize"				"0"
		"visible"					"1"
		"enabled"					"1"
		"tabPosition"				"0"
		"settitlebarvisible"		"0"
		"pinCorner"					"0"		
		"PaintBackgroundType"		"2"	
	}
			
	"Icon"
	{
		"ControlName"	"ScalableImagePanel"
		"fieldName"		"Icon"
		"xpos"			"2"
		"ypos"			"2"		
		"wide"			"36"
		"tall"			"36"
		"visible"		"1"
		"scaleImage"	"1"
	}
			
	"Name"
	{
		"ControlName"	"label"
		"fieldName"		"Name"
		"labelText"		"%AchievementName_Text%"
		"xpos"			"40"
		"ypos"			"0"
		"wide"			"200"
		"tall"			"16"
		"font"			"AchievementPopupTitle"
		"textAlignment"	"west"
	}
	
	"Description"
	{
		"ControlName"	"label"
		"fieldName"		"Description"
		"labelText"		"%AchievementDescription_Text%"
		"xpos"			"40"
		"ypos"			"16"
		"wide"			"200"
		"tall"			"24"
		"font"			"AchievementPopupDescription"
		"wrap"			"1"
		"textAlignment"	"north-west"
	}	
}
