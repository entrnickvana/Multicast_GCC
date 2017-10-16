
#ifndef GRAPH_H
#define GRAPH_H

#include<vector>
#include "Vertex.h"
#include "Edge.h"
#include <memory>

using namespace std;

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

	template<typename SortFunc>
	int color(Graph g1, SortFunc colorFunc);

	bool addVertex(shared_ptr<Vertex> v);
	bool addEdge(shared_ptr<Edge> e);
	bool addVertices(set<shared_ptr<Vertex>> vertices);
	bool addEdges(set<shared_ptr<Edge>> edges);
    bool removeEdge(shared_ptr<Edge> e);
	bool removeVertex(shared_ptr<Vertex> v);
    void plot(string plotNumber);
	shared_ptr<User> getAssociatedUser(Vertex v);
	shared_ptr<Packet> getAssociatedPacket(Vertex v);
	bool packetsAreEquivalent(Vertex lhs, Vertex rhs);
	long numberOfVertices;
	long numberOfEdges;


    private:



};




#endif


