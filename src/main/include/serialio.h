#ifndef __SERIALIO_H__
#define __SERIALIO_H__

#include "serial/serial.h"
#include "exr_definitions.h"

class SerialIO
{
public:
    SerialIO();
    SerialIO(SerialIO &&) = default;
    SerialIO(const SerialIO &) = default;
    SerialIO &operator=(SerialIO &&) = default;
    SerialIO &operator=(const SerialIO &) = default;
    ~SerialIO() = default;

    void SerialWriter();
    void SerialRead();

private:
    serial::Serial uartCommunicator;
    
};

#endif // __SERIALIO_H__