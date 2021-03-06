
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
	Graph(set<Media>* files_, set<User>* users_);
    ~Graph();

    vector<Vertex> Vertices;
    vector<Edge> Edges;
	string name;
	set<Media>* files;
	set<User>* users;

	bool addVertex(Vertex* v);
	bool addEdge(Edge* e);
    bool removeEdge(Edge* e);
	bool removeVertex(Vertex* v);
    void plot(string plotNumber);
	User* getAssociatedUser(Vertex v);
	Packet* getAssociatedPacket(Vertex v);
	bool packetsAreEquivalent(Vertex lhs, Vertex rhs);
	long numberOfVertices;
	long numberOfEdges;


    private:



};

#endif
