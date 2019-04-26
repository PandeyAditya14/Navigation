#pragma once
#include "pch.h"

class graph
{
public:
	int V, E;
	std::vector<std::pair<int, ipair>> edges;
	std::vector<int> dfs[11];
	bool visited[11];
	graph(int ver=0 , int edg=0);
	void addedge(int u, int v, int w);
	int kruskalMST();
	void caller(int s, int d);
	int dfsf(int st, int dest);
	~graph();
};

