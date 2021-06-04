#include "Headers/tm4c123gh6pm.h"
#include "karim.h"
#include "7_segments.h"
#include "GPGGA_functions.h"
#include "Extract-Coordinates.h"
#include "distanceBetweenTwoPoints.h"

float distance = 0;
float prev_lat, prev_long, current_lat, current_long;

int main () {
	//All initilizations
	initUART();
	segments_initialize();
	PORTF_init();
	led_on('r'); //turn red led on until gps fix
	extract_GPGGA_message(); //take UART input
	split_GPGGA();
	while (!validity(data)) { //wait till gps fix
		extract_GPGGA_message();
		split_GPGGA();
	}
	prev_lat = getLatitude(data); //save current location
	prev_long = getLongitude(data);
	while (1) {
		extract_GPGGA_message(); //take new input
		split_GPGGA();
		current_lat = getLatitude(data);
		current_long = getLongitude(data);
		distance += distanceBetweenTwoPoints(prev_lat, prev_long, current_lat, current_long); //calculate distance and increase calculated distance
	}
}
