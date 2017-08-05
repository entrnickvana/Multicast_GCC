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
        ~Simulation();

        set<Media>* mediaPTR;
        set<User>* usersPTR;
        string graphName;
        shared_ptr<Graph> G;
        set<Packet>* setOfAllPackets;
        

        void stepForward();
        void printSimulation();
		void distributeMedia();
        



    private:


};
