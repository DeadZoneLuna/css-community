#include "cbase.h"
#include "GameEventListener.h"
#include <ctime>

#ifdef CLIENT_DLL
#ifdef _WIN32
	#define _WINREG_
	#undef ReadConsoleInput
	#undef INVALID_HANDLE_VALUE
	#undef GetCommandLine
	#include <Windows.h>
#endif
#endif

#include "cs_shareddefs.h"
//#include "cs_web.h"

#ifdef CLIENT_DLL
ConVar cl_windows_flashtaskbar( "cl_windows_flashtaskbar", "1", 0, "Flash the taskbar icon (Windows) whenever a specifict event happen. 1 = Only when window is not active, 2 = Always" );
ConVar cl_windows_flashtaskbar_sound( "cl_windows_flashtaskbar_sound", "1", 0, "Play a sound whenever a specifict event happen. (Windows) 1 = Only when window is not active, 2 = Always" );
#endif

class CCSSystem : public CAutoGameSystem, public CGameEventListener
{
public:
    CCSSystem() : CAutoGameSystem( "CSSystem" )
    {
    }

    virtual void PostInit() OVERRIDE;

    virtual void LevelShutdownPreEntity() OVERRIDE;
    virtual void LevelInitPostEntity() OVERRIDE;

#ifdef CLIENT_DLL
	virtual void GameEventEffect();
#endif

    virtual void FireGameEvent( IGameEvent* pEvent ) OVERRIDE;
};

void CCSSystem::PostInit()
{
#ifdef CLIENT_DLL
    ListenForGameEvent( "round_end" );
    ListenForGameEvent( "round_start" );
    ListenForGameEvent( "teamplay_round_restart_seconds" );
#endif

    // Server Steam API hasn't been initialized yet.
#ifdef CLIENT_DLL
    //g_pCSSWeb->QueryVersionNumber();
#endif
}

void CCSSystem::LevelShutdownPreEntity()
{

}

void CCSSystem::LevelInitPostEntity()
{
#ifndef CLIENT_DLL
    /*if ( engine->IsDedicatedServer() )
    {
        // HACK!!! After the first map change, the api hasn't been initialized yet.
        if ( steamgameserverapicontext && !steamgameserverapicontext->SteamHTTP() )
            steamgameserverapicontext->Init();

        g_pCSSWeb->QueryVersionNumber();
    }*/
#endif
}


void CCSSystem::FireGameEvent( IGameEvent* pEvent )
{
#ifdef CLIENT_DLL
    if ( Q_strcmp( pEvent->GetName(), "round_end" ) == 0 )
    {
        DevMsg( "Client received round end event!\n" );
		GameEventEffect();
    }
    else if ( Q_strcmp( pEvent->GetName(), "round_start" ) == 0 )
    {
        DevMsg( "Client received round start event!\n" );
		GameEventEffect();
    }
	else if (Q_strcmp(pEvent->GetName(), "teamplay_round_restart_seconds") == 0)
	{
		DevMsg("Client received round restart event!\n");
		GameEventEffect();
	}
#endif
}

#ifdef CLIENT_DLL
void CCSSystem::GameEventEffect()
{
    bool bActive = engine->IsActiveApp();

    switch ( cl_windows_flashtaskbar_sound.GetInt() )
    {
    case 1 :
        if ( bActive )
            break;
    case 2 :
#ifdef _WIN32
        PlaySound( (LPCTSTR)SND_ALIAS_SYSTEMEXCLAMATION, NULL, SND_ALIAS_ID | SND_ASYNC );
#endif
        break;
    default :
        break;
    }

    switch ( cl_windows_flashtaskbar.GetInt() )
    {
    case 1 : 
        if ( bActive )
            break;
    case 2 :
        engine->FlashWindow();
        break;
    default :
        break;
    }
}
#endif

CCSSystem g_CSSystem;
