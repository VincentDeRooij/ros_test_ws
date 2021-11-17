#include "include/msgbuilder.h"
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

#include "exr_definitions.h" // the include works, but only shows unvalid errors
#include "msgbuilder.h"

#include "serial/serial.h"

int run(int argc, char **argv)
{
  // prepare the serial com link with serial address ttyS5, and baudrate 112500. Where Timeout is 1 second (1000ms) 
  serial::Serial my_serial(EX_EXR_SERIAL_PORT, EX_EXR_BAUDRATE, serial::Timeout::simpleTimeout(1000));

  uint8_t pl[8] = {}; // initialize an empty 

  MsgBuilder b(EX_MOTHER_STATUS_SERIAL_ID_REQ_TYPE, pl); 

  // write to serial address  

  std::cout << "Port is available";
  if(my_serial.isOpen())
  {
      std::cout << " Yes." << std::endl;
  }
  else
  {
    std::cout << " No." << std::endl;

    std::string test = "Hello World"; 

    size_t bytesWritten = my_serial.write((uint8_t*) b.GetExRMessage(), EX_MSG_SIZE); // send empty motherboard info request message, returns number of bytes written
  }
  return 0;
}

int main(int argc, char **argv) {
  try {
    return run(argc, argv);
  } catch (std::exception &e) {
    std::cerr << "Unhandled Exception: " << e.what() << std::endl;
  }
}
