#ifndef __EXR_DEFINITIONS_H__
#define __EXR_DEFINITIONS_H__
#pragma once

// systems includes

// See the ALL_CAN_COMMANDS.* document for all possible command types, and their fields

// SERIAL DEFINITIONS // ttyS5
#define EX_EXR_SERIAL_PORT "/dev/ttyS5"       // the serial port file location of the EXR
#define EX_EXR_SERIAL_PORT_DEBUG "/dev/ttyS5" // the debug serial port file location

#define EX_EXR_BAUDRATE 115200      // the baud/transfer rate of the EXR serial
#define EX_EXR_SERIAL_TMOUT_MS 2500 // the time-out rate in ms
#define EX_MSG_SIZE 15              // the serial msg size, which must always be 15 bytes in total

// Standard CRC Value
#define CRC_NULL_VALUE 0

// SERIAL MSG HEADER FIELDS
#define MSG_HF_1 'a'
#define MSG_HF_2 'b'
#define MSG_HF_3 'c'
#define MSG_HF_4 'd'

// EXR DEFINITIONS - Motherboard/Mainboard (Intel)
#define EX_MAINBOARD_STATUS_TYPE_SET 0x220      // serial address to set the feedback message
#define EX_MAINBOARD_STATUS_TYPE_RESPONSE 0x221 // serial address of the feedback message
//
#define EX_MAINBOARD_OUTPUTSETTINGS_TYPE_SET 0x200      // serial address to toggle the IO-expander ports of the EXR mainboard
#define EX_MAINBOARD_OUTPUTSETTINGS_TYPE_RESPONSE 0x201 // serial address to request various info about the mainboard (BAT Voltage, BAT Current, IO-expander info, etc..)

// EXR DEFINITIONS - MOTOR-LEFT - INFO GETTERS
#define EX_DRIVE_LEFT_SETTINGSTATUS_TYPE_RESPONSE 0x102 // serial address to request various info about the left motor of the EXR
#define EX_DRIVE_LEFT_SPD_TRQ_TYPE_RESPONSE 0x112       // serial address to request the actual speed and torque of the left motor
#define EX_DRIVE_LEFT_INPUT_V_C_TYPE_RESPONSE 0x122     // serial address to request the actual voltage and ref current of the left motor
#define EX_DRIVE_LEFT_MOSFETTEMP_TYPE_RESPONSE 0x132    // serial address to request the actual temperature of the mosfet sensor of the left motor
// EXR DEFINITIONS - MOTOR-LEFT - PARAMETER SETTERS
#define EX_DRIVE_LEFT_SETTINGS_TYPE_SET 0x100       // serial address to set the various settings for the left motor of the EXR, this is required to prepare the motor
#define EX_DRIVE_LEFT_MAX_ACCEL_JERK_TYPE_SET 0x120 // serial address to set the max acceleration and jerk of the left motor
#define EX_DRIVE_LEFT_BANDW_TYPE_SET 0x130          // serial address to set the bandwidth value of the left motor

// EXR DEFINITIONS - MOTOR-RIGHT - INFO GETTERS
#define EX_DRIVE_RIGHT_SETTINGSTATUS_TYPE_RESPONSE 0x103 // serial address to request various info about the left motor of the EXR
#define EX_DRIVE_RIGHT_SPD_TRQ_TYPE_RESPONSE 0x113       // serial address to request the actual speed and torque of the left motor
#define EX_DRIVE_RIGHT_INPUT_V_C_TYPE_RESPONSE 0x123     // serial address to request the actual voltage and ref current of the left motor
#define EX_DRIVE_RIGHT_MOSFETTEMP_TYPE_RESPONSE 0x133    // serial address to request the actual temperature of the mosfet sensor of the left motor
// EXR DEFINITIONS - MOTOR-RIGHT - PARAMETER SETTERS
#define EX_DRIVE_RIGHT_SETTINGS_TYPE_SET 0x101       // serial address to set the various settings for the left motor of the EXR, this is required to prepare the motor
#define EX_DRIVE_RIGHT_MAX_ACCEL_JERK_TYPE_SET 0x121 // serial address to set the max acceleration and jerk of the left motor
#define EX_DRIVE_RIGHT_BANDW_TYPE_SET 0x131          // serial address to set the bandwidth value of the left motor

// EXR DEFINITIONS - MOTOR DRIVES
#define EX_DRIVE_SPEEDREF_TYPE_SET 0x111 // serial address to set the speed to given value of the left motot
#endif                                   // end region of the include guard