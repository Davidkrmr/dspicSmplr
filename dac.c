#include <p33Fxxxx.h>
#include <stdint.h>
#include "dac.h"


void initDac()
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

extern volatile int32_t sample;
extern uint8_t sample_buf[];

void __attribute__((interrupt, no_auto_psv))_DAC1RInterrupt(void)
{
    DAC1RDAT = sample_buf[sample]<<4;
    IFS4bits.DAC1RIF = 0;
}
