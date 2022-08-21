/* 
 * File:   Timer0.h
 * Author: HP
 *
 * Created on August 21, 2022, 4:04 PM
 */

#ifndef TIMER0_H
#define	TIMER0_H


typedef enum{

    M_8bit=0,
    M_16bit 

}TimerModo;

void TimerInit(TimerModo MT);


#endif	/* TIMER0_H */

