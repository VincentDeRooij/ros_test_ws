// system includes
#include <iostream> // console include, std::cout, std::endl, etc...

// ROS includes
#include <ros/ros.h>
#include <ros/console.h>

// created includes
#include "SerialIO.h"
#include "MsgBuilder.h" // includes exr_definitions.h
#include "Tooling.h"

// debugging
#include "Debugging.h" // include > enables the ifdef DEBUG

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
        std::cout << "ADDING_PRIO_MSG..." << std::endl;
        this->prio_queue.push(builder.GetExRMessage());
        std::cout << "PRIO_MSG_ADDED!" << std::endl;
    }
    else
    {
        std::cout << "ADDING_NORMAL_MSG..." << std::endl;
        this->std_queue.push(builder.GetExRMessage()); // adds the message to the queue
        std::cout << "NORMAL_MSG_ADDED!" << std::endl;
    }
    std::cout << std::endl;
}

void SerialIO::processItem(std::queue<ExRMessage> &queue)
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

                //
                usleep((1000) * 5); // sleep for 5ms // Check if value is fine
                // read and process incoming msg

                serialRead(); // Make it seperate
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
    std::cout << std::endl;
}

void SerialIO::processQueue(std::queue<ExRMessage> &queue)
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
 * @return ExRMessage* : the object which was created for reading the serial port 
 */
void SerialIO::serialRead()
{
    if (isSerialPortAvailable() == true)
    {
        ExRMessage messagePtr;

        size_t msgSize = this->uartCommunicator.read((uint8_t *)&messagePtr, EX_MSG_SIZE);

        std::cout << "MSG_SIZE_RETURN: " << msgSize << std::endl;
        // read serial message
        if (msgSize == EX_MSG_SIZE)
        {
            for (size_t i = 0; i < sizeof(messagePtr.payload); i++)
            {
                std::cout << unsigned(((uint8_t *)&messagePtr.payload)[i]) << " ";
            }
            std::cout << std::endl;

            std::cout << "CRC:" << unsigned(messagePtr.crc) << std::endl;

            std::cout << messagePtr.header[0] << " - ";
            std::cout << messagePtr.header[1] << " - ";
            std::cout << messagePtr.header[2] << " - ";
            std::cout << messagePtr.header[3] << " - " << std::endl;

            for (int ii = 0; ii < sizeof(messagePtr) - sizeof(uint8_t); ii++)
            {
                uint8_t val = (uint8_t)((uint8_t *)&messagePtr)[ii] & 0xFF;
                printf("0x%02X \t", val);
                //printf("0x%02X \t", (uint8_t)(buffer[ii] & 0xff));
            }
            printf("\n");

            if (validateHeaders(messagePtr) == true && CalcCRCFromExRMessage(messagePtr) == true)
            {
                std::cout << "MESSAGE_VALID" << std::endl;
                // LOGGER - MESSAGE READ / PROCESSING
                // UartProcessor(); // ?

                std::cout << "SERIAL_ADDR_RECEIVED:" << unsigned(messagePtr.serialId) << std::endl;
            }
            else
            {
                std::cout << "INVALID!" << std::endl;
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
    std::cout << std::endl;
}

/**
 * @brief 
 * first check which validates the Headers to check if the message
 * @param receivedMsg the received UART/Serial message to check
 * @return true if message headers are valid
 * @return false if message headers are invalid
 */
bool SerialIO::validateHeaders(ExRMessage &receivedMsg)
{
    std::cout << "VALIDATING...." << std::endl;

    bool valid = receivedMsg.header[0] == MSG_HF_1 && receivedMsg.header[1] == MSG_HF_2 && receivedMsg.header[2] == MSG_HF_3 && receivedMsg.header[3] == MSG_HF_4;

    std::cout << valid << std::endl;
    return valid;
}