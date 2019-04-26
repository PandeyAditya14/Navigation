#include "pch.h"

using namespace std;

double deg2rad(double deg) {
	return (deg * M_PI / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
	return (rad * 180 / M_PI);
}

roads::roads(void)
{

}

void roads::setdata(location stp, location edp)
{
	start_pt = stp;
	end_pt = edp;
}


roads::roads(location stp, location edp)
{
	start_pt = stp;
	end_pt = edp;
	len = length();
}

double roads::length()
{	
	double lat1d = start_pt.latitude, lat2d = end_pt.latitude;
	double lon1d= start_pt.longitude, lon2d = end_pt.longitude;

	// distance between latitudes 
	// and longitudes 
	double lat1r, lon1r, lat2r, lon2r, u, v;
	lat1r = deg2rad(lat1d);
	lon1r = deg2rad(lon1d);
	lat2r = deg2rad(lat2d);
	lon2r = deg2rad(lon2d);
	u = sin((lat2r - lat1r) / 2);
	v = sin((lon2r - lon1r) / 2);
	return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

void roads::display()
{
	start_pt.display();
	end_pt.display();
	cout << len <<endl;


}

roads::~roads()
{
}
