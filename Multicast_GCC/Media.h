#pragma once

#include<vector>

using namespace std;

class Packet;

class Media
{

    public:

    Media();
    Media(string mediaNameArg);
    Media(string mediaNameArg, unsigned int numberOfPackets);
    string mediaName;
    vector<Packet> packetsOfMedia;

    void packetize(unsigned int numberOfPackets);
    void addPacket(Packet packetToAdd);
    bool operator<(const Media& rhs) const;
    
    private:
    


};