/* 
 * File:   Interrupt.h
 * Author: HP
 *
 * Created on August 14, 2022, 3:54 PM
 */

#ifndef INTERRUPT_H
#define	INTERRUPT_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>


void Interrupt_Config(void);
void __interrupt(irq(IRQ_INT0),base(0x400),high_priority) RutinaHP_ISR(void);
void __interrupt(irq(default),base(0x400),low_priority) RutinaLP_ISR(void);


#endif	/* INTERRUPT_H */

