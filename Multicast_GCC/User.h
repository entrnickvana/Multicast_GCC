
#ifndef USER_H
#define USER_H

#include<set>
#include<unordered_map>
#include<iterator>
#include<string>
#include "Packet.h"

using namespace std;

class User
{
public:

	User();
	User(long cacheSize_, set<Packet>* cachedPackets_);
	~User();

	

	
	long cacheSize;
	long remainingCapacity;
	unordered_map<string, Packet> cachedPackets;


	void cachePackets(set<Packet>* packetsToCache);
	void addPacket(Packet p);
	void removePacket(Packet* p);

};

#endif
