#ifndef ADC_H
#define ADC_H

void initAdc(void);
void initDma0(void);

void __attribute__((interrupt, no_auto_psv)) _DMA0Interrupt();

#endif /*ADC_H*/