#include "MBoxBandWidth.h"
#include "Converter.h"

MBoxBandWidth::MBoxBandWidth()
{
}

Payload MBoxBandWidth::Write()
{
    Payload pl;
    int32_t bwCurrent = 0;
    int32_t controlBw = 20;

    uint32_t bwCurrentConv = Int32ToUInt32Fixed(bwCurrent, IQ24);
    uint32_t controlBwConv = Int32ToUInt32Fixed(controlBw, IQ20);

    copyInt32ToByteBuffer(bwCurrentConv, &pl.payFull[0]);
    copyInt32ToByteBuffer(controlBwConv, &pl.payFull[4]);

    return pl;
}

void MBoxBandWidth::Read(Payload &p)
{
    // EMPTY
}