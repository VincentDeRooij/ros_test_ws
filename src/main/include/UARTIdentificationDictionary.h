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
	// std::vector<std::shared_ptr<Mailbox>> vec;

	//In the map m you'll find the BITDATA that alligns with the Serial adress that's given.
	std::map<uint16_t, std::shared_ptr<Mailbox *>> m;

public:
	UARTIdentificationDictionary() = default;
	~UARTIdentificationDictionary() = default;

	void AddToMap(const uint16_t &sA, Mailbox &mBox);
};
#endif