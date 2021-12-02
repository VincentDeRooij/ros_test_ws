/**
 * @brief 
 * Writes the Serial message from the queue, which is FIFO based
 * @return true if bytes written is 15 bytes
 * @return false if bytes written is not 15 bytes, which means error occured
 */

#include <ros/ros.h>
#include <stdint.h>
#include <vector>
#include <string>

#include <serial/serial.h>
#include "exr_definitions.h"

#define EX_MSG_SIZE 15

// typedef struct
// {
//     uint8_t header[4];
//     uint16_t serialId;
//     uint8_t payload[8];
//     uint8_t crc;
// } ExRMessage;

main(int argc, char **argv)
{
    ExRMessage msgInQueue; // = this->queue.front(); // takes the First-In First-Out item from the queue

    msgInQueue.header[0] = 'a';
    msgInQueue.header[1] = 'b';
    msgInQueue.header[2] = 'c';
    msgInQueue.header[3] = 'd';

    msgInQueue.serialId = '0';

    msgInQueue.payload[0] = '0';
    msgInQueue.payload[1] = '1';
    msgInQueue.payload[2] = '2';
    msgInQueue.payload[3] = '3';
    msgInQueue.payload[4] = '4';
    msgInQueue.payload[5] = '5';
    msgInQueue.payload[6] = '6';
    msgInQueue.payload[7] = '7';

    msgInQueue.crc = '9';

    serial::Serial s_port;

    s_port.setBaudrate(EX_EXR_BAUDRATE);
    s_port.setPort(EX_EXR_SERIAL_PORT);
    // serial::Timeout t_out = serial::Timeout::simpleTimeout(EX_EXR_SERIAL_TMOUT_MS); // set time-out
    s_port.setTimeout(serial::Timeout::max(), 250, 0, 250, 0);

    // s_port.setPort("/dev/ttyUSB0");
    // s_port.setBaudrate(115200);

    // serial::Timeout to = serial::Timeout(50, 50, 0, 50, 0);
    // s_port.setTimeout(to);

    while (1)
    {
        // ros::Duration(0.002).sleep(); // delay is needed, STM & UART need processesing time -- NEEDS IMPLEMENT

        // DEBUG
        std::cout << "Ready for writing..." << std::endl;
        std::cout << "MessageSize: " << sizeof(msgInQueue) << std::endl;

        for (int ii = 0; ii < sizeof(msgInQueue); ii++)
        {
            std::cout << ((uint8_t *)&msgInQueue)[ii] << "  ";
        }

        std::cout << std::endl;

        //    if (sizeof(msgInQueue) == EX_MSG_SIZE)
        {
            // DEBUG MSG TEST
            std::cout << "Message correct..." << std::endl;

            //  this->uartCommunicator.open(); // opens the serial port connection
            s_port.open();
            if (s_port.isOpen())
            {
                std::string s = "Hello World - Testing Serial";

                int count = 0;
                std::cout << "Timeout == 250ms, asking for exactly what was written." << std::endl;
                while (count < 10)
                {
                    size_t bytes_wrote = s_port.write(s);

                    std::string result = s_port.read(s.length());

                    std::cout << "Iteration: " << count << ", Bytes written: ";
                    std::cout << bytes_wrote << ", Bytes read: ";
                    std::cout << result.length() << ", String read: " << result << std::endl;

                    count += 1;
                }
                // // DEBUG MSG TEST
                // std::cout << "Writing..." << std::endl;

                // size_t bytesSend = s_port.write((uint8_t *)&msgInQueue, EX_MSG_SIZE);

                // std::cout << bytesSend << std::endl;

                // ExRMessage msg;

                // std::cout << "READING" << std::endl;
                // auto result = s_port.read((uint8_t *)&msg, EX_MSG_SIZE);

                // std::cout << "RESULT: " << result << std::endl;

                s_port.close(); // closes port after writing

                //return true
            }
        }
        usleep(1000000);
    }
    return 0; //return false;
}
