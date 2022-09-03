
#include "Interrupt.h"
#include "Uart.h"
#include <xc.h>
#include <stdbool.h>


void Interrupt_Config(void){

  
    INTCON0bits.GIEH = 1;//Habil. Int. High
    INTCON0bits.GIEL = 1;//Habil. Int. Low
    INTCON0bits.IPEN = 1;//Habil. Prioridad
    
    
    PIE4bits.U1RXIE = 1;//enable rx interrupt
    PIR4bits.U1RXIF = 0;//limpiamos la bamdera
    IPR4bits.U1RXIP = 1;//alta prioridad
    
    
    /*Ubicacione del Vector Interrupcion*/
    //IVTBASE -> 00000400h
    di();//disable interrup
    //IVTBASE = IVTBASEU + IVTBASEH + IVTBASEL
    
    IVTBASEU = 0x00;//5 bits
    IVTBASEH = 0x04;//8 bits
    IVTBASEL = 0x00;//8 bits
    ei();//enable interrupt

}
 char dato;

void __interrupt(irq(IRQ_U1RX),base(0x400),high_priority) RutinaHP_ISR(void){
    dato = U1RXB;
    switch(dato){
        case 'A':
          LATF &= ~(1<<3);
          UART_Print_String("Lampara On\n\r");
          break;
        case 'B':
          LATF |= (1<<3); 
          UART_Print_String("Lampara Off\n\r");
        break;  
    
    
    }
            
    
     PIR4bits.U1RXIF = 0;//limpiamos la bamdera
    
}
void __interrupt(irq(default),base(0x400),low_priority) RutinaLP_ISR(void){

}