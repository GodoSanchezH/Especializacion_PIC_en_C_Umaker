#include "Uart.h"
#include "Configuracion.h"
#include <xc.h>



void UART_Init(uint32_t  baudios){

//Definimos el BAUD RATE
   U1CON0bits.BRGS = 0; 

    
U1BRG = 416;
        //(uint16_t) ((_XTAL_FREQ/16/baudios)-1);//416;//<<<(uint16_t)Temp;//SE Calcula el baud rate

//seleccionamos el modo de trabajo de 8bit
U1CON0bits.MODE = 0b0000;
//habilitamos el puerto serial
U1CON1bits.ON = 1;


//habilitamos TX
U1CON0bits.TXEN = 1;
//Haabilitamos el RX
U1CON0bits.RXEN = 1;



//habilitar pines pps de la uart 1
//PPS TX -rf0

    RF0PPS = 0x20;
    
    
    TRISFbits.TRISF1 = 1; // ENTRADA
    ANSELFbits.ANSELF1 = 0; // Digital
    WPUFbits.WPUF1 = 0; // habilitado pull up
    INLVLFbits.INLVLF1 = 0; // TTL
    SLRCONFbits.SLRF1 = 1; // Limitado
    ODCONFbits.ODCF1 = 0; // Push Pull 
    


//PPS RX - rf1
    
    U1RXPPS = 0b101001; //Peripheral input is from PORTx Pin 1 (Rx1)


}


void UART_Print_Char(char a){
    {
        while(U1ERRIRbits.TXMTIF==0);
        U1TXB = a;
    }
}

void UART_Print_String(char *a){

    char *ptr;
    ptr = a;
    
    while(*ptr)  
        UART_Print_Char(*ptr++);
    
    
}

void putch(char data_x){
    
UART_Print_Char(data_x);

}