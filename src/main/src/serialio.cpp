#include "serialio.h" 
#include "msgbuilder.h"

SerialIO::SerialIO()
{
    // setup uartComm object
    this->uartCommunicator.setBaudrate(EX_EXR_BAUDRATE);
    this->uartCommunicator.setPort(EX_EXR_SERIAL_PORT);
    serial::Timeout to = serial::Timeout::simpleTimeout(EX_EXR_SERIAL_TMOUT_MS); // set time-out 
    this->uartCommunicator.setTimeout(to);
}

bool SerialIO::SerialMsgAdd(const uint16_t serialAddress, const uint8_t payload[8])
{
    MsgBuilder builder(serialAddress, payload);
    this->queue.push(builder.GetExRMessage());
}

bool SerialIO::SerialWrite(const uint16_t serialAddress, const uint8_t payload[8])
{
    MsgBuilder builder(serialAddress, payload);
    size_t bytesWritten = this->uartCommunicator.write((uint8_t*) builder.GetExRMessage(), EX_MSG_SIZE);

    if (bytesWritten == EX_MSG_SIZE)
    {
        return true; // if serial write is succesfully completed
    }
    else
    {
        // error handling
    }    
}

bool SerialIO::SerialRead(ExrMessage &message)
{
    
}