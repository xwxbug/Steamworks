//====== Copyright © 1996-2008, Valve Corporation, All rights reserved. =======
//
// Purpose: interface to app data in Steam
//
//=============================================================================

#ifndef ISTEAMAPPLIST001_H
#define ISTEAMAPPLIST001_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"
#include "AppListCommon.h"

//-----------------------------------------------------------------------------
// Purpose: This is a restricted interface that can only be used by previously approved apps,
//	contact your Steam Account Manager if you believe you need access to this API.
//	This interface lets you detect installed apps for the local Steam client, useful for debugging tools
//	to offer lists of apps to debug via Steam.
//-----------------------------------------------------------------------------
class ISteamAppList001
{
public:
	virtual uint32 GetNumInstalledApps() = 0;
	virtual uint32 GetInstalledApps( AppId_t *pvecAppID, uint32 unMaxAppIDs ) = 0;

	virtual int  GetAppName( AppId_t nAppID, char *pchName, int cchNameMax ) = 0; // returns -1 if no name was found
	virtual int  GetAppInstallDir( AppId_t nAppID, char *pchDirectory, int cchNameMax ) = 0; // returns -1 if no dir was found

	virtual int GetAppBuildId( AppId_t nAppID ) = 0; // return the buildid of this app, may change at any time based on backend updates to the game
};

#endif // ISTEAMAPPLIST001_H
