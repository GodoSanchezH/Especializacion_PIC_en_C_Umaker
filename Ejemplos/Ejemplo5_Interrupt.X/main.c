/* 
 * File:   main.c
 * Author: HP
 *
 * Created on August 14, 2022, 3:50 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <stdbool.h>
#include "Configuracion.h"
#include "Interrupt.h"
/*
 * 
 */

volatile bool Flag=false;

void Config_GPIO(void);





int main(int argc, char** argv) {
   
    Clock_Config();//64MHz
    Config_GPIO();
    Interrupt_Config();
    
    for (;;) {
    
        
        

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

    
    TRISF &= ~(1<<2);//Rf2 SALIDA
    ANSELF &= ~(1<<2);//PIN DIGITAL
    WPUF &= ~(1<<2);//pull-up off
    INLVLF &= ~(1<<2);//TTL
    ODCONF &= ~(1<<2);//PushPull
    SLRCONF |= (1<<2);//Limit Rate
    
    TRISF &= ~(1<<1);//Rf1 SALIDA
    ANSELF &= ~(1<<1);//PIN DIGITAL
    WPUF &= ~(1<<1);//pull-up off
    INLVLF &= ~(1<<1);//TTL
    ODCONF &= ~(1<<1);//PushPull
    SLRCONF |= (1<<1);//Limit Rate
    
    
     //entrada digital al pin rb4
    TRISB |= (1<<4);//RB4 ENTRADA
    ANSELB &= ~(1<<4);//digital
    WPUB |= (1<<4);//pull-up ON
    INLVLB &= ~(1<<4);//TTL
    ODCONB &= ~(1<<4);//PushPull
    SLRCONB |= (1<<4);//Limit Rate
    
}
