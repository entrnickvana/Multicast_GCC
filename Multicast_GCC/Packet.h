#pragma once

#include<vector>
#include<string>
#include "_File.h"


using namespace std;


class Packet
{
public:

	Packet();
    Packet(_File _parentFile, unsigned int partitionNumber);
	~Packet();

	long sizeInBits;
    long sizeInBytes;
    vector<char> data;
	string fileName;
    unsigned int partitionNumber;
    string packetName;
    _File parentFile;

	string toString();


};

