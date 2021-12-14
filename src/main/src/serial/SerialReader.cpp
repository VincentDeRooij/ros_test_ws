#include <iostream>

#include "SerialReader.h"
#include "SerialValidationUtils.h"
#include "MBoxMainboardIOInfo.h"
#include "MsgBuilder.h"

SerialReader::SerialReader(UARTIdentificationDictionary dict)
{
    this->processDictionary = dict;
}

void SerialReader::StartReaderProcess()
{
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
            }
            printf("\n");

            if (ValidateHeaders(messagePtr) == true && CalcCRCFromExRMessage(messagePtr) == true)
            {
                std::cout << "MESSAGE_VALID" << std::endl;
                // LOGGER - MESSAGE READ / PROCESSING
                std::cout << "SERIAL_ADDR_RECEIVED:" << unsigned(messagePtr.serialId) << std::endl;

                // Implement Check to decide which serial addresses are of priotype
                this->AddToMsgQueue(messagePtr, IsMsgPrioType(messagePtr.serialId));

                // MBoxMainboardIOInfo a(false, false, false);

                // Payload pl(
                //     messagePtr.payload[0],
                //     messagePtr.payload[1],
                //     messagePtr.payload[2],
                //     messagePtr.payload[3],
                //     messagePtr.payload[4],
                //     messagePtr.payload[5],
                //     messagePtr.payload[6],
                //     messagePtr.payload[7]);

                // a.Read(pl);
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
        std::cout << "READER: SERIAL_PORT_UNAVAILABLE/CLOSED" << std::endl;

        // try to openup the serial port connection
        this->uartCommunicator.open();
    }
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
