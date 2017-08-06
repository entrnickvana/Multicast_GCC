#pragma once


//Testing source control comment
#include<set>
#include "Media.h"
#include "Graph.h"
#include<memory>
#include<unordered_set>
#include"Packet.h"

using namespace std;


class Simulation
{
    public:

        Simulation();
        Simulation(set<Media>* mediaArg, set<User>* usersArg, string graphNameArg);
        Simulation(set<Media>* mediaArg, set<User>* usersArg, string graphNameArg, int packetsPerMedia);
        ~Simulation();

        mutable set<Media>* mediaPTR;
        mutable set<User>* usersPTR;
        string graphName;
        shared_ptr<Graph> G;
        mutable vector<Packet> setOfAllPackets;
        vector<Packet> randomizedPackets;
		unsigned int packetsPerUser;
        

        void stepForward();
        void printSimulation();
		void printUsers();
		void printFiles();
		void randomizePackets();
        void randomizePackets(int numberOfPackets);
		void request();

        template<typename T>
        void randomizeWithFunctor(T functor);
		
		void distributeMedia();
        



    private:


};

//template<typename T>
//inline void Simulation::randomizeWithFunctor(T functor)
//{
//}
