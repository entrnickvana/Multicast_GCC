

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
#include<random>
#include<memory>
#include<cstdlib>
#include<ctime>



Simulation::Simulation()
{
	
}

Simulation::Simulation(string graphNameArg)
{
	graphName = graphNameArg;
	this->mediaPTR = new set<shared_ptr<Media>>();
	this->usersPTR = new set<shared_ptr<User>>();

}

Simulation::Simulation(set<shared_ptr<Media>>* mediaArg, set<shared_ptr<User>>* usersArg, string graphNameArg)
{
	this->mediaPTR->insert(mediaArg->begin(), mediaArg->end());
	this->usersPTR->insert(usersArg->begin(), usersArg->end());
    this->graphName = "" + graphNameArg;
	

}

Simulation::Simulation(set<shared_ptr<Media>>* mediaArg, set<shared_ptr<User>>* usersArg, string graphNameArg, int packetsPerMedia)
{
	this->mediaPTR->insert(mediaArg->begin(), mediaArg->end());
	this->usersPTR->insert(usersArg->begin(), usersArg->end());
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
	for (set<shared_ptr<User>>::iterator user_itr = usersPTR->begin(); user_itr != usersPTR->end(); ++user_itr)
	{
		cout << user_itr->get()->name << endl << "******************" << endl;


		auto packet_itr = user_itr->get()->cachedPackets.begin();

		for (; packet_itr != user_itr->get()->cachedPackets.end(); ++packet_itr)
		{
			cout << packet_itr->first << "   ";
		}

		cout << endl << endl;
	}

	cout << endl;

}

void Simulation::printFiles()
{
	for (auto files_itr = mediaPTR->begin(); files_itr != mediaPTR->end(); ++files_itr)
	{
		cout << files_itr->get()->mediaName << endl << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;

		for (auto packet_itr = files_itr->get()->packetsOfMedia.begin(); packet_itr != files_itr->get()->packetsOfMedia.end(); ++packet_itr)
		{
			cout << packet_itr->packetName << "   ";
		}

		cout << endl << endl;

	}

	cout << endl << endl << endl << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;

}

void Simulation::randomizePackets()
{
    //Combine All Packets

        //For every Media
        for(set<shared_ptr<Media>>::iterator itr = mediaPTR->begin(); itr != mediaPTR->end(); ++itr)
        {
			setOfAllPackets.insert(setOfAllPackets.begin(), itr->get()->packetsOfMedia.begin(), itr->get()->packetsOfMedia.end());
        }

		vector<Packet> nuRandomizedSetOfPackets(setOfAllPackets.begin(), setOfAllPackets.end());

		random_shuffle(nuRandomizedSetOfPackets.begin(), nuRandomizedSetOfPackets.end());

		this->randomizedPackets.insert(randomizedPackets.end(), nuRandomizedSetOfPackets.begin(), nuRandomizedSetOfPackets.end());


}

void Simulation::randomizePackets(int numberOfPackets)
{


}

void Simulation::request()
{



}

void Simulation::generateUsers(unsigned int numberOfUsers_, unsigned int cacheSize_)
{
	for (unsigned int i = 0; i < numberOfUsers_; i++)\
	{
		shared_ptr<User> temp = make_shared<User>(cacheSize_, "U" + to_string(i + 1));
		this->usersPTR->insert(temp);
	}

}

void Simulation::generateFiles(unsigned int numberOfFiles_, unsigned int numberOfPackets, unsigned int mediaSizeInBytes_)
{

	vector<string> temp({ "A","B", "C", "D", "E", "F", "G", "H", "I","J", "K", "L", "M",
		"N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"
	});

	this->nameBuilder.insert(nameBuilder.end(), temp.begin(), temp.end());




	for (unsigned int i = 0; i < numberOfFiles_; i++)
	{
		/*Media mTemp(temp.at(i % 26), mediaSizeInBytes_);
		mTemp.packetize(numberOfPackets);
		this->mediaPTR.insert(mTemp);*/

		//Create media object

		// Instantiate shared_ptr with copy constuctor of media object
		
		shared_ptr<Media> mPtr = make_shared<Media>(temp.at(i % 26), mediaSizeInBytes_);
		mPtr->packetize(numberOfPackets);
		mediaPTR->insert(mPtr);

		/*Media mTemp(temp.at(i % 26), mediaSizeInBytes_);
		tempMediaVec.push_back(mTemp);
		tempMediaVec.back().packetize(numberOfPackets);*/

	}
	

}

