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
	void setdata(location stp , location edp);
	double length();
	void display();
	~roads();
};

