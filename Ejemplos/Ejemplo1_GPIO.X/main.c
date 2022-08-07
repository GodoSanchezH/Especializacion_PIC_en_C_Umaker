/* 
 * File:   main.c
 * Author: HP
 *
 * Created on 7 de agosto de 2022, 03:50 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pic18f57q43.h>
#include <pic18.h>
#include "Configuracion.h"

/*********************************************************************
 * Function:        void Config_GPIO(void)
 *
 * PreCondition:    Tiene que ir al comienzo del programa   
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        None
 *
 * Note:            Se configura los perifericos nesesarios
 ********************************************************************/

void Config_GPIO(void);



int main(int argc, char** argv) {

    Clock_Config();
    Config_GPIO();
    
    for(;;){
    
        
        if (!(PORTB & (1<<4)))  LATF |= (1<<3);
        else LATF &= ~(1<<3);

//        LATF ^= (1<<3);
//        __delay_ms(1000);
        
        

//        LATF = 0x08;//
//        __delay_ms(1000);
//         LATF = 0x00;//
//        __delay_ms(1000);
/******************************************************************/
        
//        LATFbits.LATF3 = 0;
//        __delay_ms(100);
//        LATFbits.LATF3 = 1;
//        __delay_ms(100);
    
    
    
    }
    
    return (EXIT_SUCCESS);
}

void Config_GPIO(void) {

//    //Salida digital para RF3
//    TRISF = 0x00; ///SALIDA DIGITAL
//    ANSELF = 0X00;// PINES DIGITALES
//    WPUF = 0X00;//DESABILITAMOS LAS RESISTENCIAS PULL-UP
//    INLVLF = 0X00;//TTL
//    ODCONF = 0X00;//PUSH-PULL
/******************************************************************/

    
//    TRISFbits.TRISF3 = 0;//como salida digital
//    ANSELFbits.ANSELF3 = 0;//como digital
//    WPUFbits.WPUF3 = 0;//desactivo la res pull-up
//    INLVLFbits.INLVLF3 = 0; //TTL
//    ODCONFbits.ODCF3 = 0;//PushPull
//    SLRCONFbits.SLRF3 = 1;//Limitado
//    
    
    //define como salida digital RF3
    // TRISF &= ~(1<<3);  TRISF = 0B1101 1111
    // TRISF = TRISF & ~(1<<3);
    //0000 0001 
    //0000 1000   <- (1<<3)
    //1111 0111  ~
    //1101 1111<- TRISF
    //1111 0111 
    //1101 0111 = RESULTADO
    
    TRISF &= ~(1<<3);//RF3 SALIDA
    ANSELF &= ~(1<<3);//PIN DIGITAL
    WPUF &= ~(1<<3);//pull-up off
    INLVLF &= ~(1<<3);//TTL
    ODCONF &= ~(1<<3);//PushPull
    SLRCONF |= (1<<3);//Limit Rate
    
    
    //entrada digital al pin rb4
    TRISB |= (1<<4);//RB4 ENTRADA
    ANSELB &= ~(1<<4);//digital
    WPUB |= (1<<4);//pull-up ON
    INLVLB &= ~(1<<4);//TTL
    ODCONB &= ~(1<<4);//PushPull
    SLRCONB |= (1<<4);//Limit Rate
    
}
       

