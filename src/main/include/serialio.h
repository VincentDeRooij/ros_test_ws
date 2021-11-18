#ifndef __SERIALIO_H__
#define __SERIALIO_H__

#include "serial/serial.h"
#include "exr_definitions.h"
#include <queue>

class SerialIO
{
public:
    SerialIO();
    SerialIO(SerialIO &&) = default;
    SerialIO(const SerialIO &) = default;
    SerialIO &operator=(SerialIO &&) = default;
    SerialIO &operator=(const SerialIO &) = default;
    ~SerialIO() = default;

    bool SerialMsgAdd(const uint16_t serialAddress, const uint8_t payload[8]);
    bool SerialWrite();
    ExrMessage* SerialRead();

private:
    serial::Serial uartCommunicator;
    std::queue <ExrMessage*> queue;    
};

#endif // __SERIALIO_H__