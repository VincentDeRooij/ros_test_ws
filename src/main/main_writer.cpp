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

int run(int argc, char **argv)
{
  std::cout << "Setting up the writer..." << std::endl;
  // Serial writer
  SerialWriter writer; // The serial writer portion
  writer.OpenSerialPortConnection();

  std::cout << "Enabling lights" << std::endl;

  // Set the lights and the engine io toggle
  MBoxMainboardIOInfo mBox(true, true, true);
  writer.AddToMsgQueue(EX_MOTHER_STATUS_SERIAL_ID_REQ_TYPE, mBox.Write(), false);
  writer.ProcessSerialMessageQueues();

  usleep(1000 * (300)); // sleep for 1 second

  std::cout << "Disabling lights" << std::endl;

  MBoxMainboardIOInfo mBox_off(false, false, true);
  writer.AddToMsgQueue(EX_MOTHER_STATUS_SERIAL_ID_REQ_TYPE, mBox_off.Write(), false);
  writer.ProcessSerialMessageQueues();

  usleep(1000 * (300));

  std::cout << "Enabling the motor-drivers" << std::endl;

  MBoxDriveSettings settings(true);
  writer.AddToMsgQueue(EX_MOTOR_LEFT_DRIVE_SETTINGS_SET_TYPE, settings.Write(), false);
  writer.AddToMsgQueue(EX_MOTOR_RIGHT_DRIVE_SETTINGS_SET_TYPE, settings.Write(), false);
  writer.ProcessSerialMessageQueues();

  usleep(1000 * (1000)); // sleep for ten sec

  std::cout << "Enabling the motor-drivers" << std::endl;

  MBoxDriveSettings settings_dis(false);
  writer.AddToMsgQueue(EX_MOTOR_LEFT_DRIVE_SETTINGS_SET_TYPE, settings_dis.Write(), false);
  writer.AddToMsgQueue(EX_MOTOR_RIGHT_DRIVE_SETTINGS_SET_TYPE, settings_dis.Write(), false);
  writer.ProcessSerialMessageQueues();

  SerialReader r;
  r.OpenSerialPortConnection();
  r.StartReaderProcess();
  r.CloseSerialPortConnection(); // never happens

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
