void inituart()
{

  SYSCTL_RCGCUART_R |= 0x02 ; /* enable clock for UART1 */
 
  SYSCTL_RCGCGPIO_R |= 0x02 ;  /* activate clock for port B */

  while (SYSCTL_PRGPIO_R & 0x02 == 0) ; /* wait for stabilization */

  GPIO_PORTB_CR_R = 0x03 ; /* allow changes to port A0,A1 */

  GPIO_PORTB_AMSEL_R = 0x00 ; /* disable analog in port A */

  GPIO_PORTB_PCTL_R = 0x00000011 ; /* PB0 and PB1 configure for UART module */

  GPIO_PORTB_DIR_R = 0x02 ; /* Rx PBo (in)  Tx PB1 (out) */

  GPIO_PORTB_AFSEL_R 0x03 ; /* Use PB0,PB1 alternate function */

  GPIO_PORTB_DEN_R  = 0x03 ; /* enable digital in port B0,B1 */
}
