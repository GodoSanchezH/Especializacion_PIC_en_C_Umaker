/* 
 * File:   ADC.h
 * Author: HP
 *
 * Created on 11 de septiembre de 2022, 04:06 PM
 */

#ifndef ADC_H
#define	ADC_H

#include <xc.h>
#include <stdbool.h>
#include <stdint.h>
//Macros
#define AN0 0
#define AN1 1
#define AN2 2
#define AN3 3
#define AN4 4
#define AN5 5
#define AN6 6
#define AN7 7
#define AN8 8
#define AN9 9
#define AN10 10
#define AN11 11
#define AN12 12

//PAraemtros del ADC
#define VREF 5.0
#define RESOLUCION 1023.0
//Variables

//Prototipos de funciones
void ADC_Init(void);
void channel_Read(uint8_t channel);
void start_conversion(void);
bool status_conversion(void);
uint16_t value_result_conversion(void);
uint16_t analogRead( uint8_t canal );

#endif	/* ADC_H */

