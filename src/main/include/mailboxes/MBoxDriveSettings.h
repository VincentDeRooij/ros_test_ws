#ifndef MBOXDRIVESETTINGS_H
#define MBOXDRIVESETTINGS_H

// Mailbox class
#include "Mailbox.h"

// Mailbox Read Interface
#include "IMBoxRead.h"
// Mailbox Write Interface
#include "IMBoxWrite.h"

#pragma once

class MBoxDriveSettings : public Mailbox
{
private:
	struct MBoxOutStructureDriveSettings
	{
		uint32_t TRAJECT_SPEED;
		uint8_t FIRMWARE_VER;
		uint8_t AMPERE_RATING;
		uint8_t INFO_STATES;
		uint8_t ENGINE_STATE_TOGGLES;
	};

	MBoxOutStructureDriveSettings dataFields;

	bool engineIsEnabled = false;

public:
	MBoxDriveSettings(const bool &engineEnabled);
	~MBoxDriveSettings();

	// inherit the method from mailbox, allowing our own method implementations
	void Read(Payload &p) override;
	Payload Write() override;
};
#endif