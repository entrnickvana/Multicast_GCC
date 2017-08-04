

#include "catalogFile.h"
#include "Packet.h"
#include<string>

using namespace std;

catalogFile::catalogFile()
{


}

//catalogFile::catalogFile(string* _fileName)
//{
//	nameOfFile = *_fileName;
//
//}
//
//catalogFile::catalogFile(string* _fileName, unsigned long _numberOfBytes)
//{
//	nameOfFile = *_fileName;
//	numberOfBytes = _numberOfBytes;
//	numOfPackets = 1;
//}


//catalogFile::catalogFile(string* _fileName, unsigned long _numberOfBytes, unsigned int _numOfPackets)
//{
//
//	/*nameOfFile = *_fileName;
//	numberOfBytes = _numberOfBytes;
//	numOfPackets = _numOfPackets;*/
//
//
//
//}

void catalogFile::packetize(unsigned int numOfPackets)
{
	//if divides evenly


	for (unsigned int i = 0; i < numOfPackets; ++i)
	{
		//Packet newPacket();  
		//packetsOfFile.push_back(newPacket);
	}

	//If doesnty dived evenly, implement later


}


catalogFile::~catalogFile()
{
}