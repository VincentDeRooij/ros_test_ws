#ifndef MBOXSPEEDREF_H
#define MBOXSPEEDREF_H
#pragma once

// Mailbox class
#include "Mailbox.h"

// Converter
#include "Converter.h"

class MBoxSpeedRef : public Mailbox
{
private:
	int8_t rightMotorDrive; //SPEEDREF LEFT USING IQ24 VALUE -4 to +4
	int8_t leftMotorDrive;	//SPEEDREF RIGHT USING IQ24 VALUE -4 to +4

public:
	struct DynamicSpeedRefPayload
	{
		int8_t RIGHT_MOTOR_DRIVE; // MAX ALLOWED RANGE -4 <> 4
		int8_t LEFT_MOTOR_DRIVE;  // MAX ALLOWED RANGE -4 <> 4
	};

	MBoxSpeedRef() = default;
	~MBoxSpeedRef() = default;

	// inherit the method from mailbox, allowing our own method implementations
	void Read(Payload &p) override;
	void Set(void *dynamicMBoxStruct) override;
	Payload Write() override;
};
#endif