#include "MBoxBandWidth.h"
#include "Converter.h"
#include "NotImplementedException.h"

MBoxBandWidth::MBoxBandWidth()
{
}

Payload MBoxBandWidth::Write()
{
    Payload pl;
    int32_t bwCurrent = this->maxCurrent;
    int32_t controlBw = this->controlBandwidth;

    uint32_t bwCurrentConv = Int32ToUInt32Fixed(bwCurrent, IQ24);
    uint32_t controlBwConv = Int32ToUInt32Fixed(controlBw, IQ20);

    copyInt32ToByteBuffer(bwCurrentConv, &pl.payFull[0]);
    copyInt32ToByteBuffer(controlBwConv, &pl.payFull[4]);

    return pl;
}

void MBoxBandWidth::Read(Payload &p)
{
    // EMPTY
    throw NotImplementedException();
}

void MBoxBandWidth::Set(void *dynamicMBoxStruct)
{
    // convert the void pointer type to the structure required
    DynamicBandwidthPayload *dynamicPayload = (DynamicBandwidthPayload *)dynamicMBoxStruct;

    // assign the values
    this->maxCurrent = dynamicPayload->MAX_CURRENT;
    this->controlBandwidth = dynamicPayload->CONTROL_BANDWIDTH;
}