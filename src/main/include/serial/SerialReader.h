#ifndef SERIALREADER_H
#define SERIALREADER_H
#pragma once

#include "SerialIOController.h"
#include "UARTIdentificationDictionary.h"
#include "MBoxMainboardIOInfo.h"

class SerialReader : public SerialIOController
{
private:
	void SerialReadMsg();
	void AddToMsgQueue(const ExRMessage &msg, const bool &isPrioType);

public:
	SerialReader(UARTIdentificationDictionary dict);
	~SerialReader() = default;
	void StartReaderProcess();

	// SerialWriter implementation from the SerialIOController pure virtual

	/**
 * @brief 
 * 
 */
private:
	ExRMessage msg;
	UARTIdentificationDictionary processDictionary;

	void processItem(std::queue<ExRMessage> &queue)
	{
		// RUN ROS PUB
		if (queue.empty() == false)
		{
			this->msg = queue.front();
			// insert UART DictionarySerialSerial
			Mailbox *mb = this->processDictionary.GetMailboxBySerial(this->msg.serialId);

			MBoxMainboardIOInfo info(false, false, false);

			Payload pl(msg.payload[0], msg.payload[1], msg.payload[2], msg.payload[3], msg.payload[4], msg.payload[5], msg.payload[6], msg.payload[7]);

			mb->Read(pl);

			queue.pop(); // remove item from the list
		}
	}
};
#endif