

#include "Simulation.h"
#include "Graph.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include "colorFunct.h"
#include "sharedPtr_CMP.h"


using namespace std;

Graph::Graph()
{
	
}


Graph::Graph(set<Media>* files_, set<User>* users_)
{
	this->files = files_;
	this->users = users_;
    this->numberOfColors = 0;

}

Graph::~Graph(){}

bool Graph::addEdge(shared_ptr<Edge> e)
{
    Edges.push_back(e);
	e->begin->adj.push_front(e);
    return true;
}

bool Graph::addVertices(set<shared_ptr<Vertex>> vertices)
{
	bool result = true;
	for (auto it = vertices.begin(); it != vertices.end(); ++it)
	{
		result = result & addVertex(*it);
	}

	return result;
}

bool Graph::addEdges(set<shared_ptr<Edge>> edges)
{
	bool result = true;
	for (auto it = edges.begin(); it != edges.end(); ++it)
	{
		result = result & addEdge(*it);

	}

	return result;
}

bool Graph::addVertex(shared_ptr<Vertex> v)
{
    Vertices.push_back(v);
    return true;
}

bool Graph::removeEdge(shared_ptr<Edge> e)
{
    for(unsigned i = 0; i < Edges.size(); i++)
    {

        
        if(e->getIdentity().compare(Edges[i]->getIdentity()) == 0)
        {
			Edges.erase(Edges.begin() + i);
            return true;

        }else return false;

    }

    return false;
   
}

bool Graph::removeVertex(shared_ptr<Vertex> v)
{
    for(unsigned i = 0; i < Vertices.size(); i++)
    {
        if(v->toString().compare(Vertices[i]->toString()) == 0)
        {
            Vertices.erase(Vertices.begin() + i);
            return true;
        }else return false;
        
    }
    return false;
}



void Graph::plot(string plotNumber)
{

    ofstream graphFile;
    string x = plotNumber;
    graphFile.open("gf" + x + ".txt");
    

    //Print beginning
    graphFile << "digraph G{\n";

    //Print each vertex
    for(unsigned i = 0; i < Vertices.size(); i++)
    {
        graphFile << "\"" + Vertices[i]->name + "\"\n"; 
    }

    //Print each Edge
    for(unsigned j = 0; j < Edges.size(); j++)
    {

        graphFile << "\"" + Edges[j]->getIdentity() + "\"\n";
    }

/*  The more efficient traversal of a vector
    for(vector<Edge>::iterator itr = Edges.begin(); itr != Edges.end(); ++itr)
    {
        graphFile << "\"" + ((Edge)itr)->toString() + "\"";

    }
*/

    graphFile << "}";
    
    graphFile.close();

}

shared_ptr<User> Graph::getAssociatedUser(Vertex v)
{
	return  v.requestingUser;
}

shared_ptr<Packet> Graph::getAssociatedPacket(Vertex v)
{
	return v.requestedPacket;
}

bool Graph::packetsAreEquivalent(Vertex lhs, Vertex rhs)
{
	// Compare the string name given to the identifying packet of each vertex
	bool cond1 = lhs.requestedPacket->packetName.compare(rhs.requestedPacket->packetName) < 0;

	// Compare the string name given to the user requesting the identifying packet
	bool cond2 = lhs.requestingUser->name.compare(rhs.requestingUser->name) < 0;

	return cond1 && cond2;


}

int Graph::sharedEdges(shared_ptr<Vertex> begin, shared_ptr<Vertex> end)
{
    list<shared_ptr<Edge>>* begEdges = &begin->adj;
    list<shared_ptr<Edge>>* endEdges = &end->adj;

            //Does begin have an edge pointing to end
    for (auto beg_itr = begEdges->begin(); beg_itr != begEdges->end(); ++beg_itr)
    {
        if(*begin == *((*beg_itr)->begin) && *end == *((*beg_itr)->end))
            return 1;
    }

    for (auto end_itr = endEdges->begin(); end_itr != endEdges->end(); ++end_itr)
    {
        if(*end == *((*end_itr)->begin) && *begin == *((*end_itr)->end))
            return -1;
    }

	return 0;
}

int Graph::edgesAmongSets(set<shared_ptr<Vertex>, sharedPtr_CMP<Vertex>> a, set<shared_ptr<Vertex>, sharedPtr_CMP<Vertex>> b)
{
    int result_accumulator = 0;
    for(auto a_itr = a.begin(); a_itr != a.end(); ++a_itr)
        for(auto b_itr = b.begin(); b_itr != b.end(); ++b_itr)
            if(sharedEdges(*a_itr, *b_itr) != 0)
                return 1;
}

int Graph::colorGraph(Simulation* s1)
{
	return this->colorAlgorithm->operator()(this,s1);
}


template<typename SortFunc>
int Graph::color(Graph g1, SortFunc colorFunc)
{
	return 0;
}

