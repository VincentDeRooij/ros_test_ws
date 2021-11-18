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
    this->queue.push( builder.GetExRMessage() );

    return false;
}

bool SerialIO::SerialWrite()
{
    ExrMessage* msgInQueue = this->queue.front();

    if (sizeof(msgInQueue) == EX_MSG_SIZE)
    { 
        size_t bytesSend = this->uartCommunicator.write((uint8_t*) msgInQueue, EX_MSG_SIZE);        
        return true; 
    }
    else
    {
        // error handling
        return false;
    }    
}

bool SerialIO::SerialRead(ExrMessage &message)
{
    // read serial message
    if (this->uartCommunicator.read(uint8_t*) message, EX_MSG_SIZE) == EX_MSG_SIZE)
    {
        
    }
    

    return false;
}