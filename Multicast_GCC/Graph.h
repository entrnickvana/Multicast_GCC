
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

		/*
			template<typename SortFunc>
			int color(Graph g1, SortFunc colorFunc);
		*/
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
	int	sharedEdges(shared_ptr<Vertex> begin, shared_ptr<Vertex> end);

	int edgesAmongSets(set<shared_ptr<Vertex>> a, set<shared_ptr<Vertex>> b);

	long numberOfVertices;
	long numberOfEdges;
	long numberOfColors;

	/*
	template<class T>
	struct shrdPtrPred1: public binary_function(shared_ptr<T>, shared_ptr<T>, bool)
	{
		bool operator()(const T& rhs, const T& lhs)
		{
			return *rhs == *lhs;	
		}

	};

	*/


    private:



};




#endif


