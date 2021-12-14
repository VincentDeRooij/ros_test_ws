#ifndef SERIALREADER_H
#define SERIALREADER_H
#pragma once

#include "SerialIOController.h"

class SerialReader : public SerialIOController
{
private:
	void SerialReadMsg();
	void AddToMsgQueue(const ExRMessage &msg, const bool &isPrioType);

public:
	SerialReader() = default;
	~SerialReader() = default;
	void StartReaderProcess();

	// SerialWriter implementation from the SerialIOController pure virtual

	/**
 * @brief 
 * 
 */
private:
	ExRMessage msg;

	void processItem(std::queue<ExRMessage> &queue)
	{
		// RUN ROS PUB
		if (queue.empty() == false)
		{
			this->msg = queue.front();
			// insert UART Dictionary

			queue.pop(); // remove item from the list
		}
	}
};
#endif