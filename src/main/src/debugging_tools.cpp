#include "debugging_tools.h"

void DebuggerPrintSimple(std::string txt)
{
    std::cout << "DEBUG" << txt << std::endl;
}

void DebuggerPrintPayloadInfo(const uint8_t pl[8])
{
    std::cout << "PL_INFO";
    for (size_t index = 0; index < (sizeof(pl) / sizeof(pl[0])); index++)
    {
        std::cout << index << ":v=" << pl[index];
    }
    std::cout << std::endl;
}