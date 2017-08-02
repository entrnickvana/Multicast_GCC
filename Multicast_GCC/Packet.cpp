#include "Packet.h"
#include<string>
#include<vector>
#include "_File.h"


using namespace std;

Packet::Packet()
{
    long sizeInBits;
    long sizeInBytes;
    vector<char> data;
	string fileName;
    string packetName;
	_File parentFile;
}

Packet::Packet(_File f, unsigned int _partitionNumber)
{

    sizeInBits = f.numberOfBytes*8;
    sizeInBytes = f.numberOfBytes;
	fileName = f.fileName;
    partitionNumber = _partitionNumber;
    string partitionNumString = to_string(partitionNumber);
    packetName = fileName + partitionNumString;
    parentFile = f;

}

string Packet::toString()
{
    return packetName;
}

Packet::~Packet()
{
}
