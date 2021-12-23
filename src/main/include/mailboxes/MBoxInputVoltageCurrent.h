#ifndef MBOXINPUTVOLTAGECURRENT_H
#define MBOXINPUTVOLTAGECURRENT_H
#pragma once

// Mailbox class
#include "Mailbox.h"

class MBoxInputVoltageCurrent : public Mailbox //, ExROutput<ExRDataStructureTypeUInt[2]>
{
private:
	/**
 * @brief Output structure for this MBOX
 * 
 */
	struct MBoxOutStructureVCInfo
	{
		uint32_t VDCBUS_KV; //VOLTAGE IN kV
		uint32_t IQREF_A;	//CURENT IN A
	};

	MBoxOutStructureVCInfo dataFields;

public:
	MBoxInputVoltageCurrent() = default;
	~MBoxInputVoltageCurrent() = default;

	// inherit the method from mailbox, allowing our own method implementations
	void Read(Payload &p) override;
	void Set(void *dynamicMBoxStruct) override;
	Payload Write() override;
};
#endif