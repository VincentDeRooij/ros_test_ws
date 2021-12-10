#ifndef MBOXINPUTVOLTAGECURRENT_H
#define MBOXINPUTVOLTAGECURRENT_H
#pragma once

// Mailbox class
#include "Mailbox.h"

// Mailbox Read Interface
#include "IMBoxRead.h"

class MBoxInputVoltageCurrent : public Mailbox, public IMBoxRead //, ExROutput<ExRDataStructureTypeUInt[2]>
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
	virtual void Read(Payload &p) override;

	MBoxInputVoltageCurrent() = default;
	~MBoxInputVoltageCurrent() = default;
};
#endif