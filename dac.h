#ifndef DAC_H
#define DAC_H

void initDac(void);

void __attribute__((interrupt, no_auto_psv))_DAC1RInterrupt(void);

#endif /*DAC_H*/