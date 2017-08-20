#pragma once


//Testing source control comment
#include<set>
#include "Media.h"
#include "Graph.h"
#include<memory>
#include<unordered_set>
#include"Packet.h"
#include<fstream>

using namespace std;


class Simulation
{
    public:

        Simulation();
		Simulation(string graphNameArg);
        Simulation(set<Media>* mediaArg, set<User>* usersArg, string graphNameArg);
        Simulation(set<Media>* mediaArg, set<User>* usersArg, string graphNameArg, int packetsPerMedia);
        ~Simulation();

        mutable set<Media> mediaPTR;
        mutable set<User> usersPTR;
        string graphName;
        Graph graph;
        vector<Packet> setOfAllPackets;
        vector<Packet> randomizedPackets;
		unsigned int packetsPerUser;
		vector<string> nameBuilder;
		vector<pair<Media, User>> requestHistory;
		

        

        void stepForward();
        void printSimulation();
		void printUsers();
		void printFiles();
		void randomizePackets();
        void randomizePackets(int numberOfPackets);
		void request();

		void generateUsers(unsigned int numberOfUsers_, unsigned int cachSize_);
		void generateFiles(unsigned int numberOfFiles_, unsigned int numberOfPackets, unsigned int mediaSizeInBytes_);
		set<Media> generateFiles(string fileNameDirectory);

        template<typename T>
        void randomizeWithFunctor(T functor);
		
		void distributeMedia();

		set<pair<Media, User>> request(unsigned int numOfRequests);

		set<Packet> identifyNeededPackets(pair<Media, User> requestToIdentify);

		set<Vertex> createVertices(set<Packet>* identityPackets, User* requestingUser);

		Vertex createVertex(Packet* identityPacket, User* requestingUser);

		set<Vertex> mapRequestsToVertices(set<pair<Media, User>> requestsToMap);
        



    private:


};

//template<typename T>
//inline void Simulation::randomizeWithFunctor(T functor)
//{
//}
