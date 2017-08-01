#pragma once

#include "Vertex.h"
#include "Edge.h"


using namespace std;

class Edge
{
    public:

    Edge();
    Edge(Vertex begin_, Vertex end_);
	~Edge();

    Vertex begin;
    Vertex end;
    string toString();

    private:

};
