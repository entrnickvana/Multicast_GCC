
#include<iostream>
#include<string>
#include "Vertex.h"
#include "Edge.h"
#include "Graph.h"
#include "Media.h"
#include<set>


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

	Media B("B", 100);
	cout << B.packetsOfMedia.size() << endl;

	Media A("A", 20);
	cout << A.packetsOfMedia.size() << endl;

	set<Packet> basicSet;

	basicSet.insert(A.packetsOfMedia.begin(), A.packetsOfMedia.end());
	basicSet.insert(B.packetsOfMedia.begin(), B.packetsOfMedia.end());


	/*for (unsigned int i = 0; i < A.packetsOfMedia.size(); i++)
	{
		basicSet.insert((B.packetsOfMedia.at(i)));
		basicSet.insert(A.packetsOfMedia.at(i));
	}*/

	cout << basicSet.size() << endl;


	for(set<Packet>::iterator itr = basicSet.begin(); itr != basicSet.end(); ++itr)
	{
		cout << itr->packetName << endl;
	}

	
	//Media C("C", 12);

	//
	//
	//Graph G();





	getchar();

}