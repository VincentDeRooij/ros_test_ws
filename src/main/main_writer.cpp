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

  MBoxMainboardIOInfo info;
  MBoxMotherboardStatus status;
  MBoxDriveSettings settings;

  MBoxDriveSettings::DynamicDriveSettingsPayload pl_settings;
  MBoxMainboardIOInfo::DynamicMainboardIOInfoPayload pl_info;

  pl_info.IO_Expander_P0_0_LIGHT_1 = true;
  pl_info.IO_Expander_P0_1_LIGHT_2 = true;
  pl_info.IO_Expander_P0_7_MOTOR = true;
  info.Set(&pl_info);
  writer.AddToMsgQueue(EX_MAINBOARD_OUTPUTSETTINGS_TYPE_SET, info.Write(), false);
  writer.ProcessSerialMessageQueues();

  usleep(1000 * (1000));

  pl_info.IO_Expander_P0_0_LIGHT_1 = false;
  pl_info.IO_Expander_P0_1_LIGHT_2 = false;
  info.Set(&pl_info);
  writer.AddToMsgQueue(EX_MAINBOARD_OUTPUTSETTINGS_TYPE_SET, info.Write(), false);
  writer.ProcessSerialMessageQueues();

  usleep(1000 * (1000));

  writer.AddToMsgQueue(EX_MAINBOARD_STATUS_TYPE_SET, status.Write(), false);
  writer.ProcessSerialMessageQueues();

  pl_settings.DRV_ENABLE = true;
  pl_settings.DRV_IDENTIFY = true;
  pl_settings.ENABLE_FORCE_ANGLE = true;
  pl_settings.ENABLE_OFFSET_CALC = true;
  pl_settings.ENABLE_RS_RECALC = true;
  pl_settings.ENABLE_USER_PARAM = true;
  settings.Set(&pl_settings);
  writer.AddToMsgQueue(EX_DRIVE_LEFT_SETTINGS_TYPE_SET, settings.Write(), false);
  writer.AddToMsgQueue(EX_DRIVE_RIGHT_SETTINGS_TYPE_SET, settings.Write(), false);
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
