
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
	bool addVertices(set<Vertex>* vertices);
	bool addEdges(set<Edge>* edges);
    bool removeEdge(Edge* e);
	bool removeVertex(Vertex* v);
    void plot(string plotNumber);
	shared_ptr<User> getAssociatedUser(Vertex v);
	shared_ptr<Packet> getAssociatedPacket(Vertex v);
	bool packetsAreEquivalent(Vertex lhs, Vertex rhs);
	long numberOfVertices;
	long numberOfEdges;


    private:



};

#endif
