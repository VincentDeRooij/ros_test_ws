#ifndef MBOXMAINBOARDINFO_H
#define MBOXMAINBOARDINFO_H

// Mailbox class
#include "Mailbox.h"

// Mailbox Read Interface
#include "IMBoxRead.h"
// Mailbox Write Interface
#include "IMBoxWrite.h"

#pragma once

//template <typename OutType>
class MBoxMainboardInfo : public Mailbox, public IMBoxRead, public IMBoxWrite //ExROutput<ExRDataStructureTypeUInt>
{
private:
	struct MBoxOutStructureMBInfo
	{
		uint16_t BAT_VOLTAGE;
		uint16_t BAT_CHARGE_PERCENTAGE;
		int16_t BAT_AVR_CURRENT;
		uint8_t MAINBOARD_INFO;
		uint8_t IO_EXPANDER_STATUS;
	};

	MBoxOutStructureMBInfo dataFields;

	bool lightIOPortOneIsEnabled = false;
	bool lightIOPortTwoIsEnabled = false;
	bool engineIOPortIsEnabled = false;

public:
	MBoxMainboardInfo(const bool &lightIOPortOne, const bool &lightIOPortTwo, const bool &engineIOPort);
	~MBoxMainboardInfo() = default;

	// inherit the method from mailbox, allowing our own method implementations
	virtual void Read(Payload &p) override;
	virtual Payload Write() override;
};
#endif