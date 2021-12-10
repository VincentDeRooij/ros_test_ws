#include <iostream>

#include "SerialReader.h"
#include "SerialValidationUtils.h"

SerialReader::SerialReader()
{
    this->uartCommunicator.open();
    while (1)
    {
        //this->uartCommunicator.open();
        SerialReadMsg(); /* code */

        // Temporary Placed
        usleep((1000) * 5); // sleep for 5ms // Check if value is fine
    }
}

/**
 * @brief Read the serial messages 
 * 
 */
void SerialReader::SerialReadMsg()
{
    while (IsSerialPortAvailable() == false)
    {
        this->uartCommunicator.open();
        usleep((1000) * 100); // sleep for 5ms // Check if value is fine
    }

    if (IsSerialPortAvailable() == true)
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

            if (ValidateHeaders(messagePtr) == true && CalcCRCFromExRMessage(messagePtr) == true)
            {
                std::cout << "MESSAGE_VALID" << std::endl;
                // LOGGER - MESSAGE READ / PROCESSING
                std::cout << "SERIAL_ADDR_RECEIVED:" << unsigned(messagePtr.serialId) << std::endl;

                // Implement Check to decide which serial addresses are of priotype
                this->AddToMsgQueue(messagePtr, IsMsgPrioType(messagePtr.serialId));
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
    this->uartCommunicator.close();
    std::cout << std::endl;
}

/**
 * @brief 
 * Adds a new message ready for sending via Serial to the queue
 * Msg gets added to right priority type, depending on the prio-status
 * @param msg the serial address
 * @param isPrioType bool to signal whether the incoming msg is of prio-type
 */
void SerialReader::AddToMsgQueue(const ExRMessage &msg, const bool &isPrioType)
{
    if (isPrioType == true)
    {
        this->prio_queue.push(msg);
    }
    else
    {
        this->std_queue.push(msg);
    }
}
