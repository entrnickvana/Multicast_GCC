#pragma once
#include "Graph.h"
#include "Simulation.h"

using namespace std;


class colorFunct
{
    public:
    virtual ~colorFunct(){};

	virtual int operator()(Graph* G, Simulation* s) { return 0; };

	private:

};