set<Media> Simulation::generateFiles(string fileNameDirectory)
{
	set<Media> m;
	return m;
}



void Simulation::distributeMedia()
{
    unsigned int totalNumberOfPackets = setOfAllPackets.size();
    unsigned int collectiveUserCapacity = usersPTR->size() * usersPTR->begin()->get()->cacheSize;
    unsigned int numOfUncachedPackets = totalNumberOfPackets - collectiveUserCapacity;

	// Can we distrubute the packets uniquely among each user

	// If not, 



	this->packetsPerUser = totalNumberOfPackets / usersPTR->size();

	if (this->packetsPerUser < 1)
		this->packetsPerUser = 1;

	unsigned int userSubsetCounter = 0;
	unsigned int moddedCounter = 0;

	
	int counter = 0;
	
	set<shared_ptr<User>> nuUserSet;

	for(auto user_itr = usersPTR->begin(); user_itr != usersPTR->end(); ++user_itr)
	{
		shared_ptr<User> modifiedUser = *user_itr;

		for (unsigned int i = 0; i < packetsPerUser; i++)
		{
			modifiedUser->addPacket(this->randomizedPackets.at(counter++));
		}

		nuUserSet.insert(modifiedUser);
		
	}

	this->usersPTR->clear();
	usersPTR->insert(nuUserSet.begin(), nuUserSet.end());
    
}

set<pair<shared_ptr<Media>, shared_ptr<User>>> Simulation::request(unsigned int numOfRequests)
{
	srand(0);
	set<pair<shared_ptr<Media>, shared_ptr<User>>> pairsToRequest;  //(pairCMP);

	int tempIndex1;
	int tempIndex2;

	cout << "/////////////////      REQUEST #" << requestNumber << "      ////////////////////////" << endl << endl;



	for (unsigned int i = 0; i < numOfRequests; i++)
	{
		
		tempIndex1 = rand() % usersPTR->size();	
		tempIndex2 = rand() % mediaPTR->size();
		vector<shared_ptr<User>> users(usersPTR->begin(), usersPTR->end());
		vector<shared_ptr<Media>> media(mediaPTR->begin(), mediaPTR->end());


		pair<shared_ptr<Media>, shared_ptr<User>> pTemp(media.at(tempIndex2), users.at(tempIndex1));
		
		cout << pTemp.second.get()->name << " requests " << pTemp.first.get()->mediaName << "   ";

		pairsToRequest.insert(pTemp);

		requestNumber++;

	}

	cout << endl << endl;
	
	this->requestHistory.insert(requestHistory.end(),pairsToRequest.begin(), pairsToRequest.end());


	return pairsToRequest;
}

set<Packet> Simulation::identifyNeededPackets(pair<shared_ptr<Media>, shared_ptr<User>> requestToIdentify)
{
	
	set<Packet> usrPackets;
	for (const auto& pair : requestToIdentify.second.get()->cachedPackets)
	{
		if (pair.second.parentMedia->mediaName.compare(requestToIdentify.first.get()->mediaName) == 0)
		{
			usrPackets.insert(pair.second);
		}
	}

	set<Packet> filePackets(requestToIdentify.first.get()->packetsOfMedia.begin(), requestToIdentify.first.get()->packetsOfMedia.end());

	vector<Packet> neededPackets(filePackets.size());
	vector<Packet>::iterator itr;

	itr = set_difference(filePackets.begin(), filePackets.end(), usrPackets.begin(), usrPackets.end(), neededPackets.begin());

	neededPackets.resize(itr - neededPackets.begin());

	set<Packet> s(neededPackets.begin(), neededPackets.end());

	return s;
	/*set<Packet> localPackets;
	set<Packet> requestedPackets;

	Media tmpFile(requestToIdentify.first);

	User tmpUsr(requestToIdentify.second);


	for (auto pcktItr = tmpUsr.cachedPackets.begin(); pcktItr != tmpUsr.cachedPackets.end(); ++pcktItr)
	{
		Packet pTemp(pcktItr->second);

		for (auto otherPacketItr = tmpUsr.cachedPackets.begin(); otherPacketItr != tmpUsr.cachedPackets.end(); ++otherPacketItr)
		{
			if ((*pTemp.parentMedia == tmpFile) && (pTemp.partitionNumber != otherPacketItr->second.partitionNumber))
			{
				localPackets.insert(otherPacketItr->second);
			}

		}

	}

	auto inItr3 = localPackets.begin()->parentMedia->setOfPackets.begin();
	auto inItr4 = localPackets.begin()->parentMedia->setOfPackets.end();

	set_difference(localPackets.begin(), localPackets.end(), inItr3, inItr4, requestedPackets.begin());

	return requestedPackets;*/

}

