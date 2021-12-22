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

  idDict.AddToMap(EX_DRIVE_LEFT_BANDW_TYPE_SET, bwMb, true);
  idDict.AddToMap(EX_DRIVE_RIGHT_BANDW_TYPE_SET, bwMb, true);

  idDict.AddToMap(EX_DRIVE_LEFT_SETTINGS_TYPE_SET, dsMb, true);
  idDict.AddToMap(EX_DRIVE_LEFT_SETTINGSTATUS_TYPE_RESPONSE, dsMb, false);
  idDict.AddToMap(EX_DRIVE_RIGHT_SETTINGS_TYPE_SET, dsMb, true);
  idDict.AddToMap(EX_DRIVE_RIGHT_SETTINGSTATUS_TYPE_RESPONSE, dsMb, false);

  idDict.AddToMap(EX_DRIVE_LEFT_SPD_TRQ_TYPE_RESPONSE, dstMb, false);
  idDict.AddToMap(EX_DRIVE_RIGHT_SPD_TRQ_TYPE_RESPONSE, dstMb, false);

  idDict.AddToMap(EX_DRIVE_LEFT_INPUT_V_C_TYPE_RESPONSE, iVCMb, false);
  idDict.AddToMap(EX_DRIVE_RIGHT_INPUT_V_C_TYPE_RESPONSE, iVCMb, false);

  idDict.AddToMap(EX_MAINBOARD_OUTPUTSETTINGS_TYPE_SET, mIIMb, true);
  idDict.AddToMap(EX_MAINBOARD_OUTPUTSETTINGS_TYPE_RESPONSE, mIIMb, true);

  idDict.AddToMap(EX_MAINBOARD_STATUS_TYPE_RESPONSE, msMb, false);
  idDict.AddToMap(EX_MAINBOARD_STATUS_TYPE_SET, msMb, true);

  idDict.AddToMap(EX_DRIVE_LEFT_SPEEDREF_TYPE_SET, srMb, true);
  idDict.AddToMap(EX_DRIVE_RIGHT_SPEEDREF_TYPE_SET, srMb, true);

  idDict.AddToMap(EX_DRIVE_LEFT_MOSFETTEMP_TYPE_RESPONSE, tMb, false);
  idDict.AddToMap(EX_DRIVE_RIGHT_MOSFETTEMP_TYPE_RESPONSE, tMb, false);

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
