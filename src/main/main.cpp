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

  SerialIO sio;

  // example which 
  sio.SerialMsgAdd(EX_MOTHER_STATUS_SERIAL_ID_REQ_TYPE, pl.getPayloadFull());
  // write to serial address  

  std::cout << "Port is available" << std::endl; // checks if the serial port is available, or if the port is occupied 
  
  sio.SerialWrite();

  std::cout << "Message written" << std::endl; // checks if the serial port is available, or if the port is occupied 
  
  sio.SerialRead(); // write messages from the buffer

  std::cout << "Message read" << std::endl; // checks if the serial port is available, or if the port is occupied 

  return 0;  
}

int main(int argc, char **argv) {
  try {
    return run(argc, argv);
  } catch (std::exception &e) {
    std::cerr << "Unhandled Exception: " << e.what() << std::endl;
  }
}
