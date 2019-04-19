#pragma once
#include <string>
class location
{
public:
	std::string name;
	double latitude, longitude;

	location(std::string nm = "", double lat=0, double lon=0);
	~location(void);
	void display();
};
