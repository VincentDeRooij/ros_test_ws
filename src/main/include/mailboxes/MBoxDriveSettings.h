#ifndef MBOXDRIVESETTINGS_H
#define MBOXDRIVESETTINGS_H

// Mailbox class
#include "Mailbox.h"

#pragma once

class MBoxDriveSettings : public Mailbox
{
private:
	uint8_t enableOffsetCalc;
	uint8_t enableForceAngle;
	uint8_t enableRSRecalc;
	uint8_t enableUserParam;
	uint8_t drvIdentity;
	uint8_t drvEnable;

	/**
 * @brief Output structure for this MBOX
 * 
 */
	struct MBoxOutStructureDriveSettings
	{
		uint32_t TRAJECT_SPEED; //TRAJECTORY MOTORSPEED IN KRPM 0 to 120 IQ24
		uint8_t FIRMWARE_VER;	//FIRMWARE VERSION NUMBER
		uint8_t AMPERE_RATING;
		uint8_t INFO_STATES;
		uint8_t ENGINE_STATE_TOGGLES;
	};

	MBoxOutStructureDriveSettings dataFields;

public:
	// dynamic payload struct
	struct DynamicDriveSettingsPayload
	{
		bool ENABLE_OFFSET_CALC; //OFFSET RECALCULATION ENABLED
		bool ENABLE_FORCE_ANGLE; //FORCE ANGLE ENABLED
		bool ENABLE_RS_RECALC;	 //ENABLE RS RECALCULATION
		bool ENABLE_USER_PARAM;	 //ENABLE USER PARAMETERS
		bool DRV_IDENTIFY;		 //IDENTIFY MOTOR/ DO NOT IDENTIFY MOTOR
		bool DRV_ENABLE;		 // CONTROL ENABLE/ DISABLE
	};

	MBoxDriveSettings() = default;
	~MBoxDriveSettings() = default;

	// inherit the method from mailbox, allowing our own method implementations
	void Read(Payload &p) override;
	void Set(void *dynamicMBoxStruct) override;
	Payload Write() override;
};
#endif