#ifndef MBOXMAINBOARDINFO_H
#define MBOXMAINBOARDINFO_H

// Mailbox class
#include "Mailbox.h"

#pragma once

class MBoxMainboardIOInfo : public Mailbox
{
private:
	bool ioExpanderP7Motor = false;
	bool ioExpanderP1Light2 = false;
	bool ioExpanderP0Light1 = false;

	struct MBoxOutStructureMBIOInfo
	{
		uint16_t BAT_VOLTAGE;			//BATTERY VOLTAGE 0 to 43200 mV
		uint16_t BAT_CHARGE_PERCENTAGE; //BATTERY PERCENTAGE 0 to 100%
		int16_t BAT_AVR_CURRENT;		// BATTERY CURRENT -32k to 32k mA
		uint8_t MAINBOARD_INFO;			// BMS STATUS. 00 to 11 = 00 NORMAL, 01 WARNING, 10 TEMPORARY TRIPPED, 11 PERMANENTLY TRIPPED
		uint8_t IO_EXPANDER_STATUS;		//
	};
	MBoxOutStructureMBIOInfo dataFields;

public:
	struct DynamicMainboardIOInfoPayload
	{
		bool IO_Expander_P0_7_MOTOR; // PO = GPIO port - _7 = Bit - Type of hardware
		bool IO_Expander_P0_1_LIGHT_2;
		bool IO_Expander_P0_0_LIGHT_1;
	};

	MBoxMainboardIOInfo() = default;
	~MBoxMainboardIOInfo() = default;

	// inherit the method from mailbox, allowing our own method implementations
	virtual void Read(Payload &p);
	virtual Payload Write();
	void Set(void *dynamicMBoxStruct);
};
#endif