//============ Copyright (c) Valve Corporation, All rights reserved. ============

#ifndef ISTEAMMUSIC001_H
#define ISTEAMMUSIC001_H
#ifdef _WIN32
#pragma once
#endif

#include "MusicCommon.h"

//-----------------------------------------------------------------------------
// Purpose: Functions to control music playback in the steam client
//-----------------------------------------------------------------------------
class ISteamMusic001
{
public:
	virtual bool BIsEnabled() = 0;
	virtual bool BIsPlaying() = 0;
	
	virtual AudioPlayback_Status GetPlaybackStatus() = 0; 

	virtual void Play() = 0;
	virtual void Pause() = 0;
	virtual void PlayPrevious() = 0;
	virtual void PlayNext() = 0;

	// volume is between 0.0 and 1.0
	virtual void SetVolume( float flVolume ) = 0;
	virtual float GetVolume() = 0;
	
};
#endif // #define ISTEAMMUSIC001_H
