// system includes

// ROS includes
#include <ros/ros.h>
#include <ros/console.h>

// created includes
#include "SerialIOController.h"
#include "MsgBuilder.h" // includes exr_definitions.h
#include "SerialValidationUtils.h"

// debugging
#include "Debugging.h" // include > enables the ifdef DEBUG

/**
 * @brief Initializes the SerialController, sets up the correct port, baudrate and timeout 
 * 
 */
void SerialIOController::initSerialController()
{
    // setup uartComm object
    this->uartCommunicator.setBaudrate(EX_EXR_BAUDRATE); // set baudrate to 112500
    this->uartCommunicator.setPort(EX_EXR_SERIAL_PORT);  // set the correct serial port of the ExR ttyS5

#ifdef DEBUG

    this->uartCommunicator.setPort(EX_EXR_SERIAL_PORT_DEBUG); // debug port ttyUSB0

#endif // DEBUG

    serial::Timeout t_out = serial::Timeout::simpleTimeout(EX_EXR_SERIAL_TMOUT_MS); // set time-out
    this->uartCommunicator.setTimeout(t_out);
}

void SerialIOController::OpenSerialPortConnection()
{
    while (IsSerialPortAvailable() == false)
    {
        this->uartCommunicator.open();

        if (IsSerialPortAvailable() == true)
        {
            return;
        }

        usleep(1000 * 500); // try again after 500ms
    }
}

void SerialIOController::CloseSerialPortConnection()
{
    while (IsSerialPortAvailable() == true)
    {
        this->uartCommunicator.close();

        if (IsSerialPortAvailable() == false)
        {
            return;
        }
        usleep(1000 * 500);
    }
}

/**
 * @brief Method to check if serial port is open/occupied 
 *  
 * @return true if available
 * @return false if closed/occupied
 */
bool SerialIOController::IsSerialPortAvailable()
{
    if (this->uartCommunicator.isOpen() == true)
    {
        return true;
    }
    return false;
}

/**
 * @brief Processes a whole given std::queue while the queue is not empty   
 * 
 * @param queue the queue (std or prio) which gets processed fully 
 */
void SerialIOController::processQueue(std::queue<ExRMessage> &queue)
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
 * @brief Process the Serial messages from the queues, which are FIFO based 
 * 
 */
void SerialIOController::ProcessSerialMessageQueues()
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
 * @brief Loops through a list of prio-type serial addresses and returns if the given address is of prio-type
 * 
 * @param address Serial address to check for prio-type
 * @return true if serial address is prio-type
 * @return false if serial address is std-type
 */
bool SerialIOController::IsMsgPrioType(const uint16_t &address)
{
    return false;
}