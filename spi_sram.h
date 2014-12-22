#ifndef SPI_SRAM_H
#define SPI_SRAM_H

#define READ 0x03
#define WRITE 0x02

#define MAX_ADDRESS 131071

void write_sram();
uint16_t read_sram();

#endif /*SPI_SRAM_H*/