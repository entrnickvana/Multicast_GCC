
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


	int numFiles = 2;

	int filesPerUser = 1;

	int numUsers = 3;
	int numPacketsPerFile = 3;
	int bytesPerPacket = 64;
	int totalPackets = numFiles*numPacketsPerFile;


	int sizeUserCacheBytes =		64		*		3		*		3;
	//								Packet Size		num Users		Packets/File


	// Generate |F| files, with f partitions of packets

	sim1.generateFiles(				numFiles,			//	Number of files to generate
									numPacketsPerFile,	//	Number of packets per file
									bytesPerPacket		//	Number of Bytes per Packet
						);

	// Generate |U| users each with size M cache
	sim1.generateUsers(				numUsers,			//	Number of Users
									sizeUserCacheBytes	//	Cache size per User => Packets	*	BytesPerPacket
						);

	// Randomize the Set of All Packets
	sim1.randomizePackets();


	sim1.distributeMedia();
	//sim1.distributeMedia(1);

	sim1.printFiles();
	sim1.printUsers();

	set<pair<shared_ptr<Media>, shared_ptr<User>>> p1(sim1.request(1));

	sim1.mapRequestsToVertices(p1);

	GC gc;

	sim1.graph->colorAlgorithm = &gc;

	sim1.graph->plot("BEFORE_COLORING_1");

	int result = sim1.graph->colorGraph(&sim1);
	
	sim1.graph->plot("AFTER_COLORING_1");


	Graph gig;

	cout << "Your result: " << result << endl;

	getchar();


}

template<typename T>
	bool ptr_less(T lhs, T rhs) {
    return std::less<decltype(*lhs)>()(*lhs, *rhs);
}