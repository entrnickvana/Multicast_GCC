

#include "Graph.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>


using namespace std;

Graph::Graph(){}
Graph::~Graph(){}

bool Graph::addEdge(Edge* e)
{
    Edges.push_back(*e);
    return true;
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

