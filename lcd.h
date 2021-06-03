#include "tm4c123gh6pm.h"
// commands
#define	clear 							0x01
#define	cursor_on 					0x0F
#define cursor_off					0x0C
#define	increment_cursor 		0x06
#define	display_on 					0x0E
#define	cursor_at_1stline 	0x80
#define	cursor_at_2ndline 	0xC0
#define mode_8pins 					0x38

// I am using all pins of port B ie, D0:D7--->B0:B7
// control: RS--->D0 , EN--->D1 
// connect A to VDD
// connect RW and K to GND 

void delay(unsigned long t) {
    while(t)	t--; }

void lcd_cmd(unsigned char ch){
	GPIO_PORTD_DATA_R &=~0x01;	//RS = 0
	GPIO_PORTB_DATA_R = ch;			//sending command
	GPIO_PORTD_DATA_R |= 0x02;	//enable on
	delay(10000);
	GPIO_PORTB_DATA_R &=~0x02;	//enable off
}
void lcd_data(unsigned char data){
	GPIO_PORTD_DATA_R |= 0x01;	//RS = 1
	GPIO_PORTB_DATA_R = data;		//sending data
	GPIO_PORTD_DATA_R |= 0x02;	//enable on
	delay(10000);
	GPIO_PORTD_DATA_R &=~0x02;	//enable off
}
void lcd_initialization(void){
	SYSCTL_RCGCGPIO_R |= 0x0A;
	while ( (SYSCTL_RCGCGPIO_R & 0x0A) == 0);
	
	//B
	GPIO_PORTB_DIR_R = 0xFF;
	GPIO_PORTB_DEN_R = 0xFF;
	GPIO_PORTB_AFSEL_R = 0x00;
	GPIO_PORTB_AMSEL_R = 0x00;
	GPIO_PORTB_PCTL_R = 0x00000000;
	
	//D
	
	GPIO_PORTD_DIR_R |= 0x03;
	GPIO_PORTD_DEN_R |= 0x03;	
	GPIO_PORTD_AFSEL_R &=~0x03;
	GPIO_PORTD_AMSEL_R &=~ 0x03;
	GPIO_PORTB_PCTL_R &= ~ 0x000000FF;

}
void lcd_ready (void){
	lcd_cmd(mode_8pins);
	lcd_cmd(display_on);	
	lcd_cmd(clear);	
	lcd_cmd(cursor_on);  
	lcd_cmd(cursor_at_1stline);
}
