#include <iostream>

#include "SerialWriter.h"
#include "MsgBuilder.h"

/**
 * @brief 
 * Adds a new message ready for sending via Serial to the queue
 * Msg gets added to right priority type, depending on the prio-status
 * @param serialAddress the serial address
 * @param payload the loaded payload of the serial/UART message
 * @param isPriorityMsg bool to signal whether the incoming msg is of prio-type
 */
void SerialWriter::AddToMsgQueue(const uint16_t &serialAddress, const Payload &payload, const bool &isPriorityMsg)
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
