/* 
 * File:   LCD_PIC.h
 * Author: HP
 *
 * Created on 13 de agosto de 2022, 03:44 PM
 */

#ifndef LCD_PIC_H
#define	LCD_PIC_H

#include "Configuracion.h"
#include <stdint.h>


#define E  LATEbits.LATE2
#define RS LATCbits.LATC7
#define D7 LATDbits.LATD3
#define D6 LATDbits.LATD2
#define D5 LATDbits.LATD1
#define D4 LATDbits.LATD0

typedef enum{
    Fila1=0,
            Fila2,
            Fila3,
            Fila4

}Ubicacion;

void LCD_PIC_DataBus(uint8_t a);
void LCD_PIC_Cmd(uint8_t a);
void LCD_PIC_Init(void);
void LCD_PIC_SetCursor(uint8_t x,Ubicacion y);
void LCD_PIC_Char(char c);
void LCD_PIC_String(char *a);
void LCD_PIC_Clear(void);
void LCD_PIC_Home(void);
void LCD_PIC_Write_New_Char(uint8_t a);
void LCD_PIC_New_Char(uint8_t a,uint8_t b,uint8_t c,uint8_t d,uint8_t e,uint8_t f,uint8_t g,uint8_t h,uint8_t i);
    
#endif	/* LCD_PIC_H */

