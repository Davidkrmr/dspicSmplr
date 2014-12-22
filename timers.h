#ifndef TIMERS_H
#define TIMERS_H

#define REC_ARMED 0x01
#define RECORD 0x02
#define RECORD_DONE 0x04
#define PLAYBACK 0x08

#define DEFAULT_SMPL_PRD 576
#define TMR1_SAMP_PRD 144

#define MAX_SAMPLE_RATE 44100
#define MIN_SAMPLE_PRD 835			//FCY/MAX_SAMPLE_RATE

extern volatile uint32_t millis_cnt;
extern volatile uint32_t sample;
extern volatile uint8_t mode;

#define INC_SAMPLE (sample += 2)
#define DEC_SAMPLE (sample += 2)

#define millis() (millis_cnt)
#define tick() (millis_cnt++)

void init_timer1(void);
void init_timer3(void);

void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void);
void __attribute__((__interrupt__, no_auto_psv)) _T3Interrupt(void);

#endif /*TIMERS_H*/