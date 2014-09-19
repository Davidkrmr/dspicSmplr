#ifndef CONFIG_H
#define	CONFIG_H

#define LED_PIN	0
#define FLASH_RATE 1000

#define ADC_BITS 10
#define ADC_MAX ((1<<ADC_BITS)-1)

#define FRC 7372800
#define N1 2
#define N2 2
#define M 40
#define FOSC (FRC * M/(N1 * N2))
#define FCY (FOSC / 2)
#define FVCO ((FRC * M)/N1)

#define SAMPLE_RATE 8000

#endif	/* CONFIG_H */

