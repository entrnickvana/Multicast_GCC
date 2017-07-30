

#include "Graph.h";
#include <iostream>;
#include <fstream>;

using namespace std;

Graph::Graph(){}

void Graph::plot(string plotNumber)
{

    ofstream graphFile;
    string x;
    x = plotNumber;
    graphFile.open("gf" + x);
    

    //Print beginning
    graphFile << "digraph G{\n";

    //Print each vertex
    for(int i = 0; i < Vertices.size(); i++)
    {
        graphFile << "\"" + Vertices[i].name + "\"\n"; 
    }

    //Print each Edge
    for(int j = 0; j < Edges.size(); j++)
    {
        graphFile << Edges[j].toString();
    }


    graphFile.close();

    

}

