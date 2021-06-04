#include "Headers/tm4c123gh6pm.h"

// UART initialization function 
void initUART (void)
{
SYSCTL_RCGCUART_R |= 0x02 ;  // enable clock for UART1
SYSCTL_RCGCGPIO_R |= 0x02 ;  // activate clock for port B 
while (SYSCTL_PRGPIO_R & 0x02 == 0){} ; // wait for stabilization 
// Assumes a 16 MHz bus clock, creates 9600 baud rate 
UART1_CTL_R &= ~0x00000001 ;    // disable UART 
UART1_IBRD_R = 104 ;    // IBRD = int (16,000,000/(16*9600)) = 104.1666667 
UART1_FBRD_R = 11 ;    // FBRD = factional ((0.1666667 * 64)+0.5) = 11.16688 
UART1_LCRH_R = 0x00000070 ;  // 8 bit, no parity bits, one stop, FIFOs   (0b1110000 = 0x70) 
UART1_CTL_R = 0x0301;   // enable RXE, TXE and UART
GPIO_PORTB_CR_R |= 0x03 ; // allow changes to port B0,B1 
GPIO_PORTB_AMSEL_R &= ~0x03;  // disable analog in port B0,B1 
GPIO_PORTB_PCTL_R |= 0x00000011 ; // PB0 and PB1 configure for UART module 
GPIO_PORTB_DIR_R |= 0x02 ;    //Rx PBo (in)  Tx PB1 (out) 
GPIO_PORTB_AFSEL_R |= 0x03 ;   //Use PB0,PB1 alternate function 
GPIO_PORTB_DEN_R  |= 0x03 ;   //enable digital in port B0,B1 
}

//------------UART_InChar------------
// Wait for new input, then return ASCII code
char readUART (void) {
  while((UART1_FR_R & 0x0010) != 0 ) ;      // wait until RXFE is 0
  return((char)(UART1_DR_R & 0xFF)) ;
}

//------------UART_OutChar------------
// Wait for buffer to be not full, then output
void  writeUART (char data) {
  while((UART1_FR_R & 0x0020) != 0) ;      // wait until TXFF is 0
  UART1_DR_R = data ;
}
