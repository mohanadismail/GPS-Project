#include <math.h>
#define rad(x) x*(3.14159/180)
#define DDM_to_DD(x) (int)(x / 100) + ((x - ((int)(x / 100)) * 100) / 60)

double lat_diff, long_diff, under_sqrt, flt_sqrt, haversineDistance;
int D_EarthDiameter = 2 * 6371000;

double distanceBetweenTwoPoints(double lat_1, double long_1, double lat_2, double long_2) // Haversine Formula
{
	// converting DDM into DD
	lat_1 = DDM_to_DD(lat_1), long_1 = DDM_to_DD(long_1);
	lat_2 = DDM_to_DD(lat_2), long_2 = DDM_to_DD(long_2);

	// converting from degrees into radian
	lat_1 = rad(lat_1), long_1 = rad(long_1);
	lat_2 = rad(lat_2), long_2 = rad(long_2);

	// implementing Haversine 
	lat_diff = lat_2 - lat_1;
	long_diff = long_2 - long_1;
	under_sqrt = pow(sin(lat_diff / 2), 2) + cos(lat_1)*cos(lat_2)*pow(sin(long_diff / 2), 2);
	flt_sqrt = sqrtf(under_sqrt);
	haversineDistance = D_EarthDiameter * asinf(flt_sqrt);

	return haversineDistance;
}
