#include "Headers/tm4c123gh6pm.h"

void PORTF_init(void){
	SYSCTL_RCGCGPIO_R|= 0x20;
	while((SYSCTL_PRGPIO_R &0x20)== 0){};
		GPIO_PORTF_LOCK_R = 0x4C4F434B;
		GPIO_PORTF_CR_R|= 0x0E;
		GPIO_PORTF_DIR_R|=0x0E;
		GPIO_PORTF_DEN_R|= 0x0E;
		GPIO_PORTF_AMSEL_R&= ~0x0E;
		GPIO_PORTF_DATA_R|= 0x0E; //Just to see if the leds are on or not ===> if they are working erase this line
}

void led_on (void){
	GPIO_PORTF_DATA_R &= ~0x0E; // Turn leds of if they are on
	GPIO_PORTF_DATA_R |= 0x04; //Led in pin2 will Turn on
}
