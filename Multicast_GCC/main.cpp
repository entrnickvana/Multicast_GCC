
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
#include "colorFunct.h"
#include "GC.h"

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
	Graph theGraph;

	sim1.graph = &theGraph;

	int ratioM_div_sizeF = 0;

	int numFiles = 6;
	int numPacketsPerFile = 4;
	int bytesPerPacket = 64;
	int totalPackets = numFiles*numPacketsPerFile;
	int sizeUserCacheBytes = 64*8*4;



	// Generate 4 Files, divided into 4 Packets each, of 128 bytes per file
	sim1.generateFiles(numFiles,numPacketsPerFile,bytesPerPacket);

	// Generate 3 Users, each with a cache size M = 512 bytes
	sim1.generateUsers(8, sizeUserCacheBytes);

	// Randomize the distribution of packeBytes
	sim1.randomizePackets();

	// 
	sim1.distributeMedia();
	sim1.printFiles();
	sim1.printUsers();

	set<pair<shared_ptr<Media>, shared_ptr<User>>> p1(sim1.request(4));

	sim1.mapRequestsToVertices(p1);

	GC gc;

	sim1.graph->colorAlgorithm = &gc;

	int result = sim1.graph->colorGraph(&sim1);
	
	sim1.graph->plot("gizzle");
	

	Graph gig;

	cout << "Your result: " << result << endl;

	getchar();


}

template<typename T>
	bool ptr_less(T lhs, T rhs) {
    return std::less<decltype(*lhs)>()(*lhs, *rhs);
}