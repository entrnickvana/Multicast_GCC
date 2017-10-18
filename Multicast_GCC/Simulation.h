#pragma once


//Testing source control comment
#include <set>
#include "Media.h"
#include <memory>
#include <unordered_set>
#include "Packet.h"
#include <fstream>
#include "Vertex.h"
#include "Edge.h"
using namespace std;

class Graph;

class Simulation
{
    public:

        Simulation();
		Simulation(string graphNameArg);
        Simulation(set<shared_ptr<Media>>* mediaArg, set<shared_ptr<User>>* usersArg, string graphNameArg);
        Simulation(set<shared_ptr<Media>>* mediaArg, set<shared_ptr<User>>* usersArg, string graphNameArg, int packetsPerMedia);
        ~Simulation();

        set<shared_ptr<Media>>* mediaPTR;
		set<shared_ptr<User>>* usersPTR;
        string graphName;
        Graph* graph;
        vector<Packet> setOfAllPackets;
        vector<Packet> randomizedPackets;
		unsigned int packetsPerUser;
		vector<string> nameBuilder;
		vector<pair<shared_ptr<Media>, shared_ptr<User>>> requestHistory;
		unsigned int requestNumber;
		unsigned int interferenceComparison;
		

        

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

		/*
        template<typename T>
        void randomizeWithFunctor(T functor);
		*/
		
		void distributeMedia();

		set<pair<shared_ptr<Media>, shared_ptr<User>>> request(unsigned int numOfRequests);

		set<Packet> identifyNeededPackets(pair<shared_ptr<Media>, shared_ptr<User>> requestToIdentify);

		set<shared_ptr<Vertex>> createVertices(set<Packet>* identityPackets, shared_ptr<User> requestingUser);

		shared_ptr<Vertex> createVertex(shared_ptr<Packet> identityPacket, shared_ptr<User> requestingUser);

		shared_ptr<Edge> createEdge(shared_ptr<Vertex> a, shared_ptr<Vertex> b);

		void mapRequestsToVertices(set<pair<shared_ptr<Media>, shared_ptr<User>>> requestsToMap);


        



    private:


};

//template<typename T>
//inline void Simulation::randomizeWithFunctor(T functor)
//{
//}
