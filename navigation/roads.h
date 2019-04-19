#pragma once
#include "location.h"
class roads
{
public:
	location start_pt;
	location end_pt;
	double len;
	roads(location stp , location edp);
	roads(void);
	double length();
	void display();
	~roads();
};

