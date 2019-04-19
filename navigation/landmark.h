#pragma once
#include<string.h>
using namespace std;
class landmark
{
public:
	string name;
	double latitutde;
	double longitude;
	landmark();
	void display() {
		cout << latitude << "\n" << longitude;
	}
};



landmark::landmark(string nm = "", double lat = 0, double lon = 0)
{
	name = nm;
	latitude = lat;
	longitude = lon;

}
