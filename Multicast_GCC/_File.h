#pragma once
#include "Packet.h"
#include<string>
#include<vector>

class _File
{
    public:
        _File();
        _File(string _fileName);
        _File(string _fileName, unsigned long numberOfBytes);
        _File(string _fileName, unsigned long numberOfBytes, unsigned int _numOfPackets);
        ~_File();

        string fileName;
        vector<Packet> packetsOfFile;
        unsigned long numberOfBytes;
        unsigned int numOfPackets;


        void packetize(unsigned int _numOfPackets);

};

