

#include<set>
#include"Media.h"
#include"User.h"
#include<string>
#include"Simulation.h"
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<random>
#include "Packet.h"
#include<iostream>

Simulation::Simulation()
{

}

Simulation::Simulation(set<Media>* mediaArg, set<User>* usersArg, string graphNameArg)
{
    this->mediaPTR = mediaArg;
    this->usersPTR = usersArg;
    this->graphName = "" + graphNameArg;
	this->G = make_shared<Graph>();

}

Simulation::Simulation(set<Media>* mediaArg, set<User>* usersArg, string graphNameArg, int packetsPerMedia)
{
    this->mediaPTR = mediaArg;
    this->usersPTR = usersArg;
    this->graphName = "" + graphNameArg;
	this->G = make_shared<Graph>();

    if(mediaPTR->begin()->packetsOfMedia.size() == 0)
    {

    }

}


void Simulation::stepForward()
{
    
}

void Simulation::printSimulation()
{
	printUsers();
	printFiles();
	this->G->plot("666");
	
}

void Simulation::printUsers()
{
	for (set<User>::iterator user_itr = usersPTR->begin(); user_itr != usersPTR->end(); ++user_itr)
	{
		cout << user_itr->name << endl << "******************" << endl;

		for (auto packet_itr = user_itr->cachedPackets.begin();
			packet_itr != user_itr->cachedPackets.end(); ++user_itr)
		{
			cout << packet_itr->first << "  ";
		}

		cout << endl;
	}

}

void Simulation::printFiles()
{
	for (auto files_itr = mediaPTR->begin(); files_itr != mediaPTR->end(); ++files_itr)
	{
		cout << files_itr->mediaName << endl << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;

		for (auto packet_itr = files_itr->packetsOfMedia.begin(); packet_itr != files_itr->packetsOfMedia.end(); ++packet_itr)
		{
			cout << packet_itr->packetName << "   ";
		}

		cout << endl;

	}

	cout << endl << endl << endl << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;

}

void Simulation::randomizePackets()
{
    //Combine All Packets

        //For every Media
        for(set<Media>::iterator itr = mediaPTR->cbegin(); itr != mediaPTR->cend(); ++itr)
        {
			setOfAllPackets.insert(setOfAllPackets.end(), itr->packetsOfMedia.begin(), itr->packetsOfMedia.end());
        }

		sort(setOfAllPackets.begin(), setOfAllPackets.end());

		vector<Packet> nuRandomizedSetOfPackets(setOfAllPackets);

		random_shuffle(nuRandomizedSetOfPackets.begin(), nuRandomizedSetOfPackets.end());

		this->randomizedPackets.insert(randomizedPackets.end(), nuRandomizedSetOfPackets.begin(), nuRandomizedSetOfPackets.end());


}

void Simulation::randomizePackets(int numberOfPackets)
{


}

void Simulation::request()
{



}

void Simulation::distributeMedia()
{
    unsigned int totalNumberOfPackets = setOfAllPackets.size();
    unsigned int collectiveUserCapacity = usersPTR->size() * usersPTR->begin()->cacheSize;
    unsigned int numOfUncachedPackets = totalNumberOfPackets - collectiveUserCapacity;
	this->packetsPerUser = usersPTR->begin()->cacheSize / setOfAllPackets.begin()->sizeInBytes;

	unsigned int userSubsetCounter = 0;
	unsigned int moddedCounter = 0;

	vector<User> temp(usersPTR->begin(), usersPTR->end());

	for(vector<User>::iterator user_itr = temp.begin(); user_itr != temp.end(); ++user_itr)
	{
		for(unsigned int k = 0; k < packetsPerUser; k++)
		{
			user_itr->addPacket(randomizedPackets.at(userSubsetCounter++));

		}

	}
    
}

template<typename T>
void Simulation::randomizeWithFunctor(T functor)
{


}

Simulation::~Simulation()
{

}

