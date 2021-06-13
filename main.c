#include "Headers/tm4c123gh6pm.h"
#include <TM4C123.h>
#include "led_end_coord.h"
#include "7_segments.h"
#include "Extract-Coordinates.h"
#include "distanceBetweenTwoPoints.h"
#include "buzzer.h"
#include "lcd.h"

//Global variables
double distance = 0;
int rate = 0;
double prev_lat, prev_long, prev_time, current_time, current_lat, current_long, first_time;
char str[150]; //(externed in GPGGA_functions.h) (to save GPGGA message in)
char *data[15]; //(externed in GPGGA_functions.h) (to split GPGGA into tokens)
int data_length; //(externed in GPGGA_function.h) (to monitor data length and avoid segmentation fault)

void SystemInit() {
	SCB->CPACR |= ((3UL << 10*2) | (3UL << 11*2));
}

int main () {
	//All initilizations
	//initUART1();
	initUART5();
	//segments_initialize();
	lcd_initialization();
	PORTF_init();
	led_on('r'); //turn red led on until gps fix
	extract_GPGGA_message(); //take UART input
	split_GPGGA();
	while (data_length < 6) {  // to avoid segmentation fault
		extract_GPGGA_message();
		split_GPGGA();
	}
	while (!validity()) { //wait till gps fix
		extract_GPGGA_message();
		split_GPGGA();
		while (data_length < 6) {  // to avoid segmentation fault
			extract_GPGGA_message();
			split_GPGGA();
		}
	}
	current_lat = getLatitude(); //save current location
	current_long = getLongitude();
	current_time = getTime();
	first_time = current_time;
	led_on('g'); //turn green led on (gps fixed you may start moving now)
	while (1) {
		if (isHere(current_long, current_lat)) { //check if reached the destination
			led_on('b'); //turn blue led on (you reached the destination)
			rate = (int)(distance/(current_time - first_time));
			print_all((int)distance, rate); //show distance on 7-segments
			print_end();
			//print((int)distance);
			buzzer_on(); //turn on buzzer
			break;
		}
		extract_GPGGA_message(); //take new input
		split_GPGGA();
		while (data_length < 6) {  // rechecking for gps fix
			led_on('r');
			extract_GPGGA_message();
			split_GPGGA();
		}
		while (!validity()) {
			led_on('r');
			extract_GPGGA_message();
			split_GPGGA();
			while (data_length < 6) {  // to avoid segmentation fault
				extract_GPGGA_message();
				split_GPGGA();
			}
		}
		prev_lat = current_lat;
		prev_long = current_long;
		prev_time = current_time;
		current_lat = getLatitude();
		current_long = getLongitude();
		current_time = getTime();
		if ((current_lat - prev_lat > 0.00015 || current_lat - prev_lat < -0.00015) && (current_long - prev_long > 0.00015 || current_long - prev_long < -0.00015)) {
			distance += distanceBetweenTwoPoints(prev_lat, prev_long, current_lat, current_long); //calculate distance and increase calculated distance
			rate = (int)((distanceBetweenTwoPoints(prev_lat, prev_long, current_lat, current_long))/(current_time - prev_time) * 100);
		}
		//print((int)distance);
		print_all((int)distance, rate); //show distance on seven segments while moving
	}
}
