#ifndef MBOXBANDWIDTH_H
#define MBOXBANDWIDTH_H
#pragma once

// Mailbox class
#include "Mailbox.h"

class MBoxBandWidth : public Mailbox
{
private:
	uint8_t maxCurrent;
	uint8_t controlBandwidth;

public:
	MBoxBandWidth();
	~MBoxBandWidth() = default;

	struct DynamicBandwidthPayload
	{
		uint8_t MAX_CURRENT;	   //SET MAX CURRENT IN A (Leave at value of 0)
		uint8_t CONTROL_BANDWIDTH; // SET CONTROL BANDWIDTH (Leave at value of 20)
	};

	Payload Write();
	void Read(Payload &p);
	void Set(void *dynamicMBoxStruct);
};
#endif