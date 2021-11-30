#include "debugging_tools.h"

void DebuggerPrintSimple(std::string txt)
{
    std::cout << "DEBUG" << txt << std::endl;
}

void DebuggerPrintPayloadInfo(const uint8_t pl[8])
{
    std::cout << "PL_INFO";
    for (size_t index = 0; index < sizeof(pl); index++)
    {
        std::cout << " " << index << ":v=" << unsigned(pl[index]);
    }
    std::cout << std::endl;
}