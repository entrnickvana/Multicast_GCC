#pragma once

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
        Simulation(unordered_set<Media>* mediaArg, unordered_set<User>* usersArg, string graphNameArg);
        ~Simulation();

        unordered_set<Media>* mediaPTR;
        unordered_set<User>* usersPTR;
        string graphName;
        shared_ptr<Graph> G;
		unordered_set<Packet>* setOfAllPackets;
        

        void stepForward();
        void printSimulation();
		void distributeMedia();
        



    private:


};
