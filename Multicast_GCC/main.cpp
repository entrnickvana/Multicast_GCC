
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
#include<memory>
#include "mCMP.h"

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
	

	//Test Comparator


	//shared_ptr<Media> A = make_shared<Media>("A", 128);
	//shared_ptr<Media> B = make_shared<Media>("B", 128);
	//shared_ptr<Media> C = make_shared<Media>("C", 128);
	//shared_ptr<Media> D = make_shared<Media>("D", 128);

	//set<shared_ptr<Media>, mCMP<Media>> mediaSet;

	//mediaSet.insert(C);
	//mediaSet.insert(A);
	//mediaSet.insert(D);
	//mediaSet.insert(B);

	//for (auto const& entry : mediaSet)
	//{
	//	cout << entry->mediaName << endl;
	//}


	Simulation sim1("G_CODE");

	sim1.generateFiles(3,16,256);
	sim1.generateUsers(6, 64);
	sim1.randomizePackets();
	sim1.distributeMedia();
	sim1.printFiles();
	sim1.printUsers();

	set<pair<shared_ptr<Media>, shared_ptr<User>>> p1(sim1.request(4));

	sim1.mapRequestsToVertices(p1);


	Graph gig;



	getchar();

}