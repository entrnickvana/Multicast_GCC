
#include<iostream>
#include<string>
#include "Vertex.h"
#include "Edge.h"
#include "Graph.h"
#include "Media.h"
#include<set>
#include<algorithm>
#include<random>
#include<unordered_set>
#include<vector>
#include "Simulation.h"

/*
	Left to do
	1. Simulation class
	2. Random distribution of packets
	3.
	4. Coloring Algorithm


*/


using namespace std;

int main()
{

	Simulation sim1("G_CODE");

	sim1.mediaPTR = sim1.generateFiles(3,16,256);
	sim1.usersPTR = sim1.generateUsers(6, 64);
	sim1.randomizePackets();
	sim1.distributeMedia();
	sim1.printFiles();
	sim1.printUsers();




	getchar();

}