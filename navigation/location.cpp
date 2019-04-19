#include "pch.h"
#include "location.h"



using namespace std;
location::location(string nm, double lat, double lon)
{
	name = nm;
	latitude = lat;
	longitude = lon;

}


location::~location(void)
{
}

void location::display()
{
	cout << name << ": " << latitude << " " << longitude << endl;
}
