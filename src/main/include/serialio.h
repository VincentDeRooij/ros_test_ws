#ifndef __SERIALIO_H__
#define __SERIALIO_H__
#pragma once

// system includes
#include <serial/serial.h>
#include <queue>

// created includes
#include "exr_definitions.h"

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
    void SerialMsgAdd(const uint16_t serialAddress, const Payload payload, bool isPriorityMsg);
    void ProcessSerialMessages();
    bool isSerialPortAvailable();

private:
    serial::Serial uartCommunicator;
    std::queue<ExrMessage *> std_queue;  // std_queue
    std::queue<ExrMessage *> prio_queue; // prio_queue

    // private methods
    void serialRead();
    bool validateHeaders(ExrMessage *receivedMsg);
    void handleFullQueue(std::queue<ExrMessage *> &queueToProcess);
    void handleSingleQueueItem(std::queue<ExrMessage *> &queueToProcess);
};

#endif // __SERIALIO_H__