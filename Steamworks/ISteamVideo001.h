//====== Copyright © 1996-2014 Valve Corporation, All rights reserved. =======
//
// Purpose: interface to Steam Video
//
//=============================================================================

#ifndef ISTEAMVIDEO001_H
#define ISTEAMVIDEO001_H
#ifdef _WIN32
#pragma once
#endif

#include "VideoCommon.h"

//-----------------------------------------------------------------------------
// Purpose: Steam Video API
//-----------------------------------------------------------------------------
class ISteamVideo001
{
public:

	// Get a URL suitable for streaming the given Video app ID's video
	virtual void GetVideoURL( AppId_t unVideoAppID ) = 0;

	// returns true if user is uploading a live broadcast
	virtual bool IsBroadcasting( int *pnNumViewers ) = 0;
};
#endif // ISTEAMVIDEO001_H
