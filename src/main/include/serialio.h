#ifndef __SERIALIO_H__
#define __SERIALIO_H__

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

    void SerialMsgAdd(const uint16_t serialAddress, const uint8_t payload[8]);
    bool SerialWrite();
    ExrMessage* SerialRead();
    bool isSerialOpen();

private:
    serial::Serial uartCommunicator;
    std::queue <ExrMessage*> queue;    
    bool validateHeaders(ExrMessage* receivedMsg);
};

#endif // __SERIALIO_H__