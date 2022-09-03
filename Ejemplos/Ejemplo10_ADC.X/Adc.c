#include "Adc.h"
#include <xc.h>

//722

void ADC_Init(void){

    TRISA |= (1<<0);//entrada 
    ANSELA |= (1<<0);//Analogico
    
    ADCON0bits.CS = 0;//FCY
    ADCLK = 0b001111;//FOSC/32 ... 500nS
    ADCON2bits.MD = 0b000;//adc BASIC mode
    ADCON0bits.FM = 1;//
    ADREFbits.NREF = 0;//-AVSS
    ADREFbits.PREF = 0;// vdd
    ADCON0bits.ON = 1;//HABILITO EL ADC
}
uint16_t AnalogRead(Channel Anx){

    ADPCH = Anx;
    ADCON0bits.GO = 1;//inicio la conversion
    while(ADCON0bits.GO == 1);
    
    return ((uint16_t) ((ADRESH<<8)+(ADRESL)));

}
