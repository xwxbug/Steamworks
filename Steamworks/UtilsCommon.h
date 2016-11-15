//==========================  Open Steamworks  ================================
//
// This file is part of the Open Steamworks project. All individuals associated
// with this project do not claim ownership of the contents
// 
// The code, comments, and all related files, projects, resources,
// redistributables included with this project are Copyright Valve Corporation.
// Additionally, Valve, the Valve logo, Half-Life, the Half-Life logo, the
// Lambda logo, Steam, the Steam logo, Team Fortress, the Team Fortress logo,
// Opposing Force, Day of Defeat, the Day of Defeat logo, Counter-Strike, the
// Counter-Strike logo, Source, the Source logo, and Counter-Strike Condition
// Zero are trademarks and or registered trademarks of Valve Corporation.
// All other trademarks are property of their respective owners.
//
//=============================================================================

#ifndef UTILSCOMMON_H
#define UTILSCOMMON_H
#ifdef _WIN32
#pragma once
#endif



#define CLIENTUTILS_INTERFACE_VERSION "CLIENTUTILS_INTERFACE_VERSION001"

#define STEAMUTILS_INTERFACE_VERSION_001 "SteamUtils001"
#define STEAMUTILS_INTERFACE_VERSION_003 "SteamUtils003"
#define STEAMUTILS_INTERFACE_VERSION_002 "SteamUtils002"
#define STEAMUTILS_INTERFACE_VERSION_004 "SteamUtils004"
#define STEAMUTILS_INTERFACE_VERSION_005 "SteamUtils005"
#define STEAMUTILS_INTERFACE_VERSION_006 "SteamUtils006"
#define STEAMUTILS_INTERFACE_VERSION_007 "SteamUtils007"
#define STEAMUTILS_INTERFACE_VERSION_008 "SteamUtils008"


// Steam API call failure results
typedef enum ESteamAPICallFailure
{
	k_ESteamAPICallFailureNone = -1,			// no failure
	k_ESteamAPICallFailureSteamGone = 0,		// the local Steam process has gone away
	k_ESteamAPICallFailureNetworkFailure = 1,	// the network connection to Steam has been broken, or was already broken
	// SteamServersDisconnected_t callback will be sent around the same time
	// SteamServersConnected_t will be sent when the client is able to talk to the Steam servers again
	k_ESteamAPICallFailureInvalidHandle = 2,	// the SteamAPICall_t handle passed in no longer exists
	k_ESteamAPICallFailureMismatchedCallback = 3,// GetAPICallResult() was called with the wrong callback type for this API call
} ESteamAPICallFailure;

typedef enum EConfigStore
{
	k_EConfigStoreInvalid = 0,
	k_EConfigStoreInstall = 1,
	k_EConfigStoreUserRoaming = 2,
	k_EConfigStoreUserLocal = 3,
	k_EConfigStoreMax = 4,
} EConfigStore;


enum ESpewGroup
{
	k_ESpewGroupConsole = 0,
	k_ESpewGroupPublish = 1,
	k_ESpewGroupBootstrap = 2,
	k_ESpewGroupStartup = 3,
	k_ESpewGroupService = 4,
	k_ESpewGroupFileop = 5,
	k_ESpewGroupSystem = 6,
	k_ESpewGroupSmtp = 7,
	k_ESpewGroupAccount = 8,
	k_ESpewGroupJob = 9,
	k_ESpewGroupCrypto = 10,
	k_ESpewGroupNetwork = 11,
	k_ESpewGroupVac = 12,
	k_ESpewGroupClient = 13,
	k_ESpewGroupContent = 14,
	k_ESpewGroupCloud = 15,
	k_ESpewGroupLogon = 16,
	k_ESpewGroupClping = 17,
	k_ESpewGroupThreads = 18,
	k_ESpewGroupBsnova = 19,
	k_ESpewGroupTest = 20,
	k_ESpewGroupFiletx = 21,
	k_ESpewGroupStats = 22,
	k_ESpewGroupSrvping = 23,
	k_ESpewGroupFriends = 24,
	k_ESpewGroupChat = 25,
	k_ESpewGroupGuestpass = 26,
	k_ESpewGroupLicense = 27,
	k_ESpewGroupP2p = 28,
	k_ESpewGroupDatacoll = 29,
	k_ESpewGroupDrm = 30,
	k_ESpewGroupSvcm = 31,
	k_ESpewGroupHttpclient = 32,
	k_ESpewGroupHttpserver = 33,
};

enum EUIMode
{
	k_EUIModeNormal = 0,
	k_EUIModeTenFoot = 1,
};

// Input modes for the Big Picture gamepad text entry
enum EGamepadTextInputMode
{
	k_EGamepadTextInputModeNormal = 0,
	k_EGamepadTextInputModePassword = 1
};


// Controls number of allowed lines for the Big Picture gamepad text entry
enum EGamepadTextInputLineMode
{
	k_EGamepadTextInputLineModeSingleLine = 0,
	k_EGamepadTextInputLineModeMultipleLines = 1
};

