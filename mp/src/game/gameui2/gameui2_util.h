//====== Copyright © 1996-2005, Valve Corporation, All rights reserved. =======
//
// Purpose: 
//
//=============================================================================

#ifndef GAMEUI2_UTIL_H
#define GAMEUI2_UTIL_H
#ifdef _WIN32
#pragma once
#endif

char	*VarArgs( const char *format, ... );

#include "tier1/convar.h"

void GameUI2_MakeSafeName( const char *oldName, char *newName, int newNameBufSize );

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
class GameUI2ConVarRef
{
public:
	GameUI2ConVarRef( const char *pName );
	GameUI2ConVarRef( const char *pName, bool bIgnoreMissing );
	GameUI2ConVarRef( IConVar *pConVar );

	void Init( const char *pName, bool bIgnoreMissing );
	bool IsValid() const;
	bool IsFlagSet( int nFlags ) const;

	// Get/Set value
	float GetFloat() const;
	int GetInt() const;
	bool GetBool() const { return !!GetInt(); }
	const char *GetString() const;

	void SetValue( const char *pValue );
	void SetValue( float flValue );
	void SetValue( int nValue );
	void SetValue( bool bValue );

	const char *GetName() const;

	const char *GetDefault() const;

private:
	IConVar * m_pConVar;
	ConVar *m_pConVarState;
};

// In GAMUI2 we should never use the regular ConVarRef
#define ConVarRef GameUI2ConVarRef

//-----------------------------------------------------------------------------
// Did we find an existing convar of that name?
//-----------------------------------------------------------------------------
FORCEINLINE bool GameUI2ConVarRef::IsFlagSet( int nFlags ) const
{
	return ( m_pConVar->IsFlagSet( nFlags ) != 0 );
}

FORCEINLINE const char *GameUI2ConVarRef::GetName() const
{
	return m_pConVar->GetName();
}

//-----------------------------------------------------------------------------
// Purpose: Return ConVar value as a float
//-----------------------------------------------------------------------------
FORCEINLINE float GameUI2ConVarRef::GetFloat() const
{
	return m_pConVarState->GetFloat();
}

//-----------------------------------------------------------------------------
// Purpose: Return ConVar value as an int
//-----------------------------------------------------------------------------
FORCEINLINE int GameUI2ConVarRef::GetInt() const 
{
	return m_pConVarState->GetInt();
}

//-----------------------------------------------------------------------------
// Purpose: Return ConVar value as a string, return "" for bogus string pointer, etc.
//-----------------------------------------------------------------------------
FORCEINLINE const char *GameUI2ConVarRef::GetString() const 
{
	Assert( !IsFlagSet( FCVAR_NEVER_AS_STRING ) );
	return m_pConVarState->GetString();
}


FORCEINLINE void GameUI2ConVarRef::SetValue( const char *pValue )
{
	m_pConVar->SetValue( pValue );
}

FORCEINLINE void GameUI2ConVarRef::SetValue( float flValue )
{
	m_pConVar->SetValue( flValue );
}

FORCEINLINE void GameUI2ConVarRef::SetValue( int nValue )
{
	m_pConVar->SetValue( nValue );
}

FORCEINLINE void GameUI2ConVarRef::SetValue( bool bValue )
{
	m_pConVar->SetValue( bValue ? 1 : 0 );
}

FORCEINLINE const char *GameUI2ConVarRef::GetDefault() const
{
	return m_pConVarState->GetDefault();
}

#endif // GAMEUI2_UTIL_H
