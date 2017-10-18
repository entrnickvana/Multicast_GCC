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

class GC:colorFunct{


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
		int Colors = 0;
		int numberOfColors = 0;

		while(V.size() != 0)
		{
			// Initialize I with v
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
				{

					// If there are no edges between v and v', then add v' to I

					// Iterators for v'
					auto enot_v = (*not_v_itr)->adj.begin();
					auto enot_v_end = (*not_v_itr)->adj.end();

					// Iterators for I
					for (auto I_itr = I.begin(); I_itr != I.end(); ++I_itr)
					{

						auto ev = (*I_itr)->adj.begin();
						auto ev_end = (*I_itr)->adj.end();

						has_edges_itr1 = find(enot_v, enot_v_end,  +"\"" + " -> " + "\"" + (*not_v_itr)->name);
						has_edges_itr2 = find

						if (has_edges_itr1 == enot_v_end && has_edges_itr2 == ev_end)
						{


						}

					}


					//(*begin).name + "\"" + " -> " + "\"" + (*end).name
				}

			

			}

		}

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
	struct shrdPtrPred: public binary_function(shared_ptr<T>, shared_ptr<T>, bool)
	{
		bool operator()(const T& rhs, const T& lhs)
		{
			return *rhs == *lhs;	
		}

	};

};