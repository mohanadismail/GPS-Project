#include "Headers/tm4c123gh6pm.h"
#include "karim.h"
#include "7_segments.h"
#include "GPGGA_functions.h"
#include "david.h"
#include "distanceBetweenTwoPoints.h"
#include "UART.h"

float distance = 0;

int main () {
	//All initilizations
	INIT_UART1();
	segments_initialize();
	PORTF_init();
	led_on('r'); //turn red led on until gps fix
	extract_GPGGA_message(); //take UART input
	split_GPGGA();
	while (!validity(data)) { //wait till gps fix
		extract_GPGGA_message();
		split_GPGGA();
	}
}
