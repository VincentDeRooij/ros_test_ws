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

  // std::cout << "Serial: " << unsigned(EX_MOTHER_STATUS_SERIAL_ID_REQ_TYPE) << std::endl;

  // uint8_t crc = 0x220 & 0x00FF;

  // std::cout << "Serial: " << unsigned(crc) << std::endl;

  // std::cout << "Serial_s2:" << unsigned(crc & 0xff00) << std::endl;

  // crc = 0;

  // crc = MSG_HF_1;
  // crc ^= MSG_HF_2;
  // crc ^= MSG_HF_3;
  // crc ^= MSG_HF_4;
  // crc ^= (EX_MOTHER_STATUS_SERIAL_ID_REQ_TYPE & 0x00ff);
  // crc ^= (EX_MOTHER_STATUS_SERIAL_ID_REQ_TYPE & 0xff00) >> 8;

  // std::cout << "Serial_Pre: " << unsigned(crc) << std::endl;

  // // fill the payload with empty data
  // for (uint8_t index = 0; index < 8; index++)
  // {
  //   crc ^= 0;
  // }

  // std::cout << "Serial_Aft: " << unsigned(crc) << std::endl;

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
