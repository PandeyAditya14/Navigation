#pragma once
#include "pch.h"
class Disjointsets
{
public:
	int *parent, *rnk;
	int n;
    Disjointsets(int n=0);
	int find(int u);
	void merge(int x, int y);
	~Disjointsets();
};

