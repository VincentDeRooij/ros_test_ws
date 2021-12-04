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
#include "ExRMsgStructures.h"

int run(int argc, char **argv)
{
  Payload pl; // initialize an empty

  SerialWriter writer; // The serial writer portion
  writer.AddToMsgQueue(EX_MOTHER_STATUS_SERIAL_ID_REQ_TYPE, pl, false);
  writer.ProcessSerialMessageQueues();

  //SerialReader reader; // Needs to be run seperate

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
