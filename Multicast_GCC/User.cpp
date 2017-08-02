#include "User.h"
#include "Packet.h"
#include "_File.h"
#include<string>
#include<iterator>


User::User()
{
    cacheSize = 0;
    remainingCapacity = 0;
}


User::~User()
{
}

User(long _cacheSize, set<Packet> _cachedPackets)
{
    cacheSize = _cacheSize;
    cachedPackets = _cachedPackets;
    remainingCapacity = cacheSize - ( _cachedPackets.size()*(_cachedPackets.begin().sizeInBytes));
}

void User::cachePackets(map<string, Packet> packetsToCache)
{



}

void User::addPacket(Packet p)
{
    if(remainingCapcity >= p.sizeInBytes)
    cachedPackets.insert(p);

}

void User::removePacket(Packet p)
{



}