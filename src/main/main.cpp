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
#include "SerialWriter.h"
#include "SerialReader.h"
//#include "Payload.h"
#include "ExRSerialDefinitions.h"
//#include "ExRMsgStructures.h"

#include "MBoxMainboardIOInfo.h"

int run(int argc, char **argv)
{
  MBoxMainboardIOInfo mBox(true, true, false);
  SerialWriter writer; // The serial writer portion

  //ExROutputStructure a;

  // uint8_t bytes[2];
  // uint16_t value;

  // value = 0x1234;

  // bytes[0] = *((uint8_t *)&(value) + 1); //high byte (0x12)
  // bytes[1] = *((uint8_t *)&(value) + 0); //low byte  (0x34)

  // Payload a;

  // a.setPayloadRow(0, bytes[0]);
  // a.setPayloadRow(1, bytes[1]);

  // std::cout << "TEST: " << unsigned(value) << std::endl;

  // //Payload pl = mBox.Write(); // initialize an empty

  // pl.setPayloadRow(1, bytes[0]);
  // pl.setPayloadRow(2, bytes[1]);

  //mempcpy(&a, &pl, sizeof(a));

  //std::cout << "TEST: " << unsigned(a.BAT_VOLTAGE) << std::endl;
  writer.AddToMsgQueue(EX_MOTHER_STATUS_SERIAL_ID_REQ_TYPE, mBox.Write(), false);
  writer.ProcessSerialMessageQueues();

  // SerialReader reader; // Needs to be run seperate

  usleep(2500 * (1000));

  //reader.ProcessSerialMessageQueues();

  // Payload p(reader.msg.payload[0],
  //           reader.msg.payload[1],
  //           reader.msg.payload[2],
  //           reader.msg.payload[3],
  //           reader.msg.payload[4],
  //           reader.msg.payload[5],
  //           reader.msg.payload[6],
  //           reader.msg.payload[7]);
  //mBox.Read();

  MBoxMainboardIOInfo mBox_off(false, false, false);
  writer.AddToMsgQueue(EX_MOTHER_STATUS_SERIAL_ID_REQ_TYPE, mBox_off.Write(), false);
  writer.ProcessSerialMessageQueues();

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
