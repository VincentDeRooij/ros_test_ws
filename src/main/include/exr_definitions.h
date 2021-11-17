#ifndef __EXR_DEFINITIONS_H__
#define __EXR_DEFINITIONS_H__

// See the ALL_CAN_COMMANDS.* document for all possible command types, and their fields

// PAYLOAD MSG SIZE
#define PAYLOAD_MSG_SIZE sizeof(uint8_t)*8 // max size of 8 bytes / 8*uint8

// SERIAL MSG HEADER FIELDS
#define MSG_HF_1 'a'
#define MSG_HF_2 'b'
#define MSG_HF_3 'c'
#define MSG_HF_4 'd'

// SERIAL DEFINITIONS
#define EX_EXR_SERIAL_PORT "/dev/ttyS5"                        // the serial port file location of the EXR 
#define EX_EXR_BAUDRATE 115200                          // the baud/transfer rate of the EXR serial
#define EX_MSG_SIZE 15                                  // the serial msg size, which must always be 15 bytes in total

// EXR DEFINITIONS - Motherboard/Mainboard (Intel)
#define EX_MOTHER_STATUS_SERIAL_ID_REQ_TYPE 0x220       // serial address to get the feedback message
#define EX_MOTHER_STATUS_SERIAL_ID_REC_TYPE 0x221       // serial address of the feedback message
// 
#define EX_MOTHER_PORT_OUTPUT_SET_TYPE 0x200            // serial address to toggle the IO-expander ports of the EXR mainboard 
#define EX_MOTHER_INFO_REQ_TYPE 0x201                   // serial address to request various info about the mainboard (BAT Voltage, BAT Current, IO-expander info, etc..)

// EXR DEFINITIONS - MOTOR-LEFT - INFO GETTERS
#define EX_MOTOR_LEFT_DRIVE_STATUS_REQ_TYPE 0x102       // serial address to request various info about the left motor of the EXR
#define EX_MOTOR_LEFT_SPEED_TORQUE_REQ_TYPE 0x112       // serial address to request the actual speed and torque of the left motor
#define EX_MOTOR_LEFT_VOLT_CURRENT_REQ_TYPE 0x122       // serial address to request the actual voltage and ref current of the left motor
#define EX_MOTOR_LEFT_MOSFET_TEMP_REQ_TYPE 0x132        // serial address to request the actual temperature of the mosfet sensor of the left motor     
// EXR DEFINITIONS - MOTOR-LEFT - PARAMETER SETTERS
#define EX_MOTOR_LEFT_DRIVE_SETTINGS_SET_TYPE 0x100     // serial address to set the various settings for the left motor of the EXR, this is required to prepare the motor
#define EX_MOTOR_LEFT_SPEEDREF_SET_TYPE 0x110           // serial address to set the speed to given value of the left motot 
#define EX_MOTOR_LEFT_MAX_ACCEL_JERK_SET_TYPE 0x120     // serial address to set the max acceleration and jerk of the left motor  
#define EX_MOTOR_LEFT_BW_SET_TYPE 0x130                 // serial address to set the bandwidth value of the left motor   

// EXR DEFINITIONS - MOTOR-RIGHT - INFO GETTERS
#define EX_MOTOR_RIGHT_DRIVE_STATUS_REQ_TYPE 0x103      // serial address to request various info about the left motor of the EXR
#define EX_MOTOR_RIGHT_SPEED_TORQUE_REQ_TYPE 0x113      // serial address to request the actual speed and torque of the left motor
#define EX_MOTOR_RIGHT_VOLT_CURRENT_REQ_TYPE 0x123      // serial address to request the actual voltage and ref current of the left motor
#define EX_MOTOR_RIGHT_MOSFET_TEMP_REQ_TYPE 0x133       // serial address to request the actual temperature of the mosfet sensor of the left motor     
// EXR DEFINITIONS - MOTOR-RIGHT - PARAMETER SETTERS
#define EX_MOTOR_RIGHT_DRIVE_SETTINGS_SET_TYPE 0x101    // serial address to set the various settings for the left motor of the EXR, this is required to prepare the motor
#define EX_MOTOR_RIGHT_SPEEDREF_SET_TYPE 0x111          // serial address to set the speed to given value of the left motot 
#define EX_MOTOR_RIGHT_MAX_ACCEL_JERK_SET_TYPE 0x121    // serial address to set the max acceleration and jerk of the left motor  
#define EX_MOTOR_RIGHT_BANDWIDTH_SET_TYPE 0x131         // serial address to set the bandwidth value of the left motor   

#endif // end region of the include guard