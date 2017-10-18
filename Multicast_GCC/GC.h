#pragma once

#include "colorFunct.h"
#include <algorithm>
#include <memory>
#include "Simulation.h"
#include "User.h"
#include "Media.h"
#include "Vertex.h"
#include "Edge.h"
#include <algorithm>

using namespace std;

class GC:colorFunct<Graph, Simulation>{


public:
	GC(){};
	~GC(){};

	int operator()(Graph* G, Simulation* sim){

	// Construct set of all Vertices in Graph
		set<shared_ptr<Vertex>> V(G->Vertices.begin(), G->Vertices.end());
		set<shared_ptr<Vertex>> notV(V.begin(), V.end());
		// Accumulator
		set<shared_ptr<Vertex>> I;

		// Variable to enumarate "Colors"
		
		while(V.size() != 0)
		{
			// Initialize I with v
			I.clear();
			I.insert(V.begin(), ++V.begin());
			Vertex* v = *V.begin()->get;
			
			// Copy V into V', omit first element of V which represents v:    => V' = V\v
			notV.clear();
			notV.insert(++V.begin(), V.end());

			for(auto not_v_itr = notV.begin(); not_v_itr != notV.end(); ++not_v_itr)
			{

				set<User> T_not_v;
				set<User> T;

				getT(**not_v_itr, G, &T_not_v);
				getT(**not_v_itr, G, &T);

				T_not_v.insert( *((*not_v_itr)->requestingUser));
				T.insert(*(*(V.begin()))->requestingUser);

				// Compare whether v' and v have the same user sets
				if(T == T_not_v)
					if(G->edgesAmongSets(notV, I))
						I.insert(*not_v_itr);

			}// end For

			// Color vertices in I with unique "Color"
			for(auto I_color_itr = I.begin(); I_color_itr != I.end(); ++I_color_itr)
				(*I_color_itr)->color = G->numberOfColors;

			// Increment to a new unique color
			G->numberOfColors++;

			// Create a tempory placeholder for the new V, which is the difference of V and I
			set<shared_ptr<Vertex>> nu_V;

			// Compute the set difference of V - I
			auto nu_V_itr_end = set_difference(V.begin(), V.end(), I.begin(), I.end(), nu_V.begin(), shPtrPred<Vertex>);
			
			// replace the old V with the new V which has fewer vertices
			swap(V, nu_V);

		}// end While

	}

	


	

	private:

	void getT(Vertex v, Graph* G, set<User>* Tv)
	{

		// Iterate over each user within the GRAPH
		for(auto itr = G->users->begin(); itr != G->users->end(); ++itr)
		{
			// If the current user "itr" cache contains packet associated to v, add that user
			if(itr->cachedPackets.find(v.requestedPacket->packetName) != itr->cachedPackets.end())
			{
				Tv->insert(*itr);
			}

		}

	}

	template<class T>
	bool shPtrPred(const T& rhs, const T& lhs)
	{
		return *rhs == *lhs;	
	}

	

};