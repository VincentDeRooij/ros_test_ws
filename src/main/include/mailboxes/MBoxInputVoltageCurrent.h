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
		uint32_t VDCBUS_KV;
		uint32_t IQREF_A;
	};

	MBoxOutStructureVCInfo dataFields;

public:
	// Overrides from Mailbox
	Payload Write() override;
	void Read(Payload &p) override;

	MBoxInputVoltageCurrent() = default;
	~MBoxInputVoltageCurrent() = default;
};
#endif