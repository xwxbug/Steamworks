//====== Copyright ?1996-2014 Valve Corporation, All rights reserved. =======
//
// Purpose: interface to Steam Inventory
//
//=============================================================================

#ifndef INVENTORYCOMMON_H
#define INVENTORYCOMMON_H
#ifdef _WIN32
#pragma once
#endif

#define STEAMINVENTORY_INTERFACE_VERSION_001 "STEAMINVENTORY_INTERFACE_V001"


// callbacks
#if defined( VALVE_CALLBACK_PACK_SMALL )
#pragma pack( push, 4 )
#elif defined( VALVE_CALLBACK_PACK_LARGE )
#pragma pack( push, 8 )
#else
#error isteamclient.h must be included
#endif


// Every individual instance of an item has a globally-unique ItemInstanceID.
// This ID is unique to the combination of (player, specific item instance)
// and will not be transferred to another player or re-used for another item.
typedef uint64 SteamItemInstanceID_t;

static const SteamItemInstanceID_t k_SteamItemInstanceIDInvalid = (SteamItemInstanceID_t)~0;

// Types of items in your game are identified by a 32-bit "item definition number".
// Valid definition numbers are between 1 and 999999999; numbers less than or equal to
// zero are invalid, and numbers greater than or equal to one billion (1x10^9) are
// reserved for internal Steam use.
typedef int32 SteamItemDef_t;


enum ESteamItemFlags
{
	// Item status flags - these flags are permanently attached to specific item instances
	k_ESteamItemNoTrade = 1 << 0, // This item is account-locked and cannot be traded or given away.

	// Action confirmation flags - these flags are set one time only, as part of a result set
	k_ESteamItemRemoved = 1 << 8,	// The item has been destroyed, traded away, expired, or otherwise invalidated
	k_ESteamItemConsumed = 1 << 9,	// The item quantity has been decreased by 1 via ConsumeItem API.

	// All other flag bits are currently reserved for internal Steam use at this time.
	// Do not assume anything about the state of other flags which are not defined here.
};

struct SteamItemDetails_t
{
	SteamItemInstanceID_t m_itemId;
	SteamItemDef_t m_iDefinition;
	uint16 m_unQuantity;
	uint16 m_unFlags; // see ESteamItemFlags
};

typedef int32 SteamInventoryResult_t;

static const SteamInventoryResult_t k_SteamInventoryResultInvalid = -1;




// SteamInventoryResultReady_t callbacks are fired whenever asynchronous
// results transition from "Pending" to "OK" or an error state. There will
// always be exactly one callback per handle.
struct SteamInventoryResultReady_t
{
	enum { k_iCallback = k_iClientInventoryCallbacks + 0 };
	SteamInventoryResult_t m_handle;
	EResult m_result;
};


// SteamInventoryFullUpdate_t callbacks are triggered when GetAllItems
// successfully returns a result which is newer / fresher than the last
// known result. (It will not trigger if the inventory hasn't changed,
// or if results from two overlapping calls are reversed in flight and
// the earlier result is already known to be stale/out-of-date.)
// The normal ResultReady callback will still be triggered immediately
// afterwards; this is an additional notification for your convenience.
struct SteamInventoryFullUpdate_t
{
	enum { k_iCallback = k_iClientInventoryCallbacks + 1 };
	SteamInventoryResult_t m_handle;
};


// A SteamInventoryDefinitionUpdate_t callback is triggered whenever
// item definitions have been updated, which could be in response to 
// LoadItemDefinitions() or any other async request which required
// a definition update in order to process results from the server.
struct SteamInventoryDefinitionUpdate_t
{
	enum { k_iCallback = k_iClientInventoryCallbacks + 2 };
};

#pragma pack( pop )


#endif // INVENTORYCOMMON_H
