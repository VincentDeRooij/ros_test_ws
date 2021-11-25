// system includes
#include <iostream> // console include, std::cout, std::endl, etc...

// ROS includes
#include <ros/ros.h>
#include <ros/console.h>

// created includes
#include "serialio.h"
#include "msgbuilder.h" // includes exr_definitions.h
#include "tooling.h"
#include "UartProcessor.h"

// debugging
#include "debugging_tools.h" // include > enables the ifdef DEBUG

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
bool SerialIO::isSerialPortAvailable()
{
    if (this->uartCommunicator.isOpen() == true)
    {
        return true;
    }
    return false;
}

/**
 * @brief 
 * Adds a new message ready for sending via Serial to the queue
 * Msg gets added to right priority type, depending on the prio-status
 * @param serialAddress the serial address
 * @param payload the loaded payload of the serial/UART message
 * @param isPriorityMsg bool to signal whether the incoming msg is of prio-type
 */
void SerialIO::SerialMsgAdd(const uint16_t serialAddress, const Payload payload, bool isPriorityMsg)
{
    // build the msg
    MsgBuilder builder(serialAddress, payload);

    if (isPriorityMsg == true)
    {
        this->prio_queue.push(builder.GetExRMessage());
    }
    else
    {
        this->std_queue.push(builder.GetExRMessage()); // adds the message to the queue
    }
}

void SerialIO::handleSingleQueueItem(std::queue<ExrMessage *> &queueToProcess)
{
    if (queueToProcess.empty() == false) // loops while the message queue contains more messages
    {
#if SERIAL_MODE
        // opens the serial comm on the specified serial port
        this->uartCommunicator.open(); // opens the serial port connection
        if (isSerialPortAvailable())
        {
            // write message from the queue to the
            if (this->uartCommunicator.write((uint8_t *)queueToProcess.front(), EX_MSG_SIZE != EX_MSG_SIZE)) // if the messageLength is not equal to the required size
            {
                // LOG RESULTS - INVALID ENTRY / DO SOMETHING?
                return;
            }
#endif
            // LOG RESULTS - QUEUE ITEM PROCESSED
            // removes the entry from the queue
            queueToProcess.pop();

            // read and process incoming msg

#if SERIAL_MODE

            this->uartCommunicator.close(); // closes port after processing the message
        }
#endif // DEBUG

        // gets the message
    }
}

void SerialIO::handleFullQueue(std::queue<ExrMessage *> &queueToProcess)
{
    if (queueToProcess.empty() == false)
    {
        std::cout << "Message Queue not empty - Walking through the queue...." << std::endl;
        while (queueToProcess.empty() == false) // loops while the message queue contains more messages
        {
#if SERIAL_MODE
            // opens the serial comm on the specified serial port
            this->uartCommunicator.open(); // opens the serial port connection
            if (isSerialPortAvailable())
            {
                // get message from the queue

                if (this->uartCommunicator.write((uint8_t *)queueToProcess.front(), EX_MSG_SIZE != EX_MSG_SIZE)) // if the messageLength is not equal to the required size
                {
                    // LOG RESULTS - INVALID ENTRY / DO SOMETHING?
                    return;
                }
#endif
                // LOG RESULTS - QUEUE ITEM PROCESSED
                // removes the entry from the queue
                queueToProcess.pop();

                // read and process incoming msg
                serialRead();

#if SERIAL_MODE

                this->uartCommunicator.close(); // closes port after processing the message
            }
#endif // DEBUG
        }
    }
}

/**
 * @brief 
 * Writes the Serial messages from the queues, which are FIFO based
 */
void SerialIO::ProcessSerialMessages()
{
    if (this->prio_queue.empty() == false)
    {
        handleFullQueue(this->prio_queue);
    }
    handleSingleQueueItem(this->std_queue); // handle a single queue item
}

/**
 * @brief 
 * Serial read message
 * @return ExrMessage* : the object which was created for reading the serial port 
 */
void SerialIO::serialRead()
{
    ExrMessage *messagePtr;

    // read serial message
    if (this->uartCommunicator.read((uint8_t *)&messagePtr, EX_MSG_SIZE) == EX_MSG_SIZE)
    {
        if (validateHeaders(messagePtr) == true && CalcCRCFromExRMessage(messagePtr) == true)
        {
            // do something with message
            std::cout << "Message received is valid... continuing to process" << std::endl;
            // UartProcessor(); // ?
        }
    }
    else
    {
        // ERROR CATCHING?
        //throw std::exception;
    }
}

/**
 * @brief 
 * first check which validates the Headers to check if the message
 * @param receivedMsg the received UART/Serial message to check
 * @return true if message headers are valid
 * @return false if message headers are invalid
 */
bool SerialIO::validateHeaders(ExrMessage *receivedMsg)
{
    return receivedMsg->header[0] == MSG_HF_1 && receivedMsg->header[1] == MSG_HF_2 && receivedMsg->header[2] == MSG_HF_3 && receivedMsg->header[3] == MSG_HF_4;
}