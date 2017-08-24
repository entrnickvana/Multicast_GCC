

#include "Graph.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>


using namespace std;

Graph::Graph()
{
	
}


Graph::Graph(set<Media>* files_, set<User>* users_)
{
	this->files = files_;
	this->users = users_;



}

Graph::~Graph(){}

bool Graph::addEdge(Edge* e)
{
    Edges.push_back(*e);
    return true;
}

bool Graph::addVertices(set<Vertex>* vertices)
{
	bool result = true;
	for (auto it = vertices->begin(); it != vertices->end(); ++it)
	{
		Vertex tempV = *it;
		result = result & addVertex(&tempV);
	}

	return result;
}

bool Graph::addEdges(set<Edge>* edges)
{
	bool result = true;
	for (auto it = edges->begin(); it != edges->end(); ++it)
	{
		Edge tempV = *it;
		result = result & addEdge(&tempV);

	}

	return result;
}

bool Graph::addVertex(Vertex* v)
{
    Vertices.push_back(*v);
    return true;
}

bool Graph::removeEdge(Edge* e)
{
    for(unsigned i = 0; i < Edges.size(); i++)
    {
        if(e->toString().compare(Edges[i].toString()) == 0)
        {
			Edges.erase(Edges.begin() + i);
            return true;
        }else return false;
    }

    return false;
   
}

bool Graph::removeVertex(Vertex* v)
{
    for(unsigned i = 0; i < Vertices.size(); i++)
    {
        if(v->toString().compare(Vertices[i].toString()) == 0)
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
        graphFile << "\"" + Vertices[i].name + "\"\n"; 
    }

    //Print each Edge
    for(unsigned j = 0; j < Edges.size(); j++)
    {
        graphFile << "\"" + Edges[j].toString() + "\"";
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

