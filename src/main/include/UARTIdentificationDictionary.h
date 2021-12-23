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

// class UARTIDDictionaryEntry
// {
// public:
// 	UARTIDDictionaryEntry() = default;
// 	~UARTIDDictionaryEntry() = default;

// private:
// 	uint16_t address;
// 	Mailbox &box;
// 	bool isWriteType;
// };

//A class with all the UART messages defined, ready to sent when you call them.
class UARTIdentificationDictionary
{
private:
	struct UARTIDDictionaryEntry
	{
		uint16_t address;
		Mailbox *box;
		bool isWriteType;
	};

	//In the map m you'll find the BITDATA that alligns with the Serial adress that's given.
	std::vector<UARTIDDictionaryEntry> m;

public:
	UARTIdentificationDictionary() = default;
	~UARTIdentificationDictionary() = default;

	void AddToMap(const uint16_t &sA, Mailbox &mBox);
	Mailbox &GetMailboxBySerial(const uint16_t &sId);
};
#endif