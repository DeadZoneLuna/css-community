"Scheme"
{
	"BaseSettings"
	{
		"MainMenu.Logo.OffsetX"							"-1" // "5" // "1" // "0"
		"MainMenu.Logo.OffsetY"							"15" // "10" // "0"

		"MainMenu.Logo.AttachToMenu"					"1"
		"MainMenu.Logo.AlignToLeft"						"1"
	
		"MainMenu.Buttons.OffsetX"						"128" // "32"
		"MainMenu.Buttons.OffsetY"						"48" // "32"
		"MainMenu.Buttons.Space"						"0"
	
		"MainMenu.Button.Width.Out"						"392"
		"MainMenu.Button.Width.Over"					"392"
		"MainMenu.Button.Width.Pressed"					"392"
		"MainMenu.Button.Width.Released"				"392"

		"MainMenu.Button.Height.Out"					"40" // "40"
		"MainMenu.Button.Height.Over"					"40" // "64"
		"MainMenu.Button.Height.Pressed"				"40" // "64"
		"MainMenu.Button.Height.Released"				"40" // "64"

		"MainMenu.Button.Text.OffsetX"					"3" // "-1" // "10"
		"MainMenu.Button.Text.OffsetY"					"-6" // "0"

	//	"MainMenu.Button.Description.OffsetX"			"1"
	//	"MainMenu.Button.Description.OffsetY"			"-5" // "-3"

		"MainMenu.Button.Description.OffsetX.Out"		"31"
		"MainMenu.Button.Description.OffsetX.Over"		"1"
		"MainMenu.Button.Description.OffsetX.Pressed"	"1"
		"MainMenu.Button.Description.OffsetX.Released"	"1"

		"MainMenu.Button.Description.OffsetY.Out"		"-5"
		"MainMenu.Button.Description.OffsetY.Over"		"-5"
		"MainMenu.Button.Description.OffsetY.Pressed"	"-5"
		"MainMenu.Button.Description.OffsetY.Released"	"-5"

		"MainMenu.Button.Description.Hide.Out"			"1"
		"MainMenu.Button.Description.Hide.Over"			"0"
		"MainMenu.Button.Description.Hide.Pressed"		"0"
		"MainMenu.Button.Description.Hide.Released"		"0"

		"MainMenu.Button.Background.Blur.Out"			"0"
		"MainMenu.Button.Background.Blur.Over"			"0" // "1"
		"MainMenu.Button.Background.Blur.Pressed"		"0" // "1"
		"MainMenu.Button.Background.Blur.Released"		"0" // "1"

		"MainMenu.Button.Animation.Width"				"0.15"
		"MainMenu.Button.Animation.Height"				"0.25"
		"MainMenu.Button.Animation.Background"			"0.2"
		"MainMenu.Button.Animation.Text"				"0.2"
		"MainMenu.Button.Animation.Description"			"0.5"
	}

	"Colors"
	{
		"MainMenu.Logo.Left"							"255 255 255 255"
		"MainMenu.Logo.Right"							"255 255 255 255" // "255 217 73 255"
		
		"MainMenu.Button.Background.Out"				"0 0 0 0"
		"MainMenu.Button.Background.Over"				"0 0 0 50"
		"MainMenu.Button.Background.Pressed"			"20 20 20 255"
		"MainMenu.Button.Background.Released"			"0 0 0 50"

		"MainMenu.Button.Background.Outline.Out"		"0 0 0 0"
		"MainMenu.Button.Background.Outline.Over"		"0 0 0 0"
		"MainMenu.Button.Background.Outline.Pressed"	"0 0 0 0"
		"MainMenu.Button.Background.Outline.Released"	"0 0 0 0"

		"MainMenu.Button.Text.Out"						"163 157 156 255"
		"MainMenu.Button.Text.Over"						"255 255 255 255"
		"MainMenu.Button.Text.Pressed"					"180 180 180 200"
		"MainMenu.Button.Text.Released"					"255 255 255 255"

		"MainMenu.Button.Text.Glow.Out"					"255 186 33 0"
		"MainMenu.Button.Text.Glow.Over"				"255 186 33 255"
		"MainMenu.Button.Text.Glow.Pressed"				"255 186 33 0"
		"MainMenu.Button.Text.Glow.Released"			"255 186 33 0"

		"MainMenu.Button.Description.Out"				"0 0 0 0"
		"MainMenu.Button.Description.Over"				"180 180 180 200"
		"MainMenu.Button.Description.Pressed"			"0 0 0 0"
		"MainMenu.Button.Description.Released"			"0 0 0 0"
	}
	
	"Fonts"
	{
		"MainMenu.Logo.Font"
		{
			"settings"
			{
				"name"			"HYPE" // "Facile Sans"
				"tall"			"36" // "65"
				"weight"		"400"
				"antialias"		"1"
			}
		}
		
		"MainMenu.Button.Text.Font"
		{
			"settings"
			{
				"name"			"Nokia Pure Text Regular" // Roboto Medium
				"tall"			"25"
				"weight"		"400"
				"antialias"		"1"
			}
		}

		"MainMenu.Button.Text.Glow.Font"
		{
			"settings"
			{
				"name"			"Nokia Pure Text Regular" // Roboto Medium
				"tall"			"25"
				"weight"		"400"
				"antialias"		"0"
				"blur"			"3"
			}
		}

		"MainMenu.Button.Description.Font"
		{
			"settings"
			{
				"name"			"Noto Sans"
				"tall"			"16"
				"weight"		"400"
				"antialias"		"1"
			}
		}
	}

	"CustomFontFiles"
	{
		"file"		"resource2/fonts/NotoSans-Regular.ttf" // Noto Sans
		"file"		"resource2/fonts/FacileSans.ttf" // Facile Sans
		"file"		"resource2/fonts/Roboto-Medium.ttf" // Roboto Medium
		"file"		"resource2/fonts/nokia-pure-text.ttf" // Nokia Pure Text Regular
		"file"		"resource2/fonts/HYPE.ttf" // HYPE
	}
}