//============ Copyright (c) Valve Corporation, All rights reserved. ============

#ifndef ISTEAMMUSICREMOTECOMMON_H
#define ISTEAMMUSICREMOTECOMMON_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"


#define k_SteamMusicNameMaxLength 255
#define k_SteamMusicPNGMaxLength 65535
 





#define STEAMMUSICREMOTE_INTERFACE_VERSION "STEAMMUSICREMOTE_INTERFACE_VERSION001"

// callbacks
#if defined( VALVE_CALLBACK_PACK_SMALL )
#pragma pack( push, 4 )
#elif defined( VALVE_CALLBACK_PACK_LARGE )
#pragma pack( push, 8 )
#else
#error isteamclient.h must be included
#endif 


DEFINE_CALLBACK( MusicPlayerRemoteWillActivate_t, k_iSteamMusicRemoteCallbacks + 1)
END_DEFINE_CALLBACK_0()

DEFINE_CALLBACK( MusicPlayerRemoteWillDeactivate_t, k_iSteamMusicRemoteCallbacks + 2 )
END_DEFINE_CALLBACK_0()

DEFINE_CALLBACK( MusicPlayerRemoteToFront_t, k_iSteamMusicRemoteCallbacks + 3 )
END_DEFINE_CALLBACK_0()

DEFINE_CALLBACK( MusicPlayerWillQuit_t, k_iSteamMusicRemoteCallbacks + 4 )
END_DEFINE_CALLBACK_0()

DEFINE_CALLBACK( MusicPlayerWantsPlay_t, k_iSteamMusicRemoteCallbacks + 5 )
END_DEFINE_CALLBACK_0()

DEFINE_CALLBACK( MusicPlayerWantsPause_t, k_iSteamMusicRemoteCallbacks + 6 )
END_DEFINE_CALLBACK_0()

DEFINE_CALLBACK( MusicPlayerWantsPlayPrevious_t, k_iSteamMusicRemoteCallbacks + 7 )
END_DEFINE_CALLBACK_0()

DEFINE_CALLBACK( MusicPlayerWantsPlayNext_t, k_iSteamMusicRemoteCallbacks + 8 )
END_DEFINE_CALLBACK_0()

DEFINE_CALLBACK( MusicPlayerWantsShuffled_t, k_iSteamMusicRemoteCallbacks + 9 )
	CALLBACK_MEMBER( 0, bool, m_bShuffled )
END_DEFINE_CALLBACK_1()

DEFINE_CALLBACK( MusicPlayerWantsLooped_t, k_iSteamMusicRemoteCallbacks + 10 )
	CALLBACK_MEMBER(0, bool, m_bLooped )
END_DEFINE_CALLBACK_1()

DEFINE_CALLBACK( MusicPlayerWantsVolume_t, k_iSteamMusicCallbacks + 11 )
	CALLBACK_MEMBER(0, float, m_flNewVolume)
END_DEFINE_CALLBACK_1()

DEFINE_CALLBACK( MusicPlayerSelectsQueueEntry_t, k_iSteamMusicCallbacks + 12 )
	CALLBACK_MEMBER(0, int, nID )
END_DEFINE_CALLBACK_1()

DEFINE_CALLBACK( MusicPlayerSelectsPlaylistEntry_t, k_iSteamMusicCallbacks + 13 )
	CALLBACK_MEMBER(0, int, nID )
END_DEFINE_CALLBACK_1()


#pragma pack( pop )



#endif // #define ISTEAMMUSICREMOTE_H
