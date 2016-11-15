//====== Copyright 1996-2013, Valve Corporation, All rights reserved. =======
//
// Purpose: interface to valve controller
//
//=============================================================================

#ifndef CONTROLLERCOMMON_H
#define CONTROLLERCOMMON_H
#ifdef _WIN32
#pragma once
#endif

#define STEAMCONTROLLER_INTERFACE_VERSION_001 "STEAMCONTROLLER_INTERFACE_VERSION"
#define STEAMCONTROLLER_INTERFACE_VERSION_002 "SteamController002"
#define STEAMCONTROLLER_INTERFACE_VERSION_003 "SteamController003"
#define STEAMCONTROLLER_INTERFACE_VERSION_004 "SteamController004"

#define MAX_STEAM_CONTROLLERS 16
#define STEAM_CONTROLLER_MAX_COUNT 16

#define STEAM_CONTROLLER_MAX_ANALOG_ACTIONS 16

#define STEAM_CONTROLLER_MAX_DIGITAL_ACTIONS 128

#define STEAM_CONTROLLER_MAX_ORIGINS 8

// When sending an option to a specific controller handle, you can send to all controllers via this command
#define STEAM_CONTROLLER_HANDLE_ALL_CONTROLLERS UINT64_MAX

#define STEAM_CONTROLLER_MIN_ANALOG_ACTION_DATA -1.0f
#define STEAM_CONTROLLER_MAX_ANALOG_ACTION_DATA 1.0f

enum ESteamControllerPad
{
	k_ESteamControllerPad_Left,
	k_ESteamControllerPad_Right
};

enum EControllerSource
{
	k_EControllerSource_None,
	k_EControllerSource_LeftTrackpad,
	k_EControllerSource_RightTrackpad,
	k_EControllerSource_Joystick,
	k_EControllerSource_ABXY,
	k_EControllerSource_Switch,
	k_EControllerSource_LeftTrigger,
	k_EControllerSource_RightTrigger,
	k_EControllerSource_Gyro,
	k_EControllerSource_Count
};

enum EControllerSourceMode
{
	k_EControllerSourceMode_None,
	k_EControllerSourceMode_Dpad,
	k_EControllerSourceMode_Buttons,
	k_EControllerSourceMode_FourButtons,
	k_EControllerSourceMode_AbsoluteMouse,
	k_EControllerSourceMode_RelativeMouse,
	k_EControllerSourceMode_JoystickMove,
	k_EControllerSourceMode_JoystickCamera,
	k_EControllerSourceMode_ScrollWheel,
	k_EControllerSourceMode_Trigger,
	k_EControllerSourceMode_TouchMenu,
	k_EControllerSourceMode_MouseJoystick,
	k_EControllerSourceMode_MouseRegion,
	k_EControllerSourceMode_RadialMenu,
	k_EControllerSourceMode_Switches
};

enum EControllerActionOrigin
{
	k_EControllerActionOrigin_None,
	k_EControllerActionOrigin_A,
	k_EControllerActionOrigin_B,
	k_EControllerActionOrigin_X,
	k_EControllerActionOrigin_Y,
	k_EControllerActionOrigin_LeftBumper,
	k_EControllerActionOrigin_RightBumper,
	k_EControllerActionOrigin_LeftGrip,
	k_EControllerActionOrigin_RightGrip,
	k_EControllerActionOrigin_Start,
	k_EControllerActionOrigin_Back,
	k_EControllerActionOrigin_LeftPad_Touch,
	k_EControllerActionOrigin_LeftPad_Swipe,
	k_EControllerActionOrigin_LeftPad_Click,
	k_EControllerActionOrigin_LeftPad_DPadNorth,
	k_EControllerActionOrigin_LeftPad_DPadSouth,
	k_EControllerActionOrigin_LeftPad_DPadWest,
	k_EControllerActionOrigin_LeftPad_DPadEast,
	k_EControllerActionOrigin_RightPad_Touch,
	k_EControllerActionOrigin_RightPad_Swipe,
	k_EControllerActionOrigin_RightPad_Click,
	k_EControllerActionOrigin_RightPad_DPadNorth,
	k_EControllerActionOrigin_RightPad_DPadSouth,
	k_EControllerActionOrigin_RightPad_DPadWest,
	k_EControllerActionOrigin_RightPad_DPadEast,
	k_EControllerActionOrigin_LeftTrigger_Pull,
	k_EControllerActionOrigin_LeftTrigger_Click,
	k_EControllerActionOrigin_RightTrigger_Pull,
	k_EControllerActionOrigin_RightTrigger_Click,
	k_EControllerActionOrigin_LeftStick_Move,
	k_EControllerActionOrigin_LeftStick_Click,
	k_EControllerActionOrigin_LeftStick_DPadNorth,
	k_EControllerActionOrigin_LeftStick_DPadSouth,
	k_EControllerActionOrigin_LeftStick_DPadWest,
	k_EControllerActionOrigin_LeftStick_DPadEast,
	k_EControllerActionOrigin_Gyro_Move,
	k_EControllerActionOrigin_Gyro_Pitch,
	k_EControllerActionOrigin_Gyro_Yaw,
	k_EControllerActionOrigin_Gyro_Roll,
	
