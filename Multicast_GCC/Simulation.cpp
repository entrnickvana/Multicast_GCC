

#include<set>
#include"Media.h"
#include"User.h"
#include<string>
#include"Simulation.h"
#include<unordered_set>

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


void Simulation::stepForward()
{
    
}

void Simulation::printSimulation()
{
    
}

void Simulation::distributeMedia()
{
    
    for(set<Media>::iterator media_itr = mediaPTR->begin(); media_itr !=mediaPTR->end(); ++media_itr)
    {
		this->setOfAllPackets->insert(media_itr->packetsOfMedia.begin(),media_itr->packetsOfMedia.end());
    }
}

Simulation::~Simulation()
{

}

