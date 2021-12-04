#ifndef __SERIALIO_H__
#define __SERIALIO_H__
#pragma once

// system includes
#include <serial/serial.h>
#include <queue>
#include <iostream> // console include, std::cout, std::endl, etc...

// OS Specific sleep
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

// created includes
//#include "ExRDefinitions.h"
#include "ExRSerialDefinitions.h"
#include "ExRMsgStructures.h"
#include "Payload.h"

class SerialIOController // make this a singleton pattern, this class must be instantiated only once
{
public:
    SerialIOController()
    {
        initSerialController(); // initialize the SerialController
    }
    virtual ~SerialIOController() = default;

    // Public methods
    void AddToMsgQueue(const uint16_t &serialAddress, const Payload &payload, const bool &isPriorityMsg);
    void ProcessSerialMessageQueues();
    bool IsSerialPortAvailable();

protected:
    serial::Serial uartCommunicator;
    std::queue<ExRMessage> std_queue;  // std_queue
    std::queue<ExRMessage> prio_queue; // prio_queue

    // protected methods
    virtual void processItem(std::queue<ExRMessage> &queue) = 0;
    bool IsMsgPrioType(const uint16_t &address); // WHAT TYPE HERE? OR SOMETHING ELSE

private:
    void processQueue(std::queue<ExRMessage> &queue);
    void initSerialController();
};

#endif // __SERIALIO_H__