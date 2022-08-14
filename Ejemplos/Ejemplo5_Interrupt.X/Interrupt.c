
#include "Interrupt.h"
#include <xc.h>
#include <stdbool.h>

extern volatile bool Flag;
void Interrupt_Config(void){

  /*INT0*/  //RB0
    TRISB |= (1<<0);//RB0 ENTRADA
    ANSELB &= ~(1<<0);//PIN DIGITAL
    WPUB |=  (1<<0);//pull-up on
    INLVLB &= ~(1<<0);//TTL
    ODCONB &= ~(1<<0);//PushPull
    SLRCONB |= (1<<0);//Limit Rate
   /*INT1*/  //RB1
    TRISB |= (1<<1);//RB0 ENTRADA
    ANSELB &= ~(1<<1);//PIN DIGITAL
    WPUB |=  (1<<1);//pull-up on
    INLVLB &= ~(1<<1);//TTL
    ODCONB &= ~(1<<1);//PushPull
    SLRCONB |= (1<<1);//Limit Rate
     
    //Configuracion INT0 
    PIE1bits.INT0IE = 1;//habilito la interrupcion INT0
    PIR1bits.INT0IF = 0;//limpio la bandera
    IPR1bits.INT0IP = 1;//High priority
    
    //Configuracion INT1  
    PIE6bits.INT1IE = 1;//Habilitamos la interrupcion Int1
    PIR6bits.INT1IF = 0;//limpio la bandera
    IPR6bits.INT1IP = 1;//High priority
    
    INTCON0bits.IPEN = 1; //habilito las prioridades
    INTCON0bits.GIEH = 1; //habilito las interrupciones globales
    INTCON0bits.GIEL = 1; //habilito las interrupciones de baja prioridad
    
   //INTERRUPCIONES POR CAMBIO DE ESTADO
    PIE0bits.IOCIE = 1;//habilitamos IOC
    PIR0bits.IOCIF = 0;//limpio la bandera
    IPR1bits.INT0IP = 0;//Low priority
    
    //configuracion individual
    IOCBNbits.IOCBN4 = 1;//detecte 0
    IOCBPbits.IOCBP4 = 0;//desabilitamos
    IOCBFbits.IOCBF4 = 0;//limpiamos el flag
    
    
    
    /*Ubicacione del Vector Interrupcion*/
    //IVTBASE -> 00000400h
    di();//disable interrup
    //IVTBASE = IVTBASEU + IVTBASEH + IVTBASEL
    
    IVTBASEU = 0x00;//5 bits
    IVTBASEH = 0x04;//8 bits
    IVTBASEL = 0x00;//8 bits
    ei();//enable interrupt

}


void __interrupt(irq(IRQ_INT0,IRQ_INT1,IRQ_U4TX),base(0x400),high_priority) INT0_ISR(void){

    //INT0
    if (PIR1bits.INT0IF == 1) {
    LATF ^= (1<<3);
    PIR1bits.INT0IF  = 0;
    }
    //INT1
    if (PIR6bits.INT1IF == 1) {
    LATF ^= (1<<2);
    PIR6bits.INT1IF  = 0;
    }
}

void __interrupt(irq(IRQ_IOC,IRQ_SPI2),base(0x400),low_priority) IOC_ISR(void){
  if (IOCBFbits.IOCBF4 == 1) {
    LATF ^= (1<<1);
    IOCBFbits.IOCBF4 = 0;
    }
}