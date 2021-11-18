// system includes
#include <iostream> // console include, std::cout, std::endl, etc...

// created includes
#include "serialio.h" 
#include "msgbuilder.h"
#include "tooling.h"

/**
 * @brief Construct a new SerialIO::SerialIO object
 * 
 */
SerialIO::SerialIO()
{
    // setup uartComm object
    this->uartCommunicator.setBaudrate(EX_EXR_BAUDRATE);
    this->uartCommunicator.setPort(EX_EXR_SERIAL_PORT);
    serial::Timeout t_out = serial::Timeout::simpleTimeout(EX_EXR_SERIAL_TMOUT_MS); // set time-out 
    this->uartCommunicator.setTimeout(t_out);
}

/**
 * @brief 
 * Method to check if serial port is open/occupied
 * @return true if available
 * @return false if closed/occupied
 */
bool SerialIO::isSerialOpen()
{
    return this->uartCommunicator.isOpen();
}

/**
 * @brief 
 * Adds a new message ready for sending via Serial to the queue
 * @param serialAddress the serial address
 * @param payload the loaded payload of the serial/UART message
 */
void SerialIO::SerialMsgAdd(const uint16_t serialAddress, const uint8_t payload[8])
{
    MsgBuilder builder(serialAddress, payload);
    this->queue.push( builder.GetExRMessage() );
}

/**
 * @brief 
 * Writes the Serial message from the queue, which is FIFO based
 * @return true if bytes written is 15 bytes
 * @return false if bytes written is not 15 bytes, which means error occured
 */
bool SerialIO::SerialWrite()
{
    ExrMessage* msgInQueue = this->queue.front(); // takes the First-In First-Out item from the queue


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

/**
 * @brief 
 * Serial read message
 * @return ExrMessage* : the object which was created for reading the serial port 
 */
ExrMessage* SerialIO::SerialRead()
{
    ExrMessage* messagePtr;

    // read serial message
    if (this->uartCommunicator.read((uint8_t*) &messagePtr, EX_MSG_SIZE) == EX_MSG_SIZE)
    {
        if (validateHeaders(messagePtr) == true && CalcCRCFromExRMessage(messagePtr) == true)
        {
            // do something with message
            std::cout << "Message received is valid... continuing to process" << std::endl; 
        }       
    }  
    else
    {
        // ERROR CATCHING?
        return nullptr;
    }
    return messagePtr;
}

/**
 * @brief 
 * first check which validates the Headers to check if the message
 * @param receivedMsg the received UART/Serial message to check
 * @return true if message headers are valid
 * @return false if message headers are invalid
 */
bool SerialIO::validateHeaders(ExrMessage* receivedMsg)
{
    return receivedMsg->header[0] == MSG_HF_1 && receivedMsg->header[1] == MSG_HF_2 
            && receivedMsg->header[2] == MSG_HF_3 && receivedMsg->header[3] == MSG_HF_4;    
}