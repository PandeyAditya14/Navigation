#include "pch.h"
#include "graph.h"

using namespace std;

graph::graph(int ver, int edg)
{
	this->E = edg;
	this->V = ver;
}

void graph::addedge(int u, int v, int w)
{
	edges.push_back({ w, {u, v} });
}


int graph::kruskalMST()
{
	int mst_wt = 0; // Initialize result 

   // Sort edges in increasing order on basis of cost 
	sort(edges.begin(), edges.end());

	// Create disjoint sets 
	Disjointsets ds(V);

	// Iterate through all sorted edges 
	vector< pair<int, ipair> >::iterator it;
	for (it = edges.begin(); it != edges.end(); it++)
	{
		int u = it->second.first;
		int v = it->second.second;

		int set_u = ds.find(u);
		int set_v = ds.find(v);

		// Check if the selected edge is creating 
		// a cycle or not (Cycle is created if u 
		// and v belong to same set) 
		if (set_u != set_v)
		{
			// Current edge will be in the MST 
			// so print it 
			cout << campus[u].name << " - " <<campus[v].name << endl;
			cout << u <<" - "<< v << endl;

			// Update MST weight 
			mst_wt += it->first;

			// Merge two sets 
			ds.merge(set_u, set_v);
		}
	}

	return mst_wt;
}

graph::~graph()
{
}
