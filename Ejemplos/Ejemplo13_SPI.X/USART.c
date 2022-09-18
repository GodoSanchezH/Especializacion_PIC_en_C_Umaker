
#include "USART.h"

//Desarrollo de funciones

void printStringVariable_USART(char *Ptr_string, char *Ptr_variable){
    while(*Ptr_string != '\0'){
        printChar_USART(*Ptr_string);
        Ptr_string++;
    }
    
    while(*Ptr_variable != '\0'){
        printChar_USART(*Ptr_variable);
        Ptr_variable++;
    }
}

void printString_USART(char *Ptr_string){
    while(*Ptr_string != '\0'){
        printChar_USART(*Ptr_string);
        Ptr_string++;
    }
}

void printChar_USART(char caracter){
    TXREG = caracter;
    while(TXSTAbits.TRMT == 0); //Esperar hasta que se complete la transmision
}

void Serial_begin(uint32_t baudios){
    //Varibale n para la generacion de bauidos
    uint16_t n = 0;
    //Pines de USART
    TRISCbits.RC6 = 0;//Tx - RC6
    //TRISCbits.RC7 = 1;//Rx - RC7
    //Configuracion de registros USART
    TXSTA = 0b00100100; 
    RCSTA = 0b10010000;
    BAUDCON = 0b00001000; 
    //Generacion de baudios
    n = (uint16_t)( ((_XTAL_FREQ / baudios) / 4) - 1 );
    //Cargar con el valor de n a los registros SPBGH y SPBRG
    SPBRG = n;
    SPBRGH = (n >> 8);
}

//Funcion Adicional para enviar datos por USART con printf() stdio.h
void putch(char c){
    TXREG = c;
    while(TXSTAbits.TRMT == 0);
}

////Funcion que permite la recepcion de carateres por le pin Rx
//char getChar_USART(void){
//    while(PIR1bits.RCIF == 0); //Esperar hasta que se reciba 1 datos por UART
//    //Evaluar el desbordamiento
//    if(RCSTAbits.OERR == 1){
//        RCSTAbits.CREN = 0;
//        NOP(); //Realizo un reatardo de 1 ciclo maquina
//        RCSTAbits.CREN = 1;
//    }
//    return (RCREG);
//}