	k_EControllerActionOrigin_Count
};

// ControllerHandle_t is used to refer to a specific controller.
// This handle will consistently identify a controller, even if it is disconnected and re-connected
typedef uint64 ControllerHandle_t;


// These handles are used to refer to a specific in-game action or action set
// All action handles should be queried during initialization for performance reasons
typedef uint64 ControllerActionSetHandle_t;
typedef uint64 ControllerDigitalActionHandle_t;
typedef uint64 ControllerAnalogActionHandle_t;

#pragma pack( push, 1 )

// Safe to add new bitfields at the end of this list for new buttons/actions, 
// but never re-use or re-number an existing flag as old client code will be 
// confused.
#define STEAM_RIGHT_TRIGGER_MASK            0x0000000000000001l
#define STEAM_LEFT_TRIGGER_MASK             0x0000000000000002l
#define STEAM_RIGHT_BUMPER_MASK             0x0000000000000004l
#define STEAM_LEFT_BUMPER_MASK              0x0000000000000008l
#define STEAM_BUTTON_0_MASK                 0x0000000000000010l
#define STEAM_BUTTON_1_MASK                 0x0000000000000020l
#define STEAM_BUTTON_2_MASK                 0x0000000000000040l
#define STEAM_BUTTON_3_MASK                 0x0000000000000080l
#define STEAM_TOUCH_0_MASK                  0x0000000000000100l
#define STEAM_TOUCH_1_MASK                  0x0000000000000200l
#define STEAM_TOUCH_2_MASK                  0x0000000000000400l
#define STEAM_TOUCH_3_MASK                  0x0000000000000800l
#define STEAM_BUTTON_MENU_MASK              0x0000000000001000l
#define STEAM_BUTTON_STEAM_MASK             0x0000000000002000l
#define STEAM_BUTTON_ESCAPE_MASK            0x0000000000004000l
#define STEAM_BUTTON_BACK_LEFT_MASK         0x0000000000008000l
#define STEAM_BUTTON_BACK_RIGHT_MASK        0x0000000000010000l
#define STEAM_BUTTON_LEFTPAD_CLICKED_MASK   0x0000000000020000l
#define STEAM_BUTTON_RIGHTPAD_CLICKED_MASK  0x0000000000040000l
#define STEAM_LEFTPAD_FINGERDOWN_MASK       0x0000000000080000l
#define STEAM_RIGHTPAD_FINGERDOWN_MASK      0x0000000000100000l
#define STEAM_JOYSTICK_BUTTON_MASK			0x0400000


// Only add fields to the end of this struct, or if you need to change it in a larger
// way add a new message id and new struct completely so as to not break old clients.

struct SteamControllerState001_t
{
	// If packet num matches that on your prior call, then the controller state hasn't been changed since 
	// your last call and there is no need to process it
	uint32 unPacketNum;
	
	// bit flags for each of the buttons
	uint64 ulButtons;
	
	// Left pad coordinates
	short sLeftPadX;
	short sLeftPadY;
	
	// Right pad coordinates
	short sRightPadX;
	short sRightPadY;
	
};

struct ControllerAnalogActionData_t
{
	// Type of data coming from this action, this will match what got specified in the action set
	EControllerSourceMode eMode;
	
	// The current state of this action; will be delta updates for mouse actions
	float x, y;
	
	// Whether or not this action is currently available to be bound in the active action set
	bool bActive;
};

struct ControllerDigitalActionData_t
{
	// The current state of this action; will be true if currently pressed
	bool bState;
	
	// Whether or not this action is currently available to be bound in the active action set
	bool bActive;
};

struct ControllerMotionData_t
{
	// Sensor-fused absolute rotation; will drift in heading
	float rotQuatX;
	float rotQuatY;
	float rotQuatZ;
	float rotQuatW;
	
	// Positional acceleration
	float posAccelX;
	float posAccelY;
	float posAccelZ;

	// Angular velocity
	float rotVelX;
	float rotVelY;
	float rotVelZ;
};

#define SteamControllerState_t SteamControllerState001_t

#pragma pack( pop )


//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
/*
struct ControllerCallback_t
{
	enum { k_iCallback = k_iSteamControllerCallbacks + 1 };
	
};
*/

#endif
