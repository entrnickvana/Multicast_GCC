
#ifndef GRAPH_H
#define GRAPH_H

#include<vector>
#include "Vertex.h"
#include "Edge.h"
#include <memory>
#include "sharedPtr_CMP.h"

using namespace std;

class Simulation;
class colorFunct;

class Graph
{
    public:
    Graph();
	Graph(set<Media>* files_, set<User>* users_);
    ~Graph();

    vector<shared_ptr<Vertex>> Vertices;
    vector<shared_ptr<Edge>> Edges;
	string name;
	set<Media>* files;
	set<User>* users;

	colorFunct* colorAlgorithm;
		
	bool addVertex(shared_ptr<Vertex> v);
	bool addEdge(shared_ptr<Edge> e);
	bool addVertices(set<shared_ptr<Vertex>> vertices);
	bool addEdges(set<shared_ptr<Edge>> edges);
    bool removeEdge(shared_ptr<Edge> e);
	bool removeVertex(shared_ptr<Vertex> v);
	string mapToColor(int clr);
    void plot(string plotNumber);
	shared_ptr<User> getAssociatedUser(Vertex v);
	shared_ptr<Packet> getAssociatedPacket(Vertex v);
	bool packetsAreEquivalent(Vertex lhs, Vertex rhs);
	int	sharedEdges(shared_ptr<Vertex> begin, shared_ptr<Vertex> end);

	int edgesAmongSets(set<shared_ptr<Vertex>, sharedPtr_CMP<Vertex>> a, set<shared_ptr<Vertex>, sharedPtr_CMP<Vertex>> b);


	int colorGraph(Simulation* s1);

	long numberOfVertices;
	long numberOfEdges;
	long numberOfColors;

    private:



};




#endif


