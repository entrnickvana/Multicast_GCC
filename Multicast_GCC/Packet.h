#pragma once



class Packet
{
public:

	Packet();
	~Packet();

	long sizeInBits;
    long sizeInBytes;
    vector<byte> data;
	string fileName;
    string packetName;
    _File parentFile;


};

