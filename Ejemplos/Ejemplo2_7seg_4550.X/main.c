/* 
 * File:   main.c
 * Author: HP
 *
 * Created on August 7, 2022, 5:50 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <xc.h>
#include "Configuracion.h"

uint8_t Display_7Seg_A[10] = {0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};
uint8_t i,j;
uint8_t decenas=0,unidades=0;

void Ejemplo1(void);

int main(int argc, char** argv) {

    ConfigClock();
    TRISD = 0X00;//Definimos el puerto D como salida
    LATD = 0XFF;//off
    TRISB = 0X00;//Definimos el puerto D como salida
    LATB = 0XFF;//off
    
    //definimos los pulsadores
    TRISC |= (1<<0) | (1<<1);
    
    for(;;){
    
        if ((PORTC & (1<<0)) == 0) {
            while((PORTC & (1<<0)) == 0);//bloqueo
            unidades++;
            if (unidades == 10) {
            unidades = 0;
            decenas++;
            }
            if (decenas == 10) {
                decenas = 0;
            }

        }
        
        
        if ((PORTC & (1<<1)) != 0) {
            while((PORTC & (1<<1)) != 0);//bloqueo
            unidades--;
            if ( (decenas == 0 )  && (unidades == 255)) {
            unidades = 0;
            }
            if ((decenas > 0 )  && (unidades == 255)) {
                unidades = 9;
                decenas--;
            }
        
        }
            LATD = Display_7Seg_A[unidades];
            LATB = Display_7Seg_A[decenas];


        }
    
    return (EXIT_SUCCESS);
}

void Ejemplo1(void){
       for(i=0;i<10;i++){
            for(j=0;j<10;j++){
                LATD = Display_7Seg_A[j];
                LATB = Display_7Seg_A[i];
                __delay_ms(200);
                 }
            }
}


