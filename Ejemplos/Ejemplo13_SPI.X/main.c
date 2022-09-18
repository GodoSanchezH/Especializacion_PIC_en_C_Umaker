/* 
 * File:   main.c
 * Author: HP
 *
 * Created on 17 de septiembre de 2022, 07:45 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <pic18f4550.h>
#include "Config.h"
#include "SPI.h"
#include "USART.h"

#define CS0 LATDbits.LD0
#define CS1 LATDbits.LATD1
uint8_t i=0;
int temp;
float temperatura ;
void Ejemplo1(void);

int main(int argc, char** argv) {
    
    ConfigClock();
    Serial_begin(9600);
    //SPI_Init(SPI_CLOCK_4,Modo4);
    TRISDbits.RD1 =0 ;//cs max
    TRISDbits.RD3 =0 ;//clk
    TRISAbits.RA4=1 ;//sdi
    LATDbits.LATD1 = 1;
     TRISA = 0B00010000;
    for(;;){
    
       CS1 = 0;
       __delay_us(1);

        for (i = 0; i < 16; i++) {
            LATDbits.LATD3 = 1;
            temp = (temp<<1)|(PORTA&0b00010000)>>4;
        __delay_us(1);
        LATDbits.LATD3 = 0;
        __delay_us(1);
        }
       CS1 =1;
         temperatura=(((0x0FFF & (temp>>3))/4)-24)/10;
       
       printf("Termocupla : %0.4f\n\r",temperatura);
       __delay_ms(800);
       
    }
    
    return (EXIT_SUCCESS);
}

void Ejemplo1(void){
CS0 = 0;
    SPI_TX(0b01000000);//Nos direccionamos al chip
    SPI_TX(0x00);//me ubico en la direccioon 0x00  
    SPI_TX(0x00);// defino como salida al IO
    CS0 = 1;
    __delay_ms(5);

 for (i = 0; i <= 255; i++) {
            CS0 = 0;
            SPI_TX(0b01000000);//Nos direccionamos al chip
            SPI_TX(0x09);//me ubico en la direccioon 0x09
            SPI_TX(i);// registro de escritura
            CS0 = 1;
            __delay_ms(200); 

        }

}