/***
 * This example expects the serial port has a loopback on it.
 *
 * Alternatively, you could use an Arduino:
 *
 * <pre>
 *  void setup() {
 *    Serial.begin(<insert your baudrate here>);
 *  }
 *
 *  void loop() {
 *    if (Serial.available()) {
 *      Serial.write(Serial.read());
 *    }
 *  }
 * </pre>
 */

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

#include "serial/serial.h"

// SERIAL DEFINES

#define X_EXR_PORT "/dev/ttyS5" // the serial port of the EXR 
#define X_EXR_BAUDRATE 115200 // the baud/transfer rate of the EXR serial  

using std::string;
using std::exception;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;

void my_sleep(unsigned long milliseconds) {
#ifdef _WIN32
      Sleep(milliseconds); // 100 ms
#else
      usleep(milliseconds*1000); // 100 ms
#endif
}

int run(int argc, char **argv)
{
  // ttyS5 
  serial::Serial my_serial(X_EXR_PORT, X_EXR_BAUDRATE, serial::Timeout::simpleTimeout(1000));

  // write to serial address  

  cout << "Port is available";
  if(my_serial.isOpen())
    cout << " Yes." << endl;
  else
    cout << " No." << endl;

    std::string test = "Hello World"; 

    size_t result = my_serial.write((uint8_t*) 1000, test.size());

  return 0;
}

int main(int argc, char **argv) {
  try {
    return run(argc, argv);
  } catch (exception &e) {
    cerr << "Unhandled Exception: " << e.what() << endl;
  }
}
