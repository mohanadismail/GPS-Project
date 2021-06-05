#include <math.h>
#define rad(x) x*(3.14159/180)

double rad_lat_1, rad_long_1, rad_lat_2, rad_long_2,lat_diff, long_diff, under_sqrt, flt_sqrt, haversineDistance;
int D_EarthDiameter = 2 * 6371000;

double distanceBetweenTwoPoints(double lat_1, double long_1, double lat_2, double long_2) // Haversine Formula
{ 
	// converting DDM to DD
	lat_1 = (int)(lat_1 / 100) + (lat_1 - ((int)(lat_1 / 100))*100)/60;
  	long_1 = (int)(long_1 / 100) + (long_1 - ((int)(long_1 / 100))*100)/60;
  	lat_2 = (int)(lat_2 / 100) + (lat_2 - ((int)(lat_2 / 100))*100)/60;
  	long_2 = (int)(long_2 / 100) + (long_2 - ((int)(long_2 / 100))*100)/60;
	// converting Coordinates degree values into radian
	rad_lat_1 = rad(lat_1) , rad_lat_2 = rad(lat_2);
	rad_long_1 = rad(long_1) , rad_long_2 = rad(long_2);


	lat_diff = rad_lat_2 - rad_lat_1;
	long_diff = rad_long_2 - rad_long_1;
	under_sqrt = pow(sin(lat_diff / 2), 2) + cos(rad_lat_1)*cos(rad_lat_2)*pow(sin(long_diff / 2), 2);
	flt_sqrt = sqrtf(under_sqrt);
	haversineDistance = D_EarthDiameter * asinf(flt_sqrt);

	return (double)haversineDistance;
}