enum EWindowType
{
	// TODO: Reverse this enum
};

#pragma pack( push, 8 )
//-----------------------------------------------------------------------------
// Purpose: The country of the user changed
//-----------------------------------------------------------------------------
struct IPCountry_t
{
	enum { k_iCallback = k_iSteamUtilsCallbacks + 1 };
};


//-----------------------------------------------------------------------------
// Purpose: Fired when running on a laptop and less than 10 minutes of battery is left, fires then every minute
//-----------------------------------------------------------------------------
struct LowBatteryPower_t
{
	enum { k_iCallback = k_iSteamUtilsCallbacks + 2 };

	uint8 m_nMinutesBatteryLeft;
};

//-----------------------------------------------------------------------------
// Purpose: called when a SteamAsyncCall_t has completed (or failed)
//-----------------------------------------------------------------------------
struct SteamAPICallCompleted_t
{
	enum { k_iCallback = k_iSteamUtilsCallbacks + 3 };

	SteamAPICall_t m_hAsyncCall;
	int m_iCallback;
	uint32 m_cubParam;
};


//-----------------------------------------------------------------------------
// called when Steam wants to shutdown
//-----------------------------------------------------------------------------
struct SteamShutdown_t
{
	enum { k_iCallback = k_iSteamUtilsCallbacks + 4 };
};

//-----------------------------------------------------------------------------
// results for CheckFileSignature
//-----------------------------------------------------------------------------
enum ECheckFileSignature
{
	k_ECheckFileSignatureInvalidSignature = 0,
	k_ECheckFileSignatureValidSignature = 1,
	k_ECheckFileSignatureFileNotFound = 2,
	k_ECheckFileSignatureNoSignaturesFoundForThisApp = 3,
	k_ECheckFileSignatureNoSignaturesFoundForThisFile = 4,
};

//-----------------------------------------------------------------------------
// callback for CheckFileSignature
//-----------------------------------------------------------------------------
struct CheckFileSignature_t
{
	enum { k_iCallback = k_iSteamUtilsCallbacks + 5 };

	ECheckFileSignature m_eCheckFileSignature;
};

#ifdef _PS3
//-----------------------------------------------------------------------------
// callback for NetCtlNetStartDialog finishing on PS3
//-----------------------------------------------------------------------------
struct NetStartDialogFinished_t
{
	enum { k_iCallback = k_iSteamUtilsCallbacks + 6 };
};

//-----------------------------------------------------------------------------
// callback for NetCtlNetStartDialog unloaded on PS3
//-----------------------------------------------------------------------------
struct NetStartDialogUnloaded_t
{
	enum { k_iCallback = k_iSteamUtilsCallbacks + 7 };
};

//-----------------------------------------------------------------------------
// callback for system menu closing on PS3 - should trigger resyncronizing friends list, etc.
//-----------------------------------------------------------------------------
struct PS3SystemMenuClosed_t
{
	enum { k_iCallback = k_iSteamUtilsCallbacks + 8 };
};

//-----------------------------------------------------------------------------
// callback for NP message being selected by user on PS3 - should trigger handling of message if it's a lobby invite, etc.
//-----------------------------------------------------------------------------
struct PS3NPMessageSelected_t
{
	enum { k_iCallback = k_iSteamUtilsCallbacks + 9 };
	uint32 dataid;
};

//-----------------------------------------------------------------------------
// callback for when the PS3 keyboard dialog closes
//-----------------------------------------------------------------------------
struct PS3KeyboardDialogFinished_t
{
	enum { k_iCallback = k_iSteamUtilsCallbacks + 10 };
};

// k_iSteamUtilsCallbacks + 11 is taken
struct SteamConfigStoreChanged_t
{
	enum { k_iCallback = k_iSteamUtilsCallbacks + 11 };

	EConfigStore m_eConfigStore;
	char m_szRootOfChanges[ 255 ];
};

//-----------------------------------------------------------------------------
// callback for PSN status changing on PS3
//-----------------------------------------------------------------------------
struct PS3PSNStatusChange_t
{
	enum { k_iCallback = k_iSteamUtilsCallbacks + 12 };
	bool m_bPSNOnline;
};

#endif

// k_iSteamUtilsCallbacks + 13 is taken


//-----------------------------------------------------------------------------
// Big Picture gamepad text input has been closed
//-----------------------------------------------------------------------------
struct GamepadTextInputDismissed_t
{
	enum { k_iCallback = k_iSteamUtilsCallbacks + 14 };
	bool m_bSubmitted;										// true if user entered & accepted text (Call ISteamUtils::GetEnteredGamepadTextInput() for text), false if canceled input
	uint32 m_unSubmittedText;
};

// k_iSteamUtilsCallbacks + 15 is taken


// k_iClientUtilsCallbacks
struct CellIDChanged_t
{
	enum { k_iCallback = k_iClientUtilsCallbacks + 3 };

	CellID_t m_nCellID;
};

#pragma pack( pop )

class CUtlBuffer
#ifdef _S4N_
{
	int m_iPadding;
}
#endif
;

#endif // UTILSCOMMON_H
