#ifndef MBOXINPUTVOLTAGECURRENT_H
#define MBOXINPUTVOLTAGECURRENT_H
#pragma once

// Mailbox class
#include "Mailbox.h"


class MBoxInputVoltageCurrent : public Mailbox //, ExROutput<ExRDataStructureTypeUInt[2]>
{
private:
	struct MBoxOutStructureVCInfo
	{
		uint32_t VDCBUS_KV; //VOLTAGE IN kV
		uint32_t IQREF_A; //CURENT IN A
	};

	MBoxOutStructureVCInfo dataFields;

public:
	// Overrides from Mailbox
	Payload Write() override;
	void Read(Payload &p) override;
	void Set(void *structure);

	MBoxInputVoltageCurrent() = default;
	~MBoxInputVoltageCurrent() = default;
};
#endif