#include <p33FJ128GP802.h>
#include <stdint.h>
#include "functions.h"
#include "adc_dma.h"
#include "dac.h"
#include "timers.h"
#include "config.h"

/***********************************************************************
*set clock for internal OSC with PLL
*no clock output, external OSC disabled
*disable the watchdog timer
***********************************************************************/

_FOSCSEL(FNOSC_FRCPLL)
_FOSC(OSCIOFNC_OFF & POSCMD_NONE)
_FWDT(FWDTEN_OFF)

int main (void)
{
    PLLFBD = 38;
    CLKDIVbits.PLLPOST = 0;
    CLKDIVbits.PLLPRE = 0;

    initTimer1();
    initTimer3();
    initAdc();
    initDma0();
    initDac();

    uint32_t tmr;
    
    TRISA = 0x0000;
    LATA = 0x0000;
    LATA |= (1<<1);

    tmr = millis();

    while(1) {

        if((millis() - tmr) > FLASH_RATE) {
            LATA ^= (1<<LED_PIN);
            tmr = millis();
        }
    }
    return 0;
}