#ifndef CONFIG_H
#define	CONFIG_H

#define FRC 7372800
#define N1 2
#define N2 2
#define M 40
#define FOSC (FRC * M/(N1 * N2))
#define FCY (FOSC / 2)
#define FVCO ((FRC * M)/N1)

#define LED_PIN	0
#define FLASH_RATE 1000

#endif	/* CONFIG_H */

