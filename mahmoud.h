#include "tm4c123gh6pm.h"

void intialize(){
	
	//A
	SYSCTL_RCGCGPIO_R |= 0x01;          
	while ((SYSCTL_PRGPIO_R & 0x01)==0);
	GPIO_PORTA_DIR_R |= 0xFC;
	GPIO_PORTA_DEN_R |= 0xFC;
	GPIO_PORTA_AMSEL_R &= ~ 0xFC;
	GPIO_PORTA_AFSEL_R &= ~ 0xFC;
	GPIO_PORTA_PCTL_R &= ~ 0xFFFFFF00;  

	//B
	SYSCTL_RCGCGPIO_R |= 0x02;        
	while ((SYSCTL_PRGPIO_R & 0x02)==0);  
	GPIO_PORTB_DIR_R |= 0x1C; 
	GPIO_PORTB_DEN_R |= 0x1C;
	GPIO_PORTB_AMSEL_R &= ~ 0x1C; 
	GPIO_PORTB_AFSEL_R &= ~ 0x1C;
	GPIO_PORTB_PCTL_R &= ~ 0x000FFF00;   
	
	//D
	SYSCTL_RCGCGPIO_R |= 0x08;          
	while ((SYSCTL_PRGPIO_R & 0x08)==0); 
	GPIO_PORTD_LOCK_R = 0x4C4F434B;    
	GPIO_PORTD_CR_R |= 0x80;
	GPIO_PORTD_DIR_R |= 0xCF;
	GPIO_PORTD_DEN_R |= 0xCF;
	GPIO_PORTD_AMSEL_R &= ~ 0xCF;  
	GPIO_PORTD_AFSEL_R &= ~ 0xCF;
	GPIO_PORTD_PCTL_R &= ~ 0xFF00FFFF;   
	 
	//E
	SYSCTL_RCGCGPIO_R |= 0x10;        
	while ((SYSCTL_PRGPIO_R & 0x10)==0); 
	GPIO_PORTE_DIR_R |= 0x3F;
	GPIO_PORTE_DEN_R |= 0x3F;            
	GPIO_PORTE_AMSEL_R &= ~ 0x3F;  
	GPIO_PORTE_AFSEL_R &= ~ 0x3F;  
	GPIO_PORTE_PCTL_R &= ~ 0x00FFFFFF;
	       
}

void hundreds_digit(int i){
	switch (i){
		case 0:
			GPIO_PORTA_DATA_R &= ~ 0x20;
		  GPIO_PORTA_DATA_R |= 0x1C;
		  GPIO_PORTB_DATA_R |= 0x10;
		  GPIO_PORTE_DATA_R |= 0x30;
		  break;
		case 1:
			GPIO_PORTA_DATA_R &= ~ 0x24;
		  GPIO_PORTA_DATA_R |= 0x18;
		  GPIO_PORTB_DATA_R &= ~ 0x10;
		  GPIO_PORTE_DATA_R &= ~ 0x30;
		  break;
		case 2:
			GPIO_PORTA_DATA_R |= 0x2C;
		  GPIO_PORTA_DATA_R &= ~ 0x10;
		  GPIO_PORTB_DATA_R &= ~ 0x10;
		  GPIO_PORTE_DATA_R |= 0x30;
		  break;
		case 3:
			GPIO_PORTA_DATA_R |= 0x3C;
		  GPIO_PORTB_DATA_R |= 0x23;
		  GPIO_PORTB_DATA_R &= ~ 0x10;
		  GPIO_PORTE_DATA_R |= 0x10;
		  GPIO_PORTE_DATA_R &= ~ 0x20;
		  break;
		case 4:
			GPIO_PORTA_DATA_R |= 0x38;
		  GPIO_PORTA_DATA_R &= ~ 0x04;
		  GPIO_PORTB_DATA_R |= 0x10;
		  GPIO_PORTE_DATA_R &= ~ 0x30;
		  break;
		case 5:
			GPIO_PORTA_DATA_R |= 0x34;
		  GPIO_PORTB_DATA_R &= ~ 0x08;
		  GPIO_PORTB_DATA_R |= 0x10;
		  GPIO_PORTE_DATA_R |= 0x10;
		  GPIO_PORTE_DATA_R &= ~ 0x20;
		  break;
		case 6:
			GPIO_PORTA_DATA_R |= 0x30;
		  GPIO_PORTB_DATA_R &= ~ 0x0C;
		  GPIO_PORTB_DATA_R |= 0x10;
		  GPIO_PORTE_DATA_R |= 0x30;
		  break;
		case 7:
			GPIO_PORTA_DATA_R |= 0x1C;
		  GPIO_PORTA_DATA_R &= ~ 0x20;
		  GPIO_PORTB_DATA_R &= ~ 0x10;
		  GPIO_PORTE_DATA_R &= ~ 0x30;
		  break;
		case 8:
			GPIO_PORTA_DATA_R |= 0x3C;
		  GPIO_PORTB_DATA_R |= 0x10;
		  GPIO_PORTE_DATA_R |= 0x30;
		  break;
		case 9:
			GPIO_PORTA_DATA_R |= 0x3C;
		  GPIO_PORTB_DATA_R |= 0x10;
		  GPIO_PORTE_DATA_R |= 0x10;
		  GPIO_PORTE_DATA_R &= ~ 0x20;
		  break;
	}
}
void tens_digit(int j){
	switch (j){
		case 0:
			GPIO_PORTE_DATA_R &= ~ 0x02;
		  GPIO_PORTA_DATA_R |= 0xC0;
		  GPIO_PORTD_DATA_R |= 0x0F;
		  break;
		case 1:
			GPIO_PORTE_DATA_R &= ~ 0x02;
		  GPIO_PORTA_DATA_R |= 0x80;
		  GPIO_PORTA_DATA_R &= ~ 0x40;
		  GPIO_PORTD_DATA_R |= 0x01;
		  GPIO_PORTD_DATA_R &= ~ 0x0E;
		  break;
		case 2:
			GPIO_PORTE_DATA_R |= 0x02;
		  GPIO_PORTA_DATA_R |= 0xC0;
		  GPIO_PORTD_DATA_R |= 0x06;
		  GPIO_PORTD_DATA_R &= ~ 0x09;
		  break;
		case 3:
			GPIO_PORTE_DATA_R |= 0x02;
		  GPIO_PORTA_DATA_R |= 0xC0;
		  GPIO_PORTD_DATA_R |= 0x03;
		  GPIO_PORTD_DATA_R &= ~ 0x0C;
		  break;
		case 4:
			GPIO_PORTE_DATA_R |= 0x02;
		  GPIO_PORTA_DATA_R |= 0x80;
		  GPIO_PORTA_DATA_R &= ~ 0x40;
		  GPIO_PORTD_DATA_R |= 0x09;
		  GPIO_PORTD_DATA_R &= ~ 0x06;
		  break;
		case 5:
			GPIO_PORTE_DATA_R |= 0x02;
		  GPIO_PORTA_DATA_R |= 0x40;
		  GPIO_PORTA_DATA_R &= ~ 0x80;
		  GPIO_PORTD_DATA_R |= 0x0B;
		  GPIO_PORTD_DATA_R &= ~ 0x04;
		  break;
		case 6:
			GPIO_PORTE_DATA_R |= 0x02;
		  GPIO_PORTA_DATA_R &= ~ 0xC0;
		  GPIO_PORTD_DATA_R |= 0x0F;
		  break;
		case 7:
			GPIO_PORTE_DATA_R &= ~ 0x02;
		  GPIO_PORTA_DATA_R |= 0xC0;
		  GPIO_PORTD_DATA_R |= 0x01;
		  GPIO_PORTD_DATA_R &= ~ 0x0E;
		  break;
		case 8:
			GPIO_PORTE_DATA_R |= 0x02;
		  GPIO_PORTA_DATA_R |= 0xC0;
		  GPIO_PORTD_DATA_R |= 0x0F;
		  break;
		case 9:
			GPIO_PORTE_DATA_R |= 0x02;
		  GPIO_PORTA_DATA_R |= 0xC0;
		  GPIO_PORTD_DATA_R |= 0x0B;
		  GPIO_PORTD_DATA_R &= ~ 0x04;
		  break;
	}
}
void ones_digit(int k){
	switch (k){
		case 0:
			GPIO_PORTB_DATA_R |= 0x0C;
		  GPIO_PORTD_DATA_R |= 0xC0;
		  GPIO_PORTE_DATA_R |= 0x0C;
		  GPIO_PORTE_DATA_R &= ~ 0x01;
		  break;
		case 1:
			GPIO_PORTB_DATA_R |= 0x08;
		  GPIO_PORTB_DATA_R &= ~ 0x04;
		  GPIO_PORTD_DATA_R &= ~ 0xC0;
		  GPIO_PORTE_DATA_R |= 0x08;
		  GPIO_PORTE_DATA_R &= ~ 0x05;
		  break;
		case 2:
			GPIO_PORTB_DATA_R &= ~ 0x0C;
		  GPIO_PORTD_DATA_R |= 0xC0;
		  GPIO_PORTE_DATA_R |= 0x0D;
			break;
		case 3:
			GPIO_PORTB_DATA_R |= 0x08;
		  GPIO_PORTB_DATA_R &= ~ 0x04;
		  GPIO_PORTD_DATA_R |= 0x40;
		  GPIO_PORTD_DATA_R &= ~ 0x80;
		  GPIO_PORTE_DATA_R |= 0x0D;
			break;
		case 4:
			GPIO_PORTB_DATA_R |= 0x0C;
		  GPIO_PORTD_DATA_R &= ~ 0xC0;
		  GPIO_PORTE_DATA_R |= 0x09;
		  GPIO_PORTE_DATA_R &= ~ 0x04;
		  break;
		case 5:
			GPIO_PORTB_DATA_R |= 0x0C;
		  GPIO_PORTD_DATA_R |= 0x40;
		  GPIO_PORTD_DATA_R &= ~ 0x80;
		  GPIO_PORTE_DATA_R |= 0x05;
		  GPIO_PORTE_DATA_R &= ~ 0x08;
		  break;
		case 6:
			GPIO_PORTB_DATA_R |= 0x0C;
		  GPIO_PORTD_DATA_R |= 0xC0;
		  GPIO_PORTE_DATA_R |= 0x01;
		  GPIO_PORTE_DATA_R &= ~ 0x0C;
		  break;
		case 7:
			GPIO_PORTB_DATA_R |= 0x08;
		  GPIO_PORTB_DATA_R &= ~ 0x04;
		  GPIO_PORTD_DATA_R &= ~ 0xC0;
		  GPIO_PORTE_DATA_R |= 0x04;
			GPIO_PORTE_DATA_R &= ~ 0x09;
		  break;
		case 8:
			GPIO_PORTB_DATA_R |= 0x0C;
		  GPIO_PORTD_DATA_R |= 0xC0;
		  GPIO_PORTE_DATA_R |= 0x0D;
		  break;
		case 9:
			GPIO_PORTB_DATA_R |= 0x0C;
		  GPIO_PORTD_DATA_R |= 0x40;
		  GPIO_PORTD_DATA_R &= ~ 0x80;
		  GPIO_PORTE_DATA_R |= 0x0D;
		  break;
	}
}
