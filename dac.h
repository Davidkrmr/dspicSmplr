#ifndef DAC_H
#define DAC_H

extern volatile uint16_t dac_out;

void init_dac(void);

void __attribute__((interrupt, no_auto_psv))_DAC1RInterrupt(void);

#endif /*DAC_H*/