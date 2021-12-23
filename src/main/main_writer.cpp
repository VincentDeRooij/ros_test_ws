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
#include "MBoxDriveSpeedTorque.h"
#include "MBoxBandWidth.h"
#include "MBoxSpeedRef.h"

int run(int argc, char **argv)
{
  std::cout << "Setting up the writer..." << std::endl;

  // Mailboxes
  MBoxMotherboardStatus status;
  MBoxDriveSettings settings;
  MBoxDriveSpeedTorque sptrq;
  MBoxMainboardIOInfo info;
  MBoxBandWidth bw;
  MBoxSpeedRef spRef;

  // Dynamic Payloads
  MBoxDriveSettings::DynamicDriveSettingsPayload pl_settings;
  MBoxMainboardIOInfo::DynamicMainboardIOInfoPayload pl_info;
  MBoxDriveSpeedTorque::DynamicAccelJerkPayload pl_sptrq;
  MBoxBandWidth::DynamicBandwidthPayload pl_bw;
  MBoxSpeedRef::DynamicSpeedRefPayload pl_spRef;

  // Serial writer
  SerialWriter writer; // The serial writer portion
  writer.OpenSerialPortConnection();

  // Testing the lights of the ExR1 (also enabling the GPIO Drive pin)
  pl_info.IO_Expander_P0_0_LIGHT_1 = true;
  pl_info.IO_Expander_P0_1_LIGHT_2 = true;
  pl_info.IO_Expander_P0_7_MOTOR = true;
  info.Set(&pl_info);
  writer.AddToMsgQueue(EX_MAINBOARD_OUTPUTSETTINGS_TYPE_SET, info.Write(), false);
  writer.ProcessSerialMessageQueues();

  // Shutting down the lights
  usleep(1000 * (1000));

  pl_info.IO_Expander_P0_0_LIGHT_1 = false;
  pl_info.IO_Expander_P0_1_LIGHT_2 = false;
  info.Set(&pl_info);
  writer.AddToMsgQueue(EX_MAINBOARD_OUTPUTSETTINGS_TYPE_SET, info.Write(), false);
  writer.ProcessSerialMessageQueues();

  // Setting the Engine up for use
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

  pl_bw.CONTROL_BANDWIDTH = 21;
  pl_bw.MAX_CURRENT = 0;
  bw.Set(&pl_bw);

  // enter the ACCEL / JERK SETUP
  // usleep(1000 * (1000));

  // pl_sptrq.MAX_ACCEL_KRPM = 8;
  // pl_sptrq.MAX_JERK_KRPM = 80;
  // sptrq.Set(&pl_sptrq);
  // writer.AddToMsgQueue(EX_DRIVE_LEFT_MAX_ACCEL_JERK_TYPE_SET, sptrq.Write(), false);
  // writer.AddToMsgQueue(EX_DRIVE_RIGHT_MAX_ACCEL_JERK_TYPE_SET, sptrq.Write(), false);
  // writer.ProcessSerialMessageQueues();

  // enter the BANDWIDTH SETUP
  //usleep(1000 * (1000));

  // pl_bw.CONTROL_BANDWIDTH = 0;
  // pl_bw.MAX_CURRENT = 20;
  // bw.Set(&pl_bw);
  // writer.AddToMsgQueue(EX_DRIVE_LEFT_BANDW_TYPE_SET, bw.Write(), false);
  // writer.AddToMsgQueue(EX_DRIVE_RIGHT_BANDW_TYPE_SET, bw.Write(), false);
  // writer.ProcessSerialMessageQueues();

  // enter the SPEED SETUP
  //usleep(1000 * (1000));

  // pl_spRef.LEFT_MOTOR_DRIVE = 0.5;
  // pl_spRef.RIGHT_MOTOR_DRIVE = 0.5;
  // spRef.Set(&pl_spRef);
  // writer.AddToMsgQueue(EX_DRIVE_SPEEDREF_TYPE_SET, spRef.Write(), false);
  // writer.ProcessSerialMessageQueues();

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
    std::cerr << "Unhandled Exception OR Unrecoverable Exception encountered!: " << e.what() << std::endl;
  }
}
