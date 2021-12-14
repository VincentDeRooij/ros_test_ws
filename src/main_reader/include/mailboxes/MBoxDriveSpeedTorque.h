#ifndef MBOXDRIVESPEEDTORQUE_H
#define MBOXDRIVESPEEDTORQUE_H
#pragma once

#include "Converter.h"

// Mailbox class
#include "Mailbox.h"

// Mailbox Read Interface
#include "IMBoxRead.h"

class MBoxDriveSpeedTorque : public Mailbox, public IMBoxRead //, ExROutput<ExRDataStructureTypeUInt[2]>
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
	virtual void Read(Payload &p) override;

	MBoxDriveSpeedTorque() = default;
	~MBoxDriveSpeedTorque() = default;
};
#endif