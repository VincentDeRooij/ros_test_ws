#ifndef MBOXDRIVESPEEDTORQUE_H
#define MBOXDRIVESPEEDTORQUE_H
#pragma once

#include "Converter.h"

// Mailbox class
#include "Mailbox.h"

class MBoxDriveSpeedTorque : public Mailbox //, ExROutput<ExRDataStructureTypeUInt[2]>
{
private:
	int32_t maxAccelKRPM; // uint32_t for the fixed type conversion
	int32_t maxJerkKRPM;  // uint32_t for the fixed type conversion

	/**
 * @brief Output structure for this MBOX
 * 
 */
	struct MBoxOutStructureSpeedTorque
	{
		uint32_t SPEED_KRPM;   //MOTOR SPEED IN KRPM
		uint32_t TORQUE_NEWTM; //MOTOR TORQUE IN NM
	};

	MBoxOutStructureSpeedTorque dataFields;

public:
	struct DynamicAccelJerkPayload
	{
		int32_t MAX_ACCEL_KRPM; // KRPM = Kilo RPM 0 to 120
		int32_t MAX_JERK_KRPM;	// SET MAX JERK IN M/S^3 0 to 750
	};

	MBoxDriveSpeedTorque() = default;
	~MBoxDriveSpeedTorque() = default;

	// inherit the method from mailbox, allowing our own method implementations
	void Read(Payload &p) override;
	void Set(void *dynamicMBoxStruct) override;
	Payload Write() override;
};
#endif