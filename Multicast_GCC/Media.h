#pragma once

#include<vector>



using namespace std;

class Packet;

class Media
{

    public:

    Media();
    Media(string mediaNameArg);
    string mediaName;
    vector<Packet> packetsOfMedia;

    void packetize(unsigned int numberOfPackets);
    
    private:
    


};