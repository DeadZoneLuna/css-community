//=========== (C) Copyright 1999 Valve, L.L.C. All rights reserved. ===========
//
// The copyright to the contents herein is the property of Valve, L.L.C.
// The contents may be used and/or copied only with the written permission of
// Valve, L.L.C., or in accordance with the terms and conditions stipulated in
// the agreement/contract under which the contents have been supplied.
//=============================================================================

// No spaces in event names, max length 32
// All strings are case sensitive
// total game event byte length must be < 1024
//
// valid data key types are:
//   none   : value is not networked
//   string : a zero terminated string
//   bool   : unsigned int, 1 bit
//   byte   : unsigned int, 8 bit
//   short  : signed int, 16 bit
//   long   : signed int, 32 bit
//   float  : float, 32 bit

"cstrikeevents"
{
	"player_death"				// a game event, name may be 32 characters long
	{
		// this extents the original player_death by a new fields
		"userid"	"short"   	// user ID who died				
		"attacker"	"short"	 	// user ID who killed
		"weapon"	"string" 	// weapon name killer used 
		"headshot"	"bool"		// singals a headshot
		"dominated"	"short"		// did killer dominate victim with this kill
		"revenge"	"short"		// did killer get revenge on victim with this kill
	}

	"player_hurt"
	{
		"userid"	"short"   	// player index who was hurt
		"attacker"	"short"	 	// player index who attacked
		"health"	"byte"		// remaining health points
		"armor"		"byte"		// remaining armor points
		"weapon"	"string"	// weapon name attacker used, if not the world
		"dmg_health"	"byte"	// damage done to health
		"dmg_armor"	"byte"		// damage done to armor
		"hitgroup"	"byte"		// hitgroup that was damaged
	}

	"bomb_beginplant"
	{
		"userid"	"short"		// player who is planting the bomb
		"site"		"short"		// bombsite index
	}

	"bomb_abortplant"
	{
		"userid"	"short"		// player who is planting the bomb
		"site"		"short"		// bombsite index
	}

	"bomb_planted"
	{
		"userid"	"short"		// player who planted the bomb
		"site"		"short"		// bombsite index
		"posx"		"short"		// position x
		"posy"		"short"		// position y
	}
	
	"bomb_defused"
	{
		"userid"	"short"		// player who defused the bomb
		"site"		"short"		// bombsite index
	}
	
	"bomb_exploded"
	{
		"userid"	"short"		// player who planted the bomb
		"site"		"short"		// bombsite index
	}
	
	"bomb_dropped"
	{
		"userid"	"short"		// player who dropped the bomb
	}
	
	"bomb_pickup"
	{
		"userid"	"short"		// player who picked up the bomb
	}

	"bomb_begindefuse"
	{
		"userid"	"short"		// player who is defusing
		"haskit"	"bool"
	}

	"bomb_abortdefuse"
	{
		"userid"	"short"		// player who was defusing
	}

	"hostage_follows"
	{
		"userid"	"short"		// player who touched the hostage
		"hostage"	"short"		// hostage entity index
	}
	
	"hostage_hurt"
	{
		"userid"	"short"		// player who hurt the hostage
		"hostage"	"short"		// hostage entity index
	}
	
	"hostage_killed"
	{
		"userid"	"short"		// player who killed the hostage
		"hostage"	"short"		// hostage entity index
	}
	
	"hostage_rescued"
	{
		"userid"	"short"		// player who rescued the hostage
		"hostage"	"short"		// hostage entity index
		"site"		"short"		// rescue site index
	}

	"hostage_stops_following"
	{
		"userid"	"short"		// player who rescued the hostage
		"hostage"	"short"		// hostage entity index
	}

	"hostage_rescued_all"
	{
	}

	"hostage_call_for_help"
	{
		"hostage"	"short"		// hostage entity index
	}
	
	"vip_escaped"
	{
		"userid"	"short"		// player who was the VIP
	}

	"vip_killed"
	{
		"userid"		"short"		// player who was the VIP
		"attacker"	"short"	 	// user ID who killed the VIP
	}

	"player_radio"
	{
		"userid"	"short"
		"slot"		"short"
	}

	"bomb_beep"
	{
		"entindex"	"long"		// c4 entity
	}

	"weapon_fire"
	{
		"userid"	"short"
		"weapon"	"string" 	// weapon name used
	}

	"weapon_fire_on_empty"
	{
		"userid"	"short"
		"weapon"	"string" 	// weapon name used
	}

	"weapon_reload"
	{
		"userid"	"short"
	}

	"weapon_zoom"
	{
		"userid"	"short"
	}

	"item_pickup"
	{
		"userid"	"short"
		"item"		"string"	// either a weapon such as 'tmp' or 'hegrenade', or an item such as 'nvgs'
	}

	"grenade_bounce"
	{
		"userid"	"short"
	}

	"hegrenade_detonate"
	{
		"userid"	"short"
	        "x"        "float"
	        "y"        "float"
	        "z"        "float"
	}

	"flashbang_detonate"
	{
		"userid"	"short"
	        "x"        "float"
	        "y"        "float"
	        "z"        "float"
	}

	"smokegrenade_detonate"
	{
		"userid"	"short"
	        "x"        "float"
	        "y"        "float"
	        "z"        "float"
	}

	"bullet_impact"
	{
		"userid"	"short"
		"x"		"float"
		"y"		"float"
		"z"		"float"
	}

	"player_footstep"
	{
		"userid"	"short"
	}

	"player_jump"
	{
		"userid"	"short"
	}

	"player_blind"
	{
		"userid"	"short"
	}

	"player_falldamage"
	{
		"userid"	"short"
		"damage"	"float"
	}

	"door_moving"
	{
		"entindex"	"long"
		"userid"		"short"
	}

	"round_freeze_end"
	{
	}

	"nav_blocked"
	{
		"area"		"long"
		"blocked"	"bool"
	}

	"nav_generate"
	{
	}
	
	"player_stats_updated"
	{
		"forceupload"	"bool"
	}
	
	"spec_target_updated"
	{
	}
	
	"cs_win_panel_round"
	{
		"show_timer_defend"	"bool"
		"show_timer_attack"	"bool"
		"timer_time"		"short"
		
		"final_event"		"byte"		//define in cs_gamerules.h
		
		"funfact_token"		"string"
		"funfact_player"	"short"
		"funfact_data1"		"long"
		"funfact_data2"		"long"
		"funfact_data3"		"long"
	}
	
	"cs_win_panel_match"			
	{		
		"t_score"						"short"
		"ct_score"						"short"		
		"t_kd"							"float"
		"ct_kd"							"float"		
		"t_objectives_done"				"short"
		"ct_objectives_done"			"short"		
		"t_money_earned"				"long"
		"ct_money_earned"				"long"
	}
	
	"show_freezepanel"
	{
		"killer"	"short"		// entindex of the killer entity
	}

	"hide_freezepanel"
	{
	}

	"freezecam_started"
	{
	}
	
	"player_avenged_teammate"
	{
		"avenger_id"			"short"
		"avenged_player_id"		"short"
	}
	
	"achievement_earned"
	{
		"player"	"byte"		// entindex of the player
		"achievement"	"short"		// achievement ID
	}
	
	"achievement_earned_local"
	{		
		"achievement"	"short"		// achievement ID
	}
	
	"match_end_conditions"
	{
		"frags"			"long"
		"max_rounds"	"long"
		"win_rounds"	"long"
		"time"			"long"
	}
	
	"round_mvp"
	{
		"userid"		"short"
		"reason"		"short"
	}
	
	"player_decal"
	{
		"userid"	"short"
	}
	
	"teamplay_round_start"			// round restart
	{
		"full_reset"	"bool"		// is this a full reset of the map
	}
	
	"christmas_gift_grab"
	{
		"userid"	"short"
	}
}
