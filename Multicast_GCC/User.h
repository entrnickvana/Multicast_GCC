#pragma once

#include<set>
#include<map>
#include<iterator>
#include<string>

class User
{
public:

	User();
	~User();

	User(long _cacheSize, set<Packet> _cachedPackets);

	
	long cacheSize;
	long remainingCapacity;
	map<string, Packet> cachedPackets;


	void cachePackets(map<string, Packet> packetsToCache);
	void addPacket(Packet p);
	void removePacket(Packet p);

};

