#pragma once
#include "Packet.h"
#include<string>
#include<vector>


class _File
{
    public:

        _File();
        _File(unsigned long numberBytes);
        _File(unsigned long numberBytes, unsigned int numOfPackets);
        ~_File();

        string fileName;
        vector<Packet> packetsOfFile;

        void packetize(unsigned int numOfPackets);

};

