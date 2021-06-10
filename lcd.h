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
// control: RS--->A2 , EN--->A3 
// connect A to VDD
// connect RW and K to GND 

void lcd_initialization(void){
	SYSCTL_RCGCGPIO_R |= 0x03;
	while ( (SYSCTL_RCGCGPIO_R & 0x03) == 0);
	
	//B
	GPIO_PORTB_DIR_R = 0xFF;
	GPIO_PORTB_DEN_R = 0xFF;
	GPIO_PORTB_AFSEL_R = 0x00;
	GPIO_PORTB_AMSEL_R = 0x00;
	GPIO_PORTB_PCTL_R = 0x00000000;
	
	//A
	GPIO_PORTA_DIR_R |= 0x0C;
	GPIO_PORTA_DEN_R |= 0x0C;	
	GPIO_PORTA_AFSEL_R &=~0x0C;
	GPIO_PORTA_AMSEL_R &=~ 0x0C;
	GPIO_PORTA_PCTL_R &= ~ 0x0000FF00;

}
void delay(unsigned long t) {
    while(t)	t--; 
}

void lcd_cmd(unsigned char ch){
	GPIO_PORTA_DATA_R &=~0x04;	//RS = 0
	GPIO_PORTB_DATA_R = ch;			//sending command
	GPIO_PORTA_DATA_R |= 0x08;	//enable on
	delay(100000);
	GPIO_PORTA_DATA_R &=~0x08;	//enable off
}
void lcd_data(unsigned char data){
	GPIO_PORTA_DATA_R |= 0x04;	//RS = 1
	GPIO_PORTB_DATA_R = data;		//sending data
	GPIO_PORTA_DATA_R |= 0x08;	//enable on
	delay(100000);
	GPIO_PORTA_DATA_R &=~0x08;	//enable off
}
void lcd_ready (void){
	lcd_cmd(mode_8pins);
	lcd_cmd(display_on);	
	lcd_cmd(increment_cursor);  
	lcd_cmd(clear);
}
void print_int(int x){
	int y, z, v;
	lcd_ready();
	y = x % 10;
	x /= 10;
	z = x % 10;
	x /= 10;
	v = x;
	lcd_data((char) v);
	lcd_data((char) z);
	lcd_data((char) y);
	lcd_data('m');
}
void print_str(unsigned char* s){
	int i ;
	for(i = 0 ; s[i] != '\0' ; i++){
		lcd_data(s[i]);
	}
	lcd_cmd(cursor_off);
}
void print_all(unsigned char* dis , unsigned char* speed){
	lcd_ready();
	print_str(dis);
	print_str("m , ");
	print_str(speed);
	print_str("m/s");
}
