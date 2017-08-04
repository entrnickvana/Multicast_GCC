
#ifndef PACKET_H
#define PACKET_H

#include<vector>
#include<string>
//#include "Media.h"
//#include "catalogFile.h"


using namespace std;

class Media;

class Packet
{
public:

	Packet();
	Packet(Media* parentMediaArg, unsigned int packetPartitionNumber);
	~Packet();

	long sizeInBits;
    long sizeInBytes;
    vector<char> data;
    unsigned int partitionNumber;
    string packetName;
    Media* parentMedia;

	string toString();


};

#endif

