#include "serialio.h" 

SerialIO::SerialIO()
{
    // setup uartComm object
    this->uartCommunicator.setBaudrate(EX_EXR_BAUDRATE);
    this->uartCommunicator.setPort(EX_EXR_SERIAL_PORT);
    serial::Timeout to = serial::Timeout::simpleTimeout(EX_EXR_SERIAL_TMOUT_MS); // set time-out 
    this->uartCommunicator.setTimeout(to);
}