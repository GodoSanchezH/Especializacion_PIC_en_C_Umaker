/* 
 * File:   Uart.h
 * Author: HP
 *
 * Created on 28 de agosto de 2022, 04:22 PM
 */

#ifndef UART_H
#define	UART_H

#include <stdint.h>



void UART_Init(uint32_t  baudios);
void UART_Print_Char(char a);
void UART_Print_String(char *a);

#endif	/* UART_H */

