#pragma once

#include<vector>
#include<set>
#include<memory>

using namespace std;

class Packet;

class Media : public enable_shared_from_this<Media>
{

    public:

    Media();
    Media(string mediaNameArg, unsigned int mediaSizeInBytes_);
    Media(string mediaNameArg, unsigned int numberOfPackets, unsigned int mediaSizeInBytes_);
    string mediaName;
    vector<Packet> packetsOfMedia;
	set<Packet> setOfPackets;
	unsigned int mediaSizeInBytes;

    void packetize(unsigned int numberOfPackets);
    void addPacket(Packet packetToAdd);
    bool operator<(const Media& rhs) const;
	bool operator>(const Media& rhs) const;
	bool operator<=(const Media& rhs) const;
	bool operator>=(const Media& rhs) const;
	bool operator==(const Media& rhs) const;
	bool operator!=(const Media& rhs) const;
    
    private:
    


};