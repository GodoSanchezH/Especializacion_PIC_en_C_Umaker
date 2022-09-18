/* 
 * File:   SPI.h
 * Author: HP
 *
 * Created on 17 de septiembre de 2022, 07:45 PM
 */

#ifndef SPI_H
#define	SPI_H
#include <stdint.h>

#define SPI_SLAVE_IO 0b0101 // SPI Slave mode, clock = SCK pin, SS pin control disabled, SS can be used as I/O pin(3)
#define SPI_SLAVE_SS 0b0100 // SPI Slave mode, clock = SCK pin, SS pin control enabled(3)
#define SPI_TMR2     0b0011 // SPI Master mode, clock = TMR2 output/2(3)
#define SPI_CLOCK_64 0b0010 // SPI Master mode, clock = FOSC/64(3)
#define SPI_CLOCK_16 0b0001 // SPI Master mode, clock = FOSC/16(3)
#define SPI_CLOCK_4  0b0000 // SPI Master mode, clock = FOSC/4(3)

typedef enum{
    Modo1=0,
    Modo2,
    Modo3,
    Modo4
}ModoSPI;

void SPI_Init(uint8_t reloj , ModoSPI mood);
void SPI_TX(uint8_t dato);

#endif	/* SPI_H */

