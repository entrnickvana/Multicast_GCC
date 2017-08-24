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

User::User(long cacheSize_, string name_)
{
	cacheSize = cacheSize_;
	name = name_;

}


User::~User()
{
}

User::User(long cacheSize_, set<Packet>* cachedPackets_, string name_)
{
    cacheSize = cacheSize_;
    remainingCapacity = cacheSize - (cachedPackets_->size()*(cachedPackets_->begin()->sizeInBytes));
	name = name_;


	for (set<Packet>::iterator itr = cachedPackets_->begin(); itr != cachedPackets_->end(); ++itr)
	addPacket(*itr);

    /*  The more efficient traversal of a vector
    for(vector<Edge>::iterator itr = Edges.begin(); itr != Edges.end(); ++itr)
    {
        graphFile << "\"" + ((Edge)itr)->toString() + "\"";

    }
*/


}

bool User::operator<(const User & rhs) const
{
	return this->name.compare(rhs.name) < 0;
}

bool User::operator>(const User & rhs) const
{
	return !(rhs < *this);
}

bool User::operator<=(const User & rhs) const
{
	return !(*this > rhs);
}

bool User::operator>=(const User & rhs) const
{
	return !(*this < rhs);
}

bool User::operator==(const User & rhs) const
{
	return this->name.compare(rhs.name) == 0;
}

bool User::operator!=(const User & rhs) const
{
	return !(*this == rhs);
}

void User::cachePackets(vector<Packet>::iterator beginIt, vector<Packet>::iterator endIt)
{



}

void User::addPacket(Packet p)
{
    
    cachedPackets.insert(make_pair(p.packetName, p));
	remainingCapacity = remainingCapacity - p.sizeInBytes;

}

void User::removePacket(Packet* p)
{



}