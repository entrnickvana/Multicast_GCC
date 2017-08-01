
#include<iostream>
#include<string>
#include "Vertex.h"
#include "Edge.h"
#include "Graph.h"

using namespace std;

int main()
{

	Graph G;
	
	Vertex VA1, VA2, VA3, VA4;

	

	VA1.color = 1;  VA1.name = "VA1";
	VA2.color = 2;  VA2.name = "VA2";
	VA3.color = 3;	VA3.name = "VA3";
	VA4.color = 4;  VA4.name = "VA4";

	G.addVertex(VA1);
	G.addVertex(VA2);
	
	Edge* E1 = new Edge(VA1, VA2);

	G.addEdge(*E1);

	G.plot("GraphColoring1");

	delete E1;

	getchar();

	

	return 0;

}