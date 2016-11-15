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

#ifndef ELaunchOptionType_H
#define ELaunchOptionType_H
#ifdef _WIN32
#pragma once
#endif


//-----------------------------------------------------------------------------
// Purpose: codes for well defined launch options
//-----------------------------------------------------------------------------
enum ELaunchOptionType
{
	k_ELaunchOptionType_None		= 0,	// unknown what launch option does
	k_ELaunchOptionType_Default		= 1,	// runs the game, app, whatever in default mode
	k_ELaunchOptionType_SafeMode	= 2,	// runs the game in safe mode
	k_ELaunchOptionType_Multiplayer = 3,	// runs the game in multiplayer mode
	k_ELaunchOptionType_Config		= 4,	// runs config tool for this game
	k_ELaunchOptionType_OpenVR		= 5,	// runs game in VR mode using OpenVR
	k_ELaunchOptionType_Server		= 6,	// runs dedicated server for this game
	k_ELaunchOptionType_Editor		= 7,	// runs game editor
	k_ELaunchOptionType_Manual		= 8,	// shows game manual
	k_ELaunchOptionType_Benchmark	= 9,	// runs game benchmark
	k_ELaunchOptionType_Option1		= 10,	// generic run option, uses description field for game name
	k_ELaunchOptionType_Option2		= 11,	// generic run option, uses description field for game name
	k_ELaunchOptionType_Option3     = 12,	// generic run option, uses description field for game name
	k_ELaunchOptionType_OculusVR	= 13,	// runs game in VR mode using the Oculus SDK 
	k_ELaunchOptionType_OpenVROverlay = 14,	// runs an OpenVR dashboard overlay
	k_ELaunchOptionType_OSVR		= 15,	// runs game in VR mode using the OSVR SDK

	
	k_ELaunchOptionType_Dialog 		= 1000, // show launch options dialog
};


#endif // ELaunchOptionType_H
