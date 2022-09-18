
#include <stdbool.h>
#include <xc.h>
#include "ADC.h"

//Aqui ira el desarrollo de la funciones
void ADC_Init(void){
    ADCON0bits.ADON = 1; //Habilitamos el modulo ADC
    ADCON0bits.GO_DONE = 0; //Inicio con la conversion en reposa
    ADCON1bits.VCFG = 0b00; //Configuro el VREF de la fuente del MCU
    ADCON1bits.PCFG = 0b0000; //Configuro todos los canales analogicos
    ADCON2bits.ADFM = 1; //El Resultado es justificado a la derecha

    ADCON2bits.ACQT = 0b010; //Configuro el tiempo de adquisicion a 4TAD (TAD = 1u)
    ADCON2bits.ADCS = 0b100; //Configuro el prescaler Fosc/4 
}

void channel_Read(uint8_t channel){
    ADCON0bits.CHS = channel;//Selecion del canal 
}

void start_conversion(void){
    ADCON0bits.GO_DONE = 1; //Pongo la conversion en proceso
}

bool status_conversion(void){
    return ADCON0bits.GO_DONE; 
}

uint16_t value_result_conversion(void){
    return ((ADRESH << 8) + ADRESL);
}

uint16_t analogRead( uint8_t canal ){
    channel_Read(canal); //Leo el canal
    start_conversion(); //Inicio la conversion
    while ( status_conversion() == 1 ); //Espero que la conversion termine
    return ((ADRESH << 8) + ADRESL);
}