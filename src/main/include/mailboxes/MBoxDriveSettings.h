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
	struct DynamicDriveSettingsPayload
	{
		uint8_t ENABLE_OFFSET_CALC; //OFFSET RECALCULATION ENABLED
		uint8_t ENABLE_FORCE_ANGLE; //FORCE ANGLE ENABLED
		uint8_t ENABLE_RS_RECALC;	//ENABLE RS RECALCULATION
		uint8_t ENABLE_USER_PARAM;	//ENABLE USER PARAMETERS
		uint8_t DRV_IDENTIFY;		//IDENTIFY MOTOR/ DO NOT IDENTIFY MOTOR
		uint8_t DRV_ENABLE;			// CONTROL ENABLE/ DISABLE
	};

	MBoxDriveSettings() = default;
	~MBoxDriveSettings() = default;

	// inherit the method from mailbox, allowing our own method implementations
	void Read(Payload &p) override;
	Payload Write() override;
	void Set(void *dynamicMBoxStruct);
};
#endif