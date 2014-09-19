#ifndef TIMERS_H
#define TIMERS_H

#define REVERSE 1
#define FORWARD 0
#define TMR3_SAMP_PRD 576
#define TMR1_SAMP_PRD 144

void initTimer1(void);
void initTimer3(void);
uint32_t millis(void);
void adc_to_sample_rate(uint16_t*);

void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void);
void __attribute__((__interrupt__, no_auto_psv)) _T3Interrupt(void);

#endif /*TIMERS_H*/