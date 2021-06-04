#include "tm4c123gh6pm.h"

void buzzer_initialize(){  
	
	// B5........00100000
	SYSCTL_RCGCGPIO_R |= 0x02;        
	while ((SYSCTL_PRGPIO_R & 0x02)==0);  
	GPIO_PORTB_DIR_R |= 0x20; 
	GPIO_PORTB_DEN_R |= 0x20;
	GPIO_PORTB_AMSEL_R &= ~ 0x20; 
	GPIO_PORTB_AFSEL_R &= ~ 0x20;
	GPIO_PORTB_PCTL_R &= ~ 0x00F00000;
}
