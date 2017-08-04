#pragma once
#include "Packet.h"
#include<string>
#include<vector>

class F_ile
{

	public:
	F_ile(string* _fileName);
	F_ile(string* _fileName, unsigned long numberOfBytes);
	F_ile(string* _fileName, unsigned long numberOfBytes, unsigned int _numOfPackets);
	~F_ile();

	string nameOfFile;
	vector<Packet> packetsOfFile;
	unsigned long numberOfBytes;
	unsigned int numOfPackets;


	void packetize(unsigned int _numOfPackets);

};