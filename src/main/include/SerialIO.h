#ifndef __SERIALIO_H__
#define __SERIALIO_H__
#pragma once

// system includes
#include <serial/serial.h>
#include <queue>

// created includes
#include "ExRDefinitions.h"

class SerialIO // make this a singleton pattern, this class must be instantiated only once
{
public:
    SerialIO();
    SerialIO(SerialIO &&) = default;
    SerialIO(const SerialIO &) = default;
    SerialIO &operator=(SerialIO &&) = default;
    SerialIO &operator=(const SerialIO &) = default;
    ~SerialIO() = default;

    // Public methods
    void SerialMsgAdd(const uint16_t &serialAddress, const Payload &payload, const bool &isPriorityMsg);
    void ProcessSerialMessageQueues();
    bool isSerialPortAvailable();

private:
    serial::Serial uartCommunicator;
    std::queue<ExRMessage> std_queue;  // std_queue
    std::queue<ExRMessage> prio_queue; // prio_queue

    // private methods
    void serialRead();
    bool validateHeaders(ExRMessage &receivedMsg);
    void processQueue(std::queue<ExRMessage> &queue);
    void processItem(std::queue<ExRMessage> &queue);
};

#endif // __SERIALIO_H__