#pragma once

#include<vector>

using namespace std;

class Packet;

class Media
{

    public:

    Media();
    Media(string mediaNameArg, unsigned int mediaSizeInBytes_);
    Media(string mediaNameArg, unsigned int numberOfPackets, unsigned int mediaSizeInBytes_);
    string mediaName;
    vector<Packet> packetsOfMedia;
	unsigned int mediaSizeInBytes;

    void packetize(unsigned int numberOfPackets);
    void addPacket(Packet packetToAdd);
    bool operator<(const Media& rhs) const;
    
    private:
    


};