#include <math.h>

unsigned int distanceBetweenTwoPoints_Harvesine(float lat_1, float long_1, float lat_2, float long_2)
{
	int D_EarthDiameter = 2 * 6371000;
	float lat_diff = lat_2 - lat_1;
	float long_diff = long_2 - long_1;
	float under_sqrt = pow(sin(lat_diff / 2), 2) + cos(lat_1)*cos(lat_2)*pow(sin(long_diff / 2), 2);

	float flt_sqrt = sqrtf(under_sqrt);
	return (int)(D_EarthDiameter*asinf(flt_sqrt));
}
