//====== Copyright 1996-2013, Valve Corporation, All rights reserved. =======
//
// Purpose: interface to steam ugc
//
//=============================================================================

#ifndef ISTEAMUGC001_H
#define ISTEAMUGC001_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"
#include "RemoteStorageCommon.h"
#include "UGCCommon.h"

//-----------------------------------------------------------------------------
// Purpose: Steam UGC support API
//-----------------------------------------------------------------------------
class ISteamUGC001
{
public:

	// Query UGC associated with a user. Creator app id or consumer app id must be valid and be set to the current running app.
	virtual UGCQueryHandle_t CreateQueryUserUGCRequest( AccountID_t unAccountID, EUserUGCList eListType, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eSortOrder, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint32 unPage ) = 0;

	// Query for all matching UGC. Creator app id or consumer app id must be valid and be set to the current running app.
	virtual UGCQueryHandle_t CreateQueryAllUGCRequest( EUGCQuery eQueryType, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint32 unPage ) = 0;

	// Send the query to Steam
	virtual SteamAPICall_t SendQueryUGCRequest( UGCQueryHandle_t handle ) = 0;

	// Retrieve an individual result after receiving the callback for querying UGC
	virtual bool GetQueryUGCResult( UGCQueryHandle_t handle, uint32 index, SteamUGCDetails_t *pDetails ) = 0;

	// Release the request to free up memory, after retrieving results
	virtual bool ReleaseQueryUGCRequest( UGCQueryHandle_t handle ) = 0;

	// Options to set for querying UGC
	virtual bool AddRequiredTag( UGCQueryHandle_t handle, const char *pTagName ) = 0;
	virtual bool AddExcludedTag( UGCQueryHandle_t handle, const char *pTagName ) = 0;
	virtual bool SetReturnLongDescription( UGCQueryHandle_t handle, bool bReturnLongDescription ) = 0;
	virtual bool SetReturnTotalOnly( UGCQueryHandle_t handle, bool bReturnTotalOnly ) = 0;

	// Options only for querying user UGC
	virtual bool SetCloudFileNameFilter( UGCQueryHandle_t handle, const char *pMatchCloudFileName ) = 0;

	// Options only for querying all UGC
	virtual bool SetMatchAnyTag( UGCQueryHandle_t handle, bool bMatchAnyTag ) = 0;
	virtual bool SetSearchText( UGCQueryHandle_t handle, const char *pSearchText ) = 0;
	virtual bool SetRankedByTrendDays( UGCQueryHandle_t handle, uint32 unDays ) = 0;

	// Request full details for one piece of UGC
	virtual SteamAPICall_t RequestUGCDetails( PublishedFileId_t nPublishedFileID ) = 0;

};

#endif // ISTEAMUGC001_H
