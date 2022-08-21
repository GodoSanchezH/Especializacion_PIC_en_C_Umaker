
#include "Interrupt.h"
#include <xc.h>
#include <stdbool.h>


void Interrupt_Config(void){

  
    INTCON0bits.GIEH = 1;//Habil. Int. High
    INTCON0bits.GIEL = 1;//Habil. Int. Low
    INTCON0bits.IPEN = 1;//Habil. Prioridad
    
    PIE3bits.TMR0IE = 1;//habilitamos la Int. Timer0
    PIR3bits.TMR0IF = 0;//limpiamos la bandera
    IPR3bits.TMR0IP = 1;//High Priority
    
    
    
    /*Ubicacione del Vector Interrupcion*/
    //IVTBASE -> 00000400h
    di();//disable interrup
    //IVTBASE = IVTBASEU + IVTBASEH + IVTBASEL
    
    IVTBASEU = 0x00;//5 bits
    IVTBASEH = 0x04;//8 bits
    IVTBASEL = 0x00;//8 bits
    ei();//enable interrupt

}


void __interrupt(irq(IRQ_TMR0),base(0x400),high_priority) RutinaHP_ISR(void){

    LATB ^= (1<<4);
        TMR0L = 125;
   // TMR0H = 0XFF;
    PIR3bits.TMR0IF = 0;//limpiamos la bandera
    
}
void __interrupt(irq(default),base(0x400),low_priority) RutinaLP_ISR(void){

}