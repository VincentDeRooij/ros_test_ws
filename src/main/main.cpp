// system includes
#include <cstdint>
#include <string>
#include <iostream>
#include <cstdio>

// OS Specific sleep
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

// serial lib
#include <serial/serial.h>

// created includes
#include "serialio.h"
#include "payload.h"

int run(int argc, char **argv)
{
  Payload pl; // initialize an empty

  //Payload l(0x01, 0x01, 0x01, 0x00, 0x11, 0x12, 0x01, 0x01);

  SerialIO sio;

  // examples which - Note almost all the Request types cannot be send on their own, but get received as feedback msg
  sio.SerialMsgAdd(EX_MOTHER_STATUS_SERIAL_ID_REQ_TYPE, pl, false); //  non-prio-type
  //sio.SerialMsgAdd(EX_MOTOR_RIGHT_MOSFET_TEMP_REQ_TYPE, l, false);  //  non-prio-type
  //sio.SerialMsgAdd(EX_MOTOR_LEFT_DRIVE_STATUS_REQ_TYPE, l, true);   //  non-prio-type
  //sio.SerialMsgAdd(EX_MOTOR_RIGHT_SPEED_TORQUE_REQ_TYPE, pl, true); //  non-prio-type

  // process the message Queue
  sio.ProcessSerialMessageQueues();

  return 0;
}

int main(int argc, char **argv)
{
  try
  {
    return run(argc, argv);
  }
  catch (std::exception &e)
  {
    std::cerr << "Unhandled Exception: " << e.what() << std::endl;
  }
}
