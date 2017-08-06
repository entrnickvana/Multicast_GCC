
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
	User(long cacheSize_, string name_);
	User(long cacheSize_, set<Packet>* cachedPackets_, string name_);
	~User();

	

	
	unsigned int cacheSize;
	unsigned int remainingCapacity;
	string name;
	unordered_map<string, Packet> cachedPackets;

	
	void cachePackets(vector<Packet>::iterator beginIt,  vector<Packet>::iterator endIt);
	void addPacket(Packet p);
	void removePacket(Packet* p);

};

#endif
