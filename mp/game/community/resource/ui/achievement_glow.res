//Simple file just for the glow flash underneath the achievement announce popup

"Resource/UI/Achievement_Glow.res"
{	
	"GlowPanel"
	{
		"ControlName"	"EditablePanel"
		"fieldName"		"GlowPanel"
		"xpos"			"c-256"
		"ypos"			"12"		
		"wide"			"512"		
		"tall"			"128"		
		"visible"		"1"
	
		"Glow"
		{
			"ControlName"	"ScalableImagePanel"
			"fieldName"		"Glow"
			"xpos"			"0"
			"ypos"			"0"
			"zpos"			"0"
			"wide"			"512"
			"tall"			"128"
			"visible"		"1"
			"enabled"		"1"	
			"image"			"../vgui/achievements/achievement_announce_glow"
			"scaleImage"	"1"	
			
			//"src_corner_height"		"23"				// pixels inside the image
			//"src_corner_width"		"23"
				
			//"draw_corner_width"		"6"				// screen size of the corners ( and sides ), proportional
			//"draw_corner_height" 	"6"	
		}		
	}
}
