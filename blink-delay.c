// Blink using delay function

#include <msp430g2553.h>

#define LED1_MASK       0x01
#define LED2_MASK       0x40


void configureClocks()
{
  // Stop watchdog
  WDTCTL = WDTPW + WDTHOLD;
  BCSCTL1 = CALBC1_1MHZ;
  DCOCTL = CALDCO_1MHZ;
}


void delay_us(unsigned int us)
{
  while (us)
  {
    // 1 for 1 Mhz set 16 for 16 MHz
    __delay_cycles(1); 
    us--;
  }
}


void delay_ms(unsigned int ms)
{
  while (ms)
  {
    // 1000 for 1MHz and 16000 for 16MHz
    __delay_cycles(1000);
    ms--;
  }
}


int main(void)
{
  configureClocks();

  /* set P1 direction */
  P1DIR = LED1_MASK | LED2_MASK;

  /* LED1 on and LED2 off*/
  P1OUT = 0x01;

  while  (1)
  {
    /* toggle leds */
    P1OUT ^= (LED1_MASK | LED2_MASK);
    
    delay_ms(200);
  }
  
}