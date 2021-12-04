#ifndef SERIALREADER_H
#define SERIALREADER_H
#pragma once

#include "SerialIOController.h"

class SerialReader : public SerialIOController
{
private:
	void SerialReadMsg();

public:
	SerialReader();
	~SerialReader() = default;
	void AddToMsgQueue(const ExRMessage &msg, const bool &isPrioType);

	// SerialWriter implementation from the SerialIOController pure virtual

	/**
 * @brief 
 * 
 */

private:
	void processItem(std::queue<ExRMessage> &queue)
	{
		// RUN ROS PUB
		if (queue.empty() == false)
		{

			/* code */

			queue.pop(); // remove item from the list
		}
	}
};
#endif