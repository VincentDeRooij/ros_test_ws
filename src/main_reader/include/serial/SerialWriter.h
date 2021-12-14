#ifndef SERIALWRITER_H
#define SERIALWRITER_H
#pragma once

#include "SerialIOController.h"

class SerialWriter : public SerialIOController
{
private:
	void SerialWriteMsg();

public:
	SerialWriter() = default;
	~SerialWriter() = default;
	void AddToMsgQueue(const uint16_t &serialAddress, const Payload &payload, const bool &isPriorityMsg);

	// SerialWriter implementation from the SerialIOController pure virtual
private:
	void processItem(std::queue<ExRMessage> &queue)
	{
		this->uartCommunicator.open();
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
				std::cout << "SERIAL_PORT_UNAVAILABLE" << std::endl;
			}
			std::cout << "SERIAL_MSG_WRITTEN CLOSING PORT";
			// closes port after processing the message
			this->uartCommunicator.close();
		}
		std::cout << std::endl;
	}
};
#endif