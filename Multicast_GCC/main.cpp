
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

	set<Media> fileSet;
	set<User> userSet;
	

	for (int i = 65; i < 70; i++)
	{
		string temp(1,(char)i);
		
		Media f1(temp);
		fileSet.insert(f1);
		
		/*string s1

		User u1(12, );		
		User u2(12, );
		userSet.insert()

		cout << temp << endl;*/

	}

	Simulation sim1();

	getchar();

}