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
void SerialIO::SerialMsgAdd(const uint16_t &serialAddress, const Payload &payload, const bool &isPriorityMsg)
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

void SerialIO::processItem(std::queue<ExrMessage> &queue)
{
    // check if the given queue is empty
    if (queue.empty() == false) // loops while the message queue contains more messages
    {
        // opens the serial connection --> Check which way is better --> Always open, or open/close principle
        this->uartCommunicator.open();
        // opens the serial comm on the specified serial port
        if (isSerialPortAvailable())
        {
            size_t size = this->uartCommunicator.write((uint8_t *)&queue.front(), EX_MSG_SIZE);
            std::cout << "MSG_SIZE_WRITTEN: " << size << std::endl;

            if (size == EX_MSG_SIZE) // if the messageLength is not equal to the required size
            {
                // LOG RESULTS - QUEUE ITEM PROCESSED

                // read and process incoming msg
                serialRead();
            }
            else
            {
                // LOG RESULTS - INVALID ENTRY / DO SOMETHING?
            }
            // removes the entry from the queue
            queue.pop();
        }
        else
        {
            std::cout << "SERIAL_PORT_UNAVAILABLE" << std::endl;
        }
        // closes port after processing the message
        this->uartCommunicator.close();
    }
}

void SerialIO::processQueue(std::queue<ExrMessage> &queue)
{
    // LOGGER processing which queue
    // process the selected queue
    while (queue.empty() == false)
    {
        // process item
        processItem(queue);

        std::cout << std::endl;
    }
}

/**
 * @brief 
 * Writes the Serial messages from the queues, which are FIFO based
 */
void SerialIO::ProcessSerialMessageQueues()
{
    // if any critical / prio messages are found, proceed to process these first
    if (this->prio_queue.empty() == false)
    {
        processQueue(this->prio_queue);
    }
    // process message in the queue - one by one
    processItem(this->std_queue); // handle a single queue item
}

/**
 * @brief 
 * Serial read message
 * @return ExrMessage* : the object which was created for reading the serial port 
 */
void SerialIO::serialRead()
{
    if (isSerialPortAvailable() == true)
    {
        ExrMessage messagePtr;

        size_t msgSize = this->uartCommunicator.read((uint8_t *)&messagePtr, EX_MSG_SIZE);

        std::cout << "MSG_SIZE_RETURN: " << msgSize << std::endl;
        // read serial message
        if (msgSize == EX_MSG_SIZE)
        {
            if (validateHeaders(messagePtr) == true && CalcCRCFromExRMessage(messagePtr) == true)
            {
                // LOGGER - MESSAGE READ / PROCESSING
                // UartProcessor(); // ?
            }
            else
            {
                // LOGGER - MESSAGE HEADER / CRC invalid, log received message contents?
            }
        }
        else
        {
            // ERROR CATCHING / HANDLING?
            //throw std::exception;
        }
    }
    else
    {
        // LOGGER - SERIAL_OFFLINE / Exception, or error handling
        std::cout << "SERIAL_OFFLINE:" << std::endl;
    }
}

/**
 * @brief 
 * first check which validates the Headers to check if the message
 * @param receivedMsg the received UART/Serial message to check
 * @return true if message headers are valid
 * @return false if message headers are invalid
 */
bool SerialIO::validateHeaders(ExrMessage &receivedMsg)
{
    return receivedMsg.header[0] == MSG_HF_1 && receivedMsg.header[1] == MSG_HF_2 && receivedMsg.header[2] == MSG_HF_3 && receivedMsg.header[3] == MSG_HF_4;
}