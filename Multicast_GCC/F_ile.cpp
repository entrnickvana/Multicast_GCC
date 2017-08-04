

#include "F_ile.h"
#include "Packet.h"

F_ile::F_ile() {};

F_ile::F_ile(string* _fileName)
{
	nameOfFile = *_fileName;

}

F_ile::F_ile(string* _fileName, unsigned long _numberOfBytes)
{
	nameOfFile = *_fileName;
	numberOfBytes = _numberOfBytes;
	numOfPackets = 1;
}

F_ile::F_ile(string* _fileName, unsigned long _numberOfBytes, unsigned int _numOfPackets)
{

	nameOfFile = *_fileName;
	numberOfBytes = _numberOfBytes;
	numOfPackets = _numOfPackets;



}

void F_ile::packetize(unsigned int numOfPackets)
{
	//if divides evenly


	for (unsigned int i = 0; i < numOfPackets; ++i)
	{
		Packet newPacket(this, i + 1);
		packetsOfFile.push_back(newPacket);
	}

	//If doesnty dived evenly, implement later


}


F_ile::~F_ile()
{
}