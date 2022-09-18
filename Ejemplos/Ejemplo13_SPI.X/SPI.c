#include "SPI.h"
#include <xc.h>


void SPI_Init(uint8_t reloj , ModoSPI mood){
//configuro pines digitales
    ADCON1 = 0x0F;

//configuracion de pines
    
    TRISBbits.RB0 = 1;//RB0 -> SDI / MISO
    TRISBbits.RB1 = 0;//rb1 -> sck
    TRISCbits.RC7 = 0;//rc7 -> SDO / MOSI
    TRISDbits.RD0 = 0;//RD0 -> CS / SS
    LATDbits.LD0 = 1;
    //RELOJ DEL SPI
    SSPCON1bits.SSPM  = reloj;
    
    //MODO DE trabajo o sincronizacion
    PIR1bits.SSPIF = 0;
    switch(mood){
        case Modo1:
            SSPSTATbits.CKE = 1;
            SSPCON1bits.CKP = 1;
        break;
        case Modo2:
            SSPSTATbits.CKE = 0;
            SSPCON1bits.CKP = 1;
        break;
        case Modo3:
            SSPSTATbits.CKE = 1;
            SSPCON1bits.CKP = 0;   
        break;
        case Modo4:
            SSPSTATbits.CKE = 0;
            SSPCON1bits.CKP = 0;
        break;
    }
    
    //lectura de datos
    SSPSTATbits.SMP = 0;
    
    //habilitamos todos los pines
    SSPCON1bits.SSPEN = 1;
}

void SPI_TX(uint8_t dato){

    SSPBUF = dato;
     while(SSPSTATbits.BF == 1);
   // PIR1bits.SSPIF=0;
}

