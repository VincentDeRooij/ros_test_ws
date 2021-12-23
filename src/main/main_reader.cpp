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

// Include all the Mailboxes
#include "MBoxBandWidth.h"
#include "MBoxDriveSettings.h"
#include "MBoxDriveSpeedTorque.h"
#include "MBoxInputVoltageCurrent.h"
#include "MBoxMainboardIOInfo.h"
#include "MBoxMotherboardStatus.h"
#include "MBoxSpeedRef.h"
#include "MBoxTemperatures.h"

MBoxBandWidth::DynamicBandwidthPayload a;

int run(int argc, char **argv)
{
  UARTIdentificationDictionary idDict;

  MBoxBandWidth bwMb;
  MBoxDriveSettings dsMb;
  MBoxDriveSpeedTorque dstMb;
  MBoxInputVoltageCurrent iVCMb;
  MBoxMainboardIOInfo mIIMb;
  MBoxMotherboardStatus msMb;
  MBoxSpeedRef srMb;
  MBoxTemperatures tMb;

  idDict.AddToMap(EX_DRIVE_LEFT_BANDW_TYPE_SET, bwMb);
  idDict.AddToMap(EX_DRIVE_RIGHT_BANDW_TYPE_SET, bwMb);

  idDict.AddToMap(EX_DRIVE_LEFT_SETTINGS_TYPE_SET, dsMb);
  idDict.AddToMap(EX_DRIVE_LEFT_SETTINGSTATUS_TYPE_RESPONSE, dsMb);
  idDict.AddToMap(EX_DRIVE_RIGHT_SETTINGS_TYPE_SET, dsMb);
  idDict.AddToMap(EX_DRIVE_RIGHT_SETTINGSTATUS_TYPE_RESPONSE, dsMb);

  idDict.AddToMap(EX_DRIVE_LEFT_SPD_TRQ_TYPE_RESPONSE, dstMb);
  idDict.AddToMap(EX_DRIVE_RIGHT_SPD_TRQ_TYPE_RESPONSE, dstMb);

  idDict.AddToMap(EX_DRIVE_LEFT_INPUT_V_C_TYPE_RESPONSE, iVCMb);
  idDict.AddToMap(EX_DRIVE_RIGHT_INPUT_V_C_TYPE_RESPONSE, iVCMb);

  idDict.AddToMap(EX_MAINBOARD_OUTPUTSETTINGS_TYPE_SET, mIIMb);
  idDict.AddToMap(EX_MAINBOARD_OUTPUTSETTINGS_TYPE_RESPONSE, mIIMb);

  idDict.AddToMap(EX_MAINBOARD_STATUS_TYPE_RESPONSE, msMb);
  idDict.AddToMap(EX_MAINBOARD_STATUS_TYPE_SET, msMb);

  idDict.AddToMap(EX_DRIVE_SPEEDREF_TYPE_SET, srMb);

  idDict.AddToMap(EX_DRIVE_LEFT_MOSFETTEMP_TYPE_RESPONSE, tMb);
  idDict.AddToMap(EX_DRIVE_RIGHT_MOSFETTEMP_TYPE_RESPONSE, tMb);

  SerialReader read(idDict);
  read.StartReaderProcess();

  read.ProcessSerialMessageQueues();

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
