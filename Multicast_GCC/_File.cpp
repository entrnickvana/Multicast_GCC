

#include "_File.h"
#include "Packet.h"

_File::_File(){};

_File::_File(string* _fileName)
{
	nameOfFile = *_fileName;

}

_File::_File(string* _fileName, unsigned long _numberOfBytes)
{
    nameOfFile = *_fileName;
    numberOfBytes = _numberOfBytes;
    numOfPackets = 1;
}

_File::_File(string* _fileName, unsigned long _numberOfBytes,  unsigned int _numOfPackets)
{
 
    nameOfFile = *_fileName;
    numberOfBytes = _numberOfBytes;
    numOfPackets = _numOfPackets;



}

void _File::packetize(unsigned int numOfPackets)
{
    //if divides evenly
	

    for(unsigned int i = 0; i < numOfPackets; ++i)
    {
		Packet newPacket(this, i + 1);
        packetsOfFile.push_back(newPacket);
    }

    //If doesnty dived evenly, implement later


}


_File::~_File()
{
}
