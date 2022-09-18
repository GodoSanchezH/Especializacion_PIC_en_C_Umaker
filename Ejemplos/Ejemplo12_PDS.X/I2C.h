/* 
 * File:   I2C.h
 * Author: HP
 *
 * Created on 4 de septiembre de 2022, 03:31 PM
 */

#ifndef I2C_H
#define	I2C_H

#include <stdint.h>


#define F_Scl 100000UL

#define Modo_Write 0b00000000
#define Modo_Read  0b00000001
#define ADDR_PCF1  0b01000000
#define ADDR_PCF2  0b01001100
#define ADDR_PCF3  0b01000110
#define ADDR_PCF4  0b01000010

#define ADDR_DAC  0b11000000
#define I2C_ACK 0b00000000
#define I2C_nACK 0b00000001

void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Restart(void);
void I2C_Write_Address_Slave(uint8_t address ,uint8_t dir);
void I2C_Write_Slave(uint8_t data);
void I2C_ReadData(uint8_t *Ptr_data , uint8_t var_Ack_nAck);


#endif	/* I2C_H */

