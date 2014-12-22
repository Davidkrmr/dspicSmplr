#include <p33Fxxxx.h>
#include <stdint.h>
#include "dac.h"

void init_dac()
{
    ACLKCONbits.SELACLK  = 0;  // FRC w/ Pll as Clock Source
    ACLKCONbits.APSTSCLR = 7;  // Fvco/1

    DAC1STATbits.ROEN = 1;
    DAC1STATbits.RITYPE = 0;
    DAC1CONbits.AMPON = 0;
    DAC1CONbits.DACFDIV = 72;
    DAC1CONbits.FORM = 0;
    DAC1DFLT = 0x8000;
    IFS4bits.DAC1RIF = 0;
    IEC4bits.DAC1RIE = 1;
    DAC1CONbits.DACEN = 1;
}

volatile uint16_t dac_out = 0;
 
void __attribute__((interrupt, no_auto_psv))_DAC1RInterrupt(void)
{
    DAC1RDAT = dac_out;
    IFS4bits.DAC1RIF = 0;
}
