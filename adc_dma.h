#ifndef ADC_H
#define ADC_H

#define ADC_BITS 12
#define ADC_MAX (1<<ADC_BITS)
#define NUM_ADC_INPUTS 2


struct t_adc
{
	uint16_t smpl_rate;
	uint16_t smpl_input;
	uint16_t smpl_start;
	uint16_t smpl_end;
	uint16_t smpl_win_offset;
	uint16_t smpl_splice;
};

extern volatile struct t_adc adc;

void init_adc(void);
void init_dma0(void);

void __attribute__((interrupt, no_auto_psv)) _DMA0Interrupt();

#endif /*ADC_H*/