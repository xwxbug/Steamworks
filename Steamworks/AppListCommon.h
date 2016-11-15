//====== Copyright © 1996-2008, Valve Corporation, All rights reserved. =======
//
// Purpose: interface to app data in Steam
//
//=============================================================================

#ifndef APPLISTCOMMON_H
#define APPLISTCOMMON_H
#ifdef _WIN32
#pragma once
#endif


#include "SteamTypes.h"

#define STEAMAPPLIST_INTERFACE_VERSION_001 "STEAMAPPLIST_INTERFACE_VERSION001"

// callbacks
#if defined( VALVE_CALLBACK_PACK_SMALL )
#pragma pack( push, 4 )
#elif defined( VALVE_CALLBACK_PACK_LARGE )
#pragma pack( push, 8 )
#else
#error isteamclient.h must be included
#endif 


//---------------------------------------------------------------------------------
// Purpose: Sent when a new app is installed
//---------------------------------------------------------------------------------
DEFINE_CALLBACK( SteamAppInstalled_t, k_iSteamAppListCallbacks + 1 );
	CALLBACK_MEMBER( 0,	AppId_t,	m_nAppID )			// ID of the app that installs
END_DEFINE_CALLBACK_1()


//---------------------------------------------------------------------------------
// Purpose: Sent when an app is uninstalled
//---------------------------------------------------------------------------------
DEFINE_CALLBACK( SteamAppUninstalled_t, k_iSteamAppListCallbacks + 2 );
	CALLBACK_MEMBER( 0,	AppId_t,	m_nAppID )			// ID of the app that installs
END_DEFINE_CALLBACK_1()


#pragma pack( pop )
#endif // APPLISTCOMMON_H
