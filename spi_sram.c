#include <stdint.h>
#include "spi_sram.h"
#include "spi.h"

void write_sram(uint32_t address, uint16_t data)
{
	spi_write_byte(WRITE);			//Instruction = write
	spi_write_byte(address >> 16);	//Write 24bit address
	spi_write_byte(address >> 8);
	spi_write_byte(address);
	spi_write_byte(data>>8);		//Write data
	spi_write_byte(data);
}

uint16_t read_sram(uint32_t address)
{
	uint16_t data = 0;

	spi_write_byte(READ);			//Instruction = write
	spi_write_byte(address >> 16);	//Write 24bit address
	spi_write_byte(address >> 8);
	spi_write_byte(address);
	data |= spi_read_byte() << 8;
	data |= spi_read_byte();

	return data;
}