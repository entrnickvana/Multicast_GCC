#pragma once
#include "Graph.h"

using namespace std;

class colorFunct
{
    public:
    colorFunct(){};

	virtual int operator()(Graph G) {};

};
