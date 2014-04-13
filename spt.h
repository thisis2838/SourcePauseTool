#ifndef __SPT_H__
#define __SPT_H__

#ifdef _WIN32
#pragma once
#endif

#include <string>

#include "engine/iserverplugin.h"

//---------------------------------------------------------------------------------
// Purpose: a sample 3rd party plugin class
//---------------------------------------------------------------------------------
class CSourcePauseTool : public IServerPluginCallbacks
{
public:
    CSourcePauseTool( );
    ~CSourcePauseTool( );

    // IServerPluginCallbacks methods
    virtual bool            Load( CreateInterfaceFn interfaceFactory, CreateInterfaceFn gameServerFactory );
    virtual void            Unload( void );
    virtual void            Pause( void );
    virtual void            UnPause( void );
    virtual const char     *GetPluginDescription( void );
    virtual void            LevelInit( char const *pMapName );
    virtual void            ServerActivate( edict_t *pEdictList, int edictCount, int clientMax );
    virtual void            GameFrame( bool simulating );
    virtual void            LevelShutdown( void );
    virtual void            ClientActive( edict_t *pEntity );
    virtual void            ClientDisconnect( edict_t *pEntity );
    virtual void            ClientPutInServer( edict_t *pEntity, char const *playername );
    virtual void            SetCommandClient( int index );
    virtual void            ClientSettingsChanged( edict_t *pEdict );
    virtual PLUGIN_RESULT   ClientConnect( bool *bAllowConnect, edict_t *pEntity, const char *pszName, const char *pszAddress, char *reject, int maxrejectlen );
    virtual PLUGIN_RESULT   ClientCommand( edict_t *pEntity, const CCommand &args );
    virtual PLUGIN_RESULT   NetworkIDValidated( const char *pszUserName, const char *pszNetworkID );
    virtual void            OnQueryCvarValueFinished( QueryCvarCookie_t iCookie, edict_t *pPlayerEntity, EQueryCvarValueStatus eStatus, const char *pCvarName, const char *pCvarValue );

    // added with version 3 of the interface.
    virtual void            OnEdictAllocated( edict_t *edict );
    virtual void            OnEdictFreed( const edict_t *edict );
};

std::string WStringToString( std::wstring wstr );

template <typename... Args>
void EngineLog( std::string format, Args... args )
{
    Log( ("SPT: " + format).c_str(), args... );
}

template <typename... Args>
void EngineDevLog( std::string format, Args... args )
{
    DevLog( ("SPT: " + format).c_str( ), args... );
}

template <typename... Args>
void EngineWarning( std::string format, Args... args )
{
    Warning( ("SPT: " + format).c_str( ), args... );
}

#endif // __SPT_H__