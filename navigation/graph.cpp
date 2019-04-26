#include "pch.h"
#include "graph.h"

using namespace std;

graph::graph(int ver, int edg)
{
	this->E = edg;
	this->V = ver;
}

void graph::addedge(int u, int v, double w)
{
	edges.push_back({ w, {u, v} });
	
}


double graph::kruskalMST()
{
	double mst_wt = 0.0; // Initialize result 

   // Sort edges in increasing order on basis of cost 
	sort(edges.begin(), edges.end());

	// Create disjoint sets 
	Disjointsets ds(V);

	// Iterate through all sorted edges 
	vector< pair<double, ipair> >::iterator it;
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
			/*cout << campus[u].name << " - " <<campus[v].name << endl;
			cout << u <<" - "<< v << endl;*/
			dfs[u].push_back(v);
			dfs[v].push_back(u);

			// Update MST weight 
			mst_wt += it->first;

			// Merge two sets 
			ds.merge(set_u, set_v);
		}
		
		}
	/* for (int i = 0; i < 11; i++) {
		std::vector<int>::iterator it = dfs[i].begin();
		for (it; it < dfs[i].end(); it++)
			cout << *it;
		cout << endl;
	}*/
	//cout << visited[1];
	return mst_wt;
}

void graph::caller(int s, int d)
{
	for (int i = 0; i < 11; i++) {
		visited[i] = false;
	}
	int flag = 0;
	final.push(s);
	flag = dfsf(s, d);
}

int graph::dfsf(int st, int dest)
{
	vector<int> temp = dfs[st];
	visited[st] = true;
	
	std::vector<int>::iterator it = temp.begin();
	/*for (it; it < temp.end(); it++)
		cout << *it << "\t";
	cout << endl;*/
	int flag = 0;
	it = temp.begin();    
	for (it; it < temp.end(); it++) {
		
		final.push(*it);
	//	cout << *it;
		if (*it == dest) {
			return 1;
		}
		else if (!visited[*it]) {
			flag = dfsf(*it, dest);
		
		}

		if (flag == 1) {
			return 1;
		}
		final.pop();
	}
	
	return 0;
}

graph::~graph()
{
}
