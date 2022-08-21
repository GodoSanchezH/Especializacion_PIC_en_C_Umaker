
#include "Timer0.h"
#include <xc.h>


void TimerInit(TimerModo MT){

    switch(MT){
    
        case M_8bit: 
        T0CON0bits.EN = 0;//iniciamos con el timer apagado    
        T0CON0bits.MD16 = 0;//8bits    
        T0CON0bits.OUTPS = 0;//1:1Postscaler 
        T0CON1bits.CS = 0b010;//FCY/4 
        T0CON1bits.T0ASYNC = 0;
        T0CON1bits.T0CKPS = 0b001;// pre 1:2
        TMR0L = 125;
        //TMR0H = 0x00;
        T0CON0bits.EN = 1;  //Habilitamso el timer  
            
            break;
            
        case M_16bit:
 /*? Timer0 mode = 16-bit listo
? Clock Source = FOSC/4 (250 kHz) listo
? Synchronous operation
? Prescaler = 1:1
? Postscaler = 1:2 (T0OUTPS = 1)
In this case, the TMR0_out toggles every two rollovers of TMR0H:TMR0L.
i.e., (0xFFFF)*2*(1/250 kHz) = 524.28 ms*/
        T0CON0bits.EN = 0;//iniciamos con el timer apagado    
        T0CON0bits.MD16 = 1;//16bits    
        T0CON0bits.OUTPS = 0b0001;//1:2 Postscaler 
        T0CON1bits.CS = 0b010;//FCY/4 
        T0CON1bits.T0ASYNC = 0;
        T0CON1bits.T0CKPS = 0b0000;// pre 1:1
        TMR0L = 0XFF;
        TMR0H = 0XFF;
        T0CON0bits.EN = 1;  //Habilitamso el timer  
            break;
    
    }



}
