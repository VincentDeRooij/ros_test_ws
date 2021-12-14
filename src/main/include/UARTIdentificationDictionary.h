#ifndef UARTIDENTIFICATIONDICTONAIRY_H
#define UARTIDENTIFICATIONDICTONAIRY_H
#pragma once

// system includes
#include <stdint.h>
#include <memory>
#include <map>
#include <vector>

// created includes
//#include "ExRDefinitions.h"
#include "Payload.h"
#include "Mailbox.h"

// Mailboxes
#include "MBoxDriveSettings.h"

//A class with all the UART messages defined, ready to sent when you call them.
class UARTIdentificationDictionary
{
private:
	struct UARTIDDictionaryEntry
	{
		uint16_t address;
		Mailbox *box;
		bool isWriteType; // if type is of write = 1, if not = 0
	};

	//In the map m you'll find the BITDATA that alligns with the Serial adress that's given.
	std::vector<UARTIDDictionaryEntry> m;

public:
	UARTIdentificationDictionary() = default;
	~UARTIdentificationDictionary() = default;

	void AddToMap(const uint16_t &sA, Mailbox *mBox, const bool &type);
	Mailbox *GetMailboxBySerial(const uint16_t &sId);
};
#endif