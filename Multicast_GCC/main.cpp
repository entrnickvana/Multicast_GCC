
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
	3. change naming convention
	4. Coloring Algorithm


*/


using namespace std;

int main()
{
	

	int ratioM_div_sizeF;


	int numFiles;

	int filesPerUser;

	int numUsers;
	int numPacketsPerFile;
	int bytesPerPacket;
	int totalPackets;

	int sizeUserCacheBytes;

	vector<int> results;
	//Test Comparator

	cout << "Target values to reproduce are: \n1000 Files\n80 Users\n200 packets per file\n";

	cout << "Please enter #files" << endl;
	int nFiles;
	cin >> nFiles;

	cout << endl << "Please enter #users" << endl;
	int u;
	cin >> u;

	cout << endl << "Please enter iterations from 0 to __x___ in files per user (even numbers)" << endl;
	int iterations;
	cin >> iterations;
	cout << endl << "Please enter iteration step size (even numbers)" << endl;
	int step_size;
	cin >> step_size;
	cout << endl << "Please enter packets per file (Ensure is an even product with # of files)" << endl;
	int ppf;
	cin >> ppf;

	cout << endl << endl;





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


	

	for (int i = 1; i <= iterations; i += step_size)
	{
		cout << "@@@@@@@@  SIM: " + to_string(i) << endl;

		Simulation sim1("G_sim_" + to_string(i)); 
		Graph theGraph;

		sim1.graph = &theGraph;

		numFiles = nFiles; //1000

		filesPerUser = i;

		numUsers = u;  // 80
		numPacketsPerFile = ppf; //200
		bytesPerPacket = 64;
		totalPackets = numFiles*numPacketsPerFile;
		sizeUserCacheBytes = bytesPerPacket * numUsers * numPacketsPerFile;

		//								Packet Size		num Users		Packets/File


		// Generate |F| files, with f partitions of packets

		cout << "GenerateFiles SIM: " << i << endl << endl;

		sim1.generateFiles(numFiles,			//	Number of files to generate
			numPacketsPerFile,	//	Number of packets per file
			bytesPerPacket		//	Number of Bytes per Packet
		);


		cout << "GenerateUsers SIM: " << i << endl << endl;

		// Generate |U| users each with size M cache
		sim1.generateUsers(numUsers,			//	Number of Users
			sizeUserCacheBytes	//	Cache size per User => Packets	*	BytesPerPacket
		);


		cout << "Randomize Packets SIM: " << i << endl << endl;

		// Randomize the Set of All Packets
		sim1.randomizePackets();


		cout << "Distribute Packets SIM: " << i << endl << endl;

		//sim1.distributeMedia();
		sim1.distributeMedia(filesPerUser);

		//sim1.printFiles();
		//sim1.printUsers();

		set<pair<shared_ptr<Media>, shared_ptr<User>>> p1(sim1.request2(1));


		cout << "Map Random Requests to Vertices SIM: " << i << endl << endl;

		sim1.mapRequestsToVertices(p1);

		GC gc;

		cout << "Coloring Graph SIM: " << i << endl << endl;

		sim1.graph->colorAlgorithm = &gc;

		//sim1.graph->plot("BEFORE_COLORING_1_Today");

		results.insert(results.begin(),sim1.graph->colorGraph(&sim1));

		//sim1.graph->plot("AFTER_COLORING_1_Today");


		cout << to_string(i) << ":\tYour result: " << results.back() << endl;

	}// end for

	cout << "Size" << results.size() << endl;

	cout << "##########################################\n \t\tFINAL RESULTS \t\t\t\n";

	for(int i = 0; i < results.size(); i++)
		cout << "\t\t\t" << i + 1 << ":\t" << results.at(i) << endl;

	getchar();


}

template<typename T>
	bool ptr_less(T lhs, T rhs) {
    return std::less<decltype(*lhs)>()(*lhs, *rhs);
}