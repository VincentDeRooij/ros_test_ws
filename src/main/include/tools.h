#ifndef __TOOLS_H__
#define __TOOLS_H__


// void ExrBaseNode::calcCrc(exrmessage* mes)
// {  
//     mes->crc=mes->header[0];
//     mes->crc ^=mes->header[1];
//     mes->crc ^=mes->header[2];
//     mes->crc ^=mes->header[3];    
//     mes->crc ^= (mes->id & 0x00ff);
//     mes->crc ^= (mes->id & 0xff00) >> 8;
    
//     for (uint8_t ii=0;ii<8;ii++)
//     {
//         mes->crc ^=mes->data[ii];
//     }
// }



#endif // __TOOLS_H__