#include <p33Fxxxx.h>
#include <stdint.h>


void init_spi()
{
    RPINR20bits.SDI1R = 8;      //SD1 (Data in) tied to RP8
    RPOR3bits.RP6R = 7;         //SDO1 (Data out) tied to RP6
    RPOR3bits.RP7R = 8;         //SCK1 (Clock out) tied to RP7

    SPI1STAT = 0;               //Disable module - good practice
    SPI1CON1bits.DISSCK = 1;    //Enable master clock out
    SPI1CON1bits.DISSDO = 1;    //Data out controlled by module
    SPI1CON1bits.MODE16 = 0;    //Byte write
    SPI1CON1bits.CKE = 0;       //Risig edge transition
    SPI1CON1bits.MSTEN = 1;     //Master mode
    SPI1CON1bits.SPRE = 0;      //Secondary prescaler 1:1
    SPI1CON1bits.PPRE = 1;      //Primary prescaler 4:1

    SPI1STATbits.SPIEN = 1;		//Enable
}


void spi_write_byte(uint8_t data)
{
	SPI1BUF = data;
	while(!SPI1STATbits.SPIRBF);
}

uint8_t spi_read_byte()
{
	SPI1BUF = 0;
	while(!SPI1STATbits.SPIRBF);
	return SPI1BUF;
}



