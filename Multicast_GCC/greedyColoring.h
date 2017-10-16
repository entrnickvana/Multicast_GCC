#pragma once
#pragma once
#include "colorFunct.h"
#include <algorithm>
#include <memory>
#include "Simulation.h"
#include "User.h"
#include "Media.h"
#include "Vertex.h"


using namespace std;

class greedyColoring :colorFunct
{
	/*
		Algorithm 2 GCLC1
	1: Let C = ;;
	2: Let c = ;;
	3: while V 6= ; do
	4: Pick an arbitrary vertex v in V; Let I = {v};
	5: Let V0 = V \ {v};
	6: for all v0 2 V0 with Tv0 ? Tv do
	7: if {There is no edge between v0 and I} then
	8: I = I [v0;
	9: end if
	10: end for
	11: Color all the vertices in I by c /2 C;
	12: Let c[I] = c;
	13: V = V \ I.
	14: end while
	15: return maxv2V
	*/

public:
	greedyColoring() {};
	int operator()(Graph* G, Simulation* sim)
	{
		set<int> C({});
		set<int> c({});
		
		int colorDesignation = 0;

		set<Vertex> V(G->Vertices.begin(), G->Vertices.end());
		
		while(V.size() != 0)
		{
			Vertex temp_v = *V.begin();
			
			for(auto it = V.begin(); it!= V.end(); ++it)
			{
				if( (getT(temp_v, &sim->graph, sim) == getT(*it, &sim->graph, sim)) && temp_v != *it)
				{
					
				}
			}
		}
	}

	set<User> getT(Vertex vert, Graph* G, Simulation* sim)
	{
		set<User> T;
		T.insert(*vert.requestingUser.get());

		for(auto it = sim->usersPTR->begin(); it!= sim->usersPTR->end(); ++it)
		{
			unordered_map<string, Packet> temp = *it;

			auto result = temp.find(vert);

			if(it.operator==( temp.end()) != 0)
			{
				T.insert(it->get());
			}
		}

		return T;

	}
	
};