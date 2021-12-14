#ifndef SERIALWRITER_H
#define SERIALWRITER_H
#pragma once

#include "SerialIOController.h"

class SerialWriter : public SerialIOController
{
public:
	SerialWriter() = default;
	~SerialWriter() = default;
	void AddToMsgQueue(const uint16_t &serialAddress, const Payload &payload, const bool &isPriorityMsg);

	// SerialWriter implementation from the SerialIOController pure virtual
private:
	void processItem(std::queue<ExRMessage> &queue)
	{
		// check if the given queue is empty
		if (queue.empty() == false) // loops while the message queue contains more messages
		{
			// opens the serial comm on the specified serial port
			if (IsSerialPortAvailable())
			{
				size_t size = this->uartCommunicator.write((uint8_t *)&queue.front(), EX_MSG_SIZE);
				std::cout << "MSG_SIZE_WRITTEN: " << size << std::endl;

				if (size == EX_MSG_SIZE) // if the messageLength is not equal to the required size
				{
					// LOG RESULTS - QUEUE ITEM PROCESSED
				}
				else
				{
					// LOG RESULTS - INVALID ENTRY / DO SOMETHING?
				}
				// removes the entry from the queue
				queue.pop();
			}
			else
			{
				std::cout << "WRITER: SERIAL_PORT_UNAVAILABLE/CLOSED" << std::endl;
				this->uartCommunicator.open();
			}
		}
		std::cout << std::endl;
	}
};
#endif