#include <math.h>
#define rad(x) x*(3.14159/180)

float distanceBetweenTwoPoints(double lat_1, double long_1, double lat_2, double long_2) // Haversine Formula
{ 
	// converting Coordinates degree values into radian
	double rad_lat_1 = rad(lat_1) , rad_lat_2 = rad(lat_2);
	double rad_long_1 = rad(long_1) , rad_long_2 = rad(long_2);


	int D_EarthDiameter = 2 * 6371000;
	double lat_diff = rad_lat_2 - rad_lat_1;
	double long_diff = rad_long_2 - rad_long_1;
	double under_sqrt = pow(sin(lat_diff / 2), 2) + cos(rad_lat_1)*cos(rad_lat_2)*pow(sin(long_diff / 2), 2);
	double flt_sqrt = sqrtf(under_sqrt);
	double haversineDistance = D_EarthDiameter * asinf(flt_sqrt);

	return haversineDistance;
}
