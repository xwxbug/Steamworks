//====== Copyright © 1996-2014 Valve Corporation, All rights reserved. =======
//
// Purpose: interface to Steam Video
//
//=============================================================================

#ifndef ISTEAMVIDEOCOMMON_H
#define ISTEAMVIDEOCOMMON_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"

#define STEAMVIDEO_INTERFACE_VERSION_001 "STEAMVIDEO_INTERFACE_V001"

// callbacks
#if defined( VALVE_CALLBACK_PACK_SMALL )
#pragma pack( push, 4 )
#elif defined( VALVE_CALLBACK_PACK_LARGE )
#pragma pack( push, 8 )
#else
#error isteamclient.h must be included
#endif 



DEFINE_CALLBACK( BroadcastUploadStart_t, k_iClientVideoCallbacks + 4 )
END_DEFINE_CALLBACK_0()

DEFINE_CALLBACK( BroadcastUploadStop_t, k_iClientVideoCallbacks + 5 )
	CALLBACK_MEMBER( 0, EBroadcastUploadResult, m_eResult )
END_DEFINE_CALLBACK_1()

DEFINE_CALLBACK( GetVideoURLResult_t, k_iClientVideoCallbacks + 11 )
	CALLBACK_MEMBER( 0, EResult, m_eResult )
	CALLBACK_MEMBER( 1, AppId_t, m_unVideoAppID )
	CALLBACK_MEMBER( 2, char, m_rgchURL[256] )
END_DEFINE_CALLBACK_1()


#pragma pack( pop )


#endif // ISTEAMVIDEOCOMMON_H
