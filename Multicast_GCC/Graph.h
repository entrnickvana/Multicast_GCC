
#ifndef GRAPH_H
#define GRAPH_H

#include<vector>
#include "Vertex.h"
#include "Edge.h"

using namespace std;

class Graph
{
    public:
    Graph();
    ~Graph();

    vector<Vertex> Vertices;
    vector<Edge> Edges;
	string name;

	bool addVertex(Vertex* v);
	bool addEdge(Edge* e);
    bool removeEdge(Edge* e);
	bool removeVertex(Vertex* v);
    void plot(string plotNumber);


    private:



};

#endif
