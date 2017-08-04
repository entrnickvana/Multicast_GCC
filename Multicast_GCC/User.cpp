#include "User.h"
#include "Packet.h"
//#include "catalogFile.h"
#include<string>
#include<iterator>
#include<unordered_map>
#include<utility>

User::User()
{
    cacheSize = 0;
    remainingCapacity = 0;
}


User::~User()
{
}

User::User( long cacheSize_, set<Packet>* cachedPackets_)
{
    cacheSize = cacheSize_;
    remainingCapacity = cacheSize - (cachedPackets_->size()*(cachedPackets_->begin()->sizeInBytes));


    for(set<Packet>::iterator itr = cachedPackets_->begin(); itr != cachedPackets_->end(); ++itr)
	addPacket(*itr);

    /*  The more efficient traversal of a vector
    for(vector<Edge>::iterator itr = Edges.begin(); itr != Edges.end(); ++itr)
    {
        graphFile << "\"" + ((Edge)itr)->toString() + "\"";

    }
*/


}

void User::cachePackets(set<Packet>* packetsToCache)
{



}

void User::addPacket(Packet p)
{
    if(remainingCapacity >= p.sizeInBytes)
    cachedPackets.insert(make_pair(p.packetName, p));
	remainingCapacity = remainingCapacity - p.sizeInBytes;

}

void User::removePacket(Packet* p)
{



}