#pragma once
#include "pch.h"

class graph
{
public:
	int V, E;
	std::vector<std::pair<int, ipair>> edges;
	graph(int ver=0 , int edg=0);
	void addedge(int u, int v, int w);
	int kruskalMST();
	~graph();
};

