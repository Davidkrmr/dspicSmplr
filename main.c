#include <p33FJ128GP802.h>
#include <stdint.h>
#include "buttons.h"
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

    init_timer1();
    init_timer3();
    init_adc();
    init_dma0();
    init_dac();

    
    TRISA = 0x0000;
    LATA = 0x0000;

    uint32_t tmr;
    tmr = millis();

    while(1) {

        if((millis() - tmr) > FLASH_RATE) {
            LATA ^= (1<<LED_PIN);
            tmr = millis();
        }

        check_buttons();
    }
    return 0;
}