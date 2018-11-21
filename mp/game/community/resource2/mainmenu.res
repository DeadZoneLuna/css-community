"MainMenu"
{	
	"ResumeGame"
	{
		"text"			"#GameUI2_ResumeGame"
		"description"	"#GameUI2_ResumeGameDescription"
		"command"		"cvar gamemenucommand ResumeGame"
		"priority"		"13"
		"specifics"		"ingame"
	}
	
	"Disconnect"
	{
		"text"			"#GameUI2_Disconnect"
		"description"	"#GameUI2_DisconnectDescription"
		"command"		"cvar gamemenucommand Disconnect"
		"priority"		"12"
		"specifics"		"ingame"
	}
	
	"PlayerList"
	{
		"text"			"#GameUI2_PlayerList"
		"description"	"#GameUI2_PlayerListDescription"
		"command"		"cvar gamemenucommand OpenPlayerListDialog"
		"priority"		"11"
		"specifics"		"ingame"
	}
	
	"FindServrer"
	{
		"text"			"#GameUI2_FindServer"
		"description"	"#GameUI2_FindServerDescription"
		"command"		"cvar gamemenucommand OpenServerBrowser"
		"priority"		"10"
		"specifics"		"shared"
	}
	
	"CreateServer"
	{
		"text"			"#GameUI2_CreateServer"
		"description"	"#GameUI2_CreateServerDescription"
		"command"		"cvar gamemenucommand OpenCreateMultiplayerGameDialog"
		"priority"		"9"
		"specifics"		"shared"
	}
	
	"Achievements"
	{
		"text"			"#GameUI2_Achievements"
		"description"	"#GameUI2_AchievementsDescription"
		"command"		"cvar gamemenucommand OpenAchievementsDialog"
		"priority"		"8"
		"specifics"		"shared"
	}
	
	"ReportBug"
	{
		"text"			"#GameUI2_ReportBug"
		"description"	"#GameUI2_ReportBugDescription"
		"command"		"cvar bug"
		"priority"		"7"
		"specifics"		"shared"
	}
	
	"Benchmark"
	{
		"text"			"#GameUI2_LaunchBenchmark"
		"description"	"#GameUI2_LaunchBenchmarkDescription"
		"command"		"cvar gamemenucommand OpenBenchmarkDialog"
		"priority"		"6"
		"specifics"		"shared"
	}
	
	"Options"
	{
		"text"			"#GameUI2_Options"
		"description"	"#GameUI2_OptionsDescription"
		"command"		"cvar gamemenucommand openoptionsdialog" //gameui2_openoptionsdialog
		"priority"		"5"
		"specifics"		"shared"
	}

	"Quit"
	{
		"text"			"#GameUI2_Quit"
		"description"	"#GameUI2_QuitDescription"
		"command"		"cvar gamemenucommand quit"
		"priority"		"4"
		"specifics"		"shared"
	}
}