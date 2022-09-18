

#ifndef USART_H
#define	USART_H

#define _XTAL_FREQ 8000000UL
#include <xc.h>
#include <stdint.h>

//Funciones
void Serial_begin(uint32_t baudios);
void printChar_USART(char caracter);
void printString_USART(char *Ptr_string);
void printStringVariable_USART(char *Ptr_string, char *Ptr_variable);
char getChar_USART(void);

#endif	/* USART_H */

