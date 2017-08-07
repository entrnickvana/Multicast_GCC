

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

Simulation::Simulation(string graphNameArg)
{
	graphName = graphNameArg;

}

Simulation::Simulation(set<Media>* mediaArg, set<User>* usersArg, string graphNameArg)
{
	this->mediaPTR.insert(mediaArg->begin(), mediaArg->end());
	this->usersPTR.insert(usersArg->begin(), usersArg->end());
    this->graphName = "" + graphNameArg;
	

}

Simulation::Simulation(set<Media>* mediaArg, set<User>* usersArg, string graphNameArg, int packetsPerMedia)
{
	this->mediaPTR.insert(mediaArg->begin(), mediaArg->end());
	this->usersPTR.insert(usersArg->begin(), usersArg->end());
    this->graphName = "" + graphNameArg;
	

    //if(mediaPTR->begin()->packetsOfMedia.size() == 0)
    //{

    //}

}


void Simulation::stepForward()
{
    
}

void Simulation::printSimulation()
{
	printUsers();
	printFiles();
	this->graph.plot("666");
	
}

void Simulation::printUsers()
{
	for (set<User>::iterator user_itr = usersPTR.begin(); user_itr != usersPTR.end(); ++user_itr)
	{
		cout << user_itr->name << endl << "******************" << endl;

		auto packet_itr = user_itr->cachedPackets.begin();

		for (; packet_itr != user_itr->cachedPackets.end(); ++packet_itr)
		{
			cout << packet_itr->first << "   ";
		}

		cout << endl;
	}

	cout << endl;

}

void Simulation::printFiles()
{
	for (auto files_itr = mediaPTR.begin(); files_itr != mediaPTR.end(); ++files_itr)
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
        for(set<Media>::iterator itr = mediaPTR.cbegin(); itr != mediaPTR.cend(); ++itr)
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

set<User> Simulation::generateUsers(unsigned int numberOfUsers_, unsigned int cacheSize_)
{
	set<User> tempUserSet;
	for (unsigned int i = 0; i < numberOfUsers_; i++)\
	{
		User temp(cacheSize_, "U" + to_string(i + 1));
		tempUserSet.insert(temp);
	}
	

	return tempUserSet;

}

set<Media> Simulation::generateFiles(unsigned int numberOfFiles_, unsigned int numberOfPackets, unsigned int mediaSizeInBytes_)
{

	vector<string> temp({ "A","B", "C", "D", "E", "F", "G", "H", "I","J", "K", "L", "M",
		"N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"
	});

	this->nameBuilder.insert(nameBuilder.end(), temp.begin(), temp.end());

	set<Media> tempMediaSet;


	for (unsigned int i = 0; i < numberOfFiles_; i++)
	{
		Media mTemp(temp.at(i % 26), mediaSizeInBytes_);
		mTemp.packetize(numberOfPackets);
		tempMediaSet.insert(mTemp);
	}

	return tempMediaSet;
	

}

set<Media> Simulation::generateFiles(string fileNameDirectory)
{
	set<Media> m;
	return m;
}



void Simulation::distributeMedia()
{
    unsigned int totalNumberOfPackets = setOfAllPackets.size();
    unsigned int collectiveUserCapacity = usersPTR.size() * usersPTR.begin()->cacheSize;
    unsigned int numOfUncachedPackets = totalNumberOfPackets - collectiveUserCapacity;
	this->packetsPerUser = usersPTR.begin()->cacheSize / setOfAllPackets.begin()->sizeInBytes;

	unsigned int userSubsetCounter = 0;
	unsigned int moddedCounter = 0;

	
	int counter = 0;
	
	set<User> nuUserSet;

	for(auto user_itr = usersPTR.begin(); user_itr != usersPTR.end(); ++user_itr)
	{
		User modifiedUser(*user_itr);

		for (unsigned int i = 0; i < packetsPerUser; i++)
		{
			modifiedUser.addPacket(this->randomizedPackets.at(counter++));
		}

		nuUserSet.insert(modifiedUser);
		
	}

	this->usersPTR.clear();
	usersPTR.insert(nuUserSet.begin(), nuUserSet.end());
    
}

template<typename T>
void Simulation::randomizeWithFunctor(T functor)
{


}

Simulation::~Simulation()
{

}

