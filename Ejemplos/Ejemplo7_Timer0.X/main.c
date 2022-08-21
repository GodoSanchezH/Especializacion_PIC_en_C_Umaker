/* 
 * File:   main.c
 * Author: HP
 *
 * Created on August 21, 2022, 3:58 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "Configuracion.h"
#include "Interrupt.h"
#include "Timer0.h"
#include <xc.h>
void Config_GPIO(void);


int main(int argc, char** argv) {

    Clock_Config();//1Mhz
    Config_GPIO();
    Interrupt_Config();
    TimerInit(M_8bit);
    for(;;){
    
    
    }
    
    return (EXIT_SUCCESS);
}
void Config_GPIO(void){
   //salida digital al pin rb4
    TRISB &= ~(1<<4);//RB4 salida
    ANSELB &= ~(1<<4);//digital
    WPUB &= ~(1<<4);//pull-up off
    INLVLB &= ~(1<<4);//TTL
    ODCONB &= ~(1<<4);//PushPull
    SLRCONB |= (1<<4);//Limit Rate

   // LATBbits.LATB4 = 1;
}
