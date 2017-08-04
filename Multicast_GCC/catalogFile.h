
#ifndef CATALOGFILE_H
#define CATALOGFILE_H


#include"Packet.h"
#include<string>
#include<vector>

class catalogFile
{

public:
	catalogFile();
//	catalogFile(string* _fileName);
//	catalogFile(string* _fileName, unsigned long numberOfBytes);
	//catalogFile(string* _fileName, unsigned long numberOfBytes, unsigned int _numOfPackets);
	~catalogFile();

	//string nameOfFile;
	vector<Packet> packetsOfFile;
	unsigned long numberOfBytes;
	unsigned int numOfPackets;


	void packetize(unsigned int numOfPackets);

private:

};

#endif // !CATALOGFILE_H

