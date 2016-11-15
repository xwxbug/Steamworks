//============ Copyright (c) Valve Corporation, All rights reserved. ============

#ifndef ISTEAMMUSICCOMMON_H
#define ISTEAMMUSICCOMMON_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
enum AudioPlayback_Status
{
	AudioPlayback_Undefined = 0, 
	AudioPlayback_Playing = 1,
	AudioPlayback_Paused = 2,
	AudioPlayback_Idle = 3
};



#define STEAMMUSIC_INTERFACE_VERSION_001 "STEAMMUSIC_INTERFACE_VERSION001"

// callbacks
#if defined( VALVE_CALLBACK_PACK_SMALL )
#pragma pack( push, 4 )
#elif defined( VALVE_CALLBACK_PACK_LARGE )
#pragma pack( push, 8 )
#else
#error isteamclient.h must be included
#endif 


DEFINE_CALLBACK( PlaybackStatusHasChanged_t, k_iSteamMusicCallbacks + 1 )
END_DEFINE_CALLBACK_0()

DEFINE_CALLBACK( VolumeHasChanged_t, k_iSteamMusicCallbacks + 2 )
 	CALLBACK_MEMBER( 0,	float, m_flNewVolume )
END_DEFINE_CALLBACK_1()

#pragma pack( pop )


#endif // ISTEAMMUSICCOMMON_H
