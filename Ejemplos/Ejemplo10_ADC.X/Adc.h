/* 
 * File:   Adc.h
 * Author: HP
 *
 * Created on 1 de septiembre de 2022, 09:46 PM
 */

#ifndef ADC_H
#define	ADC_H
#include <stdint.h>
typedef enum{
    An0=0,
    An1,
    An2,
    An3,
    An4,
    An5,
    An6
}Channel;

void ADC_Init(void);
uint16_t AnalogRead(Channel Anx);

#endif	/* ADC_H */

