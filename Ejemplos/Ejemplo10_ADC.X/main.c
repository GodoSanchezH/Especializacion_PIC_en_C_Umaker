/* 
 * File:   main.c
 * Author: HP
 *
 * Created on 28 de agosto de 2022, 04:51 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Configuracion.h"
#include "Interrupt.h"
#include "Uart.h"
#include "Adc.h"
#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#define Init_Trama 0x00
#define Final_Trama 0xFF

   void Config_GPIO(void );
uint8_t i=0,j=0;
uint16_t data;
int main(int argc, char** argv) {

    Clock_Config();
    ADC_Init();
    Config_GPIO();
    Interrupt_Config();
    UART_Init(9600);
    
 
    for(;;){
        
            
            data = AnalogRead(An0);
//            i = (uint8_t) data>>8;
//            j = (uint8_t)data;
//            printf("%c%u%c",Init_Trama,j,i,Final_Trama);
//            
            printf("El valor convertido es: %u" ,data);
          
            
            
        __delay_ms(100);  
      
     }

    
    
     
    
    return (EXIT_SUCCESS);
}

void Config_GPIO(void){
    TRISF &= ~(1<<3);//RF3 SALIDA
    ANSELF &= ~(1<<3);//PIN DIGITAL
    WPUF &= ~(1<<3);//pull-up off
    INLVLF &= ~(1<<3);//TTL
    ODCONF &= ~(1<<3);//PushPull
    SLRCONF |= (1<<3);//Limit Rate



}