

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
    
    
}

Simulation::~Simulation()
{

}

