#ifndef MBOXDRIVESPEEDTORQUE_H
#define MBOXDRIVESPEEDTORQUE_H
#pragma once

#include "Converter.h"

// Mailbox class
#include "Mailbox.h"

class MBoxDriveSpeedTorque : public Mailbox //, ExROutput<ExRDataStructureTypeUInt[2]>
{
private:
	struct MBoxOutStructureSpeedTorque
	{
		uint32_t SPEED_KRPM;
		uint32_t TORQUE_NEWTM;
	};

	MBoxOutStructureSpeedTorque dataFields;

public:
	// Overrides from Mailbox
	Payload Write() override;
	void Read(Payload &p) override;

	MBoxDriveSpeedTorque() = default;
	~MBoxDriveSpeedTorque() = default;
};
#endif