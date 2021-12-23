#ifndef MBOXBANDWIDTH_H
#define MBOXBANDWIDTH_H
#pragma once

// Mailbox class
#include "Mailbox.h"
#include "IValueLimitException.h"

class MBoxBandWidth : public Mailbox, public IValueLimitException
{
private:
	// attributes
	uint8_t maxCurrent;
	uint8_t controlBandwidth;

public:
	// dynamic payload struct
	struct DynamicBandwidthPayload
	{
		uint8_t MAX_CURRENT;	   //SET MAX CURRENT IN A (Leave at value of 0)
		uint8_t CONTROL_BANDWIDTH; // SET CONTROL BANDWIDTH (Leave at value of 20)
	};

	// constructors
	MBoxBandWidth() = default;
	~MBoxBandWidth() = default;

	const char *FailSafeSet(void *payloadType) throw();

	// inherit the method from mailbox, allowing our own method implementations
	void Read(Payload &p) override;
	void Set(void *dynamicMBoxStruct) override;
	Payload Write() override;
};
#endif