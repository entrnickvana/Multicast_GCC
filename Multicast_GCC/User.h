#pragma once

#include<set>
#include<map>
#include<iterator>
#include<string>
#include "Packet.h"

using namespace std;

class User
{
public:

	User();
	~User();

	User(long _cacheSize, set<Packet> _cachedPackets);

	
	long cacheSize;
	long remainingCapacity;
	map<string, Packet> cachedPackets;


	void cachePackets(set<Packet> packetsToCache);
	void addPacket(Packet p);
	void removePacket(Packet p);

};

