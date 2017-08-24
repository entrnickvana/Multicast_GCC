
#ifndef PACKET_H
#define PACKET_H

#include<vector>
#include<string>
//#include "Media.h"
//#include "catalogFile.h"
#include<memory>


using namespace std;

class Media;

class Packet
{
public:

	Packet();
	Packet(shared_ptr<Media> parentMediaArg, unsigned int packetPartitionNumber, unsigned int sizeInBytes_);
    bool operator<(const Packet& rhs) const;
	bool operator>(const Packet& rhs) const;
	bool operator<=(const Packet& rhs) const;
	bool operator>=(const Packet& rhs) const;
	bool operator==(const Packet& rhs) const;
	bool operator!=(const Packet& rhs) const;

	//Packet& operator=(const Packet& rhs);
	
	~Packet();

	long sizeInBits;
    long sizeInBytes;
    vector<char> data;
    unsigned int partitionNumber;
    string packetName;
    shared_ptr<Media> parentMedia;

	string toString();


};

#endif

