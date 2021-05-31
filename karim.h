#include "Headers/tm4c123gh6pm.h"

void PORTF_init(void){
	SYSCTL_RCGCGPIO_R|= 0x20;
	while((SYSCTL_PRGPIO_R &0x20)== 0){};
		GPIO_PORTF_LOCK_R = 0x4C4F434B;
		GPIO_PORTF_CR_R|= 0x0E;
		GPIO_PORTF_DIR_R|=0x0E;
		GPIO_PORTF_DEN_R|= 0x0E;
		GPIO_PORTF_AMSEL_R&= ~0x0E;
}

void led_on (char color){
	GPIO_PORTF_DATA_R &= ~0x0E; // Turn leds of if they are on
	if(color == "r"){
		GPIO_PORTF_DATA_R |= 0x02; //Red led turns on when input is "r"
	}else if(color == "b"){
		GPIO_PORTF_DATA_R |= 0x04; //Green led turns on when input is "g"
	}else{
		GPIO_PORTF_DATA_R |= 0x08; //Otherwise Blue led turns on
	}
	 
}