set<shared_ptr<Vertex>> Simulation::createVertices(set<Packet>* identityPackets, shared_ptr<User> requestingUser)
{
	set<shared_ptr<Vertex>> nuVertices;
	Packet tempPckt;

	for (auto packetItr = identityPackets->begin(); packetItr != identityPackets->end(); ++packetItr)
	{
		shared_ptr<Packet> tempPckt = make_shared<Packet>(*packetItr);
		nuVertices.insert(createVertex(tempPckt, requestingUser));
	}

	return nuVertices;
}


shared_ptr<Vertex> Simulation::createVertex(shared_ptr<Packet> identityPacket, shared_ptr<User> requestingUser)
{

	shared_ptr<Vertex> v = make_shared<Vertex>(identityPacket, requestingUser, this->graph.numberOfVertices++);


	return v;
}

shared_ptr<Edge> Simulation::createEdge(shared_ptr<Vertex> a, shared_ptr<Vertex> b)
{

	return make_shared<Edge>(a, b);
}


void Simulation::mapRequestsToVertices(set<pair<shared_ptr<Media>, shared_ptr<User>>> requestsToMap)
{
	//set<Packet> neededPackets;
	//set<shared_ptr<Vertex>> verticesToAddToGraph;
	unordered_map<string, Packet>::iterator it;

	//Iterate through each user
	for (auto reqItr = requestsToMap.begin(); reqItr != requestsToMap.end(); ++reqItr)
	{

		shared_ptr<User> u = reqItr->second;
		const pair<shared_ptr<Media>, shared_ptr<User>> pr = *reqItr;

		set<Packet> neededPackets(identifyNeededPackets(pr));

		//Insert All Vertices

		this->graph.addVertices(createVertices(&neededPackets, u));
	}

	cout << "/////////////////////// Interference Comparison ////////////////" << endl << endl;



	//Iterate over each user to check whether there should be an edge
	for (auto vItr = this->graph.Vertices.begin(); vItr != this->graph.Vertices.end(); ++vItr)
	{
		Vertex current = *vItr->get();

		for (auto otherItr = graph.Vertices.begin(); otherItr != graph.Vertices.end(); ++otherItr)
		{
			Vertex otherVertex = *otherItr->get();
			if (otherVertex.name.compare( current.name) != 0)
			{
				it = otherVertex.requestingUser->cachedPackets.find(current.requestedPacket->packetName);

				if (it == otherVertex.requestingUser->cachedPackets.end())
				{
					cout << otherVertex.name << "->" << current.name << endl;
					this->graph.addEdge(createEdge(*otherItr, *vItr));
				}

			}

		}

		

	}



	/*  ////////////////  Description of Graph Construction and Definition  /////////////////////////

	// Vertex = (PACKET IDENTITY OF VERTEX, USER REQUETING PACKET)
	//        = (GET_PACKET_IDENTITY, GET_REQUESTING_USER)
	//		  = (p(v), u(v)) where p(v) computes packet from vertex v element of V, u(v) computes user v element V

	// Steps for constructing graph

	// Each vertex is an abstraction composed of the pair(Packet, User Requesting Packet)

	// An edge is an abstraction composed of the pair (v_1, v_2) where v_1, v_2 are unique elements in V

	An edge is add to the Graph G which is compose of the (V,E)  if

	1. v_1 is not in the cache of the user associated to v_2 by u(v)

	2. v_1 and v_2 do not represent the same packet

	///////////  Steps  ////////////////

	1. Requests are placed

	2. Given set of (File, User) pairs which are the raw materials for determinging actual packet requests

	3. Iterate through each given User

	//For

	4. Access u_i local cached packets, to determin local subset of packets

	5. Access full set of packets belonging to requested file through pointer

	6. Subtract local from complete set

	7.



	*/
}

template<typename T>
void Simulation::randomizeWithFunctor(T functor)
{


}

Simulation::~Simulation()
{

}

