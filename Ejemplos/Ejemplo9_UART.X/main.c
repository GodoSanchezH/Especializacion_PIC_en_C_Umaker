/* 
 * File:   main.c
 * Author: HP
 *
 * Created on 28 de agosto de 2022, 04:51 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Configuracion.h"
#include "Uart.h"
#include <xc.h>
#include <stdint.h>
#include <stdbool.h>




int main(int argc, char** argv) {

    Clock_Config();
    UART_Init(9600);
    
    
    
    for(;;){
    
        UART_Print_String("hola\n\r") ;
        __delay_ms(200);
    
    }
    
    return (EXIT_SUCCESS);
}

