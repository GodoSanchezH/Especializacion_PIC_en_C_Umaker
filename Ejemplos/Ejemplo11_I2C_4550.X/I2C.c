#include <pic18f4550.h>
#include "I2C.h"
#include "Configuracion.h"



void I2C_Init(void){
    
    TRISB |= (1<<0) | (1<<1);//rb0 y rb1 como entradas
    SSPSTATbits.SMP = 1 ;//a una velocidad standart 100Khz
    SSPCON1bits.SSPEN = 1;//habiltar los pines de SDA Y SCL
    SSPCON1bits.SSPM = 0b1000;//Master mode, clock = FOSC/(4 * (SSPADD + 1))(
    SSPADD = (uint8_t) ((_XTAL_FREQ / (4UL*F_Scl))-1);
}
void I2C_Start(void){
    SSPCON2bits.SEN = 1;//condicion de start
    while(SSPCON2bits.SEN == 1);
}
void I2C_Stop(void){
SSPCON2bits.PEN = 1;//condicion de stop
    while(SSPCON2bits.PEN == 1);
}
void I2C_Restart(void){
    SSPCON2bits.RSEN = 1;
    while(SSPCON2bits.RSEN == 1);
}
void I2C_Write_Address_Slave(uint8_t address ,uint8_t dir){

    SSPBUF =  ((address & 0b11111110) |  (dir & 0b00000001)) ;
            while(SSPSTATbits.BF == 1);
            while(SSPSTATbits.R_nW == 1);
    
}
void I2C_Write_Slave(uint8_t data){
  SSPBUF = data;
  while(SSPSTATbits.BF == 1);
  while(SSPSTATbits.R_nW == 1);  
}
void I2C_ReadData(uint8_t *Ptr_data , uint8_t var_Ack_nAck){

    SSPCON2bits.RCEN = 1;//habilitamos la recepcion de data
    if(var_Ack_nAck == I2C_ACK){
     while(SSPSTATbits.BF == 0);
     *Ptr_data = SSPBUF;
     SSPCON2bits.ACKDT = 0;//preparamos un ack
     SSPCON2bits.ACKEN = 1;//enviamos el ack
     while ( SSPCON2bits.ACKEN == 1);

    }
    if(var_Ack_nAck == I2C_nACK){
    while(SSPSTATbits.BF == 0);
     *Ptr_data = SSPBUF;
     SSPCON2bits.ACKDT = 1;//preparamos un nack
     SSPCON2bits.ACKEN = 1;//enviamos el nack
     while ( SSPCON2bits.ACKEN == 1);
    }

    
}

