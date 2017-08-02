

#include "_File.h"
#include "Packet.h"

_File::_File(){};

_File::_File(string _fileName, unsigned long _numberOfBytes)
{
    fileName = _fileName;
    numberOfBytes = _numberOfBytes;
    numOfPackets = 1;
}

_File::_File(string _fileName, unsigned long _numberOfBytes,  unsigned int _numOfPackets)
{
 
    fileName = _fileName;
    numberOfBytes = _numberOfBytes;
    numOfPackets = _numOfPackets;



}

void _File::packetize(unsigned int numOfPackets)
{
    //if divides evenly
    Packet* newPacket;

    for(unsigned int i = 0; i < numOfPackets; ++i)
    {
        newPacket = new Packet(*this, i + 1);
        packetsOfFile.push_back(*newPacket);
    }

    //If doesnty dived evenly, implement later


}


_File::~_File()
{
}
