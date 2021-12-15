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

// Mailboxes
#include "MBoxMainboardIOInfo.h"

#include "MBoxDriveSettings.h"

#include "MBoxMotherboardStatus.h"

int run(int argc, char **argv)
{
  std::cout << "Setting up the writer..." << std::endl;
  // Serial writer
  SerialWriter writer; // The serial writer portion
  writer.OpenSerialPortConnection();

  MBoxMainboardIOInfo info_on(true, true, true);
  MBoxMainboardIOInfo info_off(false, false, true);

  MBoxMotherboardStatus status;

  writer.AddToMsgQueue(EX_MAINBOARD_OUTPUTSETTINGS_TYPE_SET, info_on.Write(), false);
  writer.ProcessSerialMessageQueues();

  usleep(1000 * 100);

  writer.AddToMsgQueue(EX_MAINBOARD_OUTPUTSETTINGS_TYPE_SET, info_off.Write(), false);
  writer.ProcessSerialMessageQueues();

  usleep(1000 * 100);

  writer.AddToMsgQueue(EX_MAINBOARD_STATUS_TYPE_SET, status.Write(), false);
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
