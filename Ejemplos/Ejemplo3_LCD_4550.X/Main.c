/* 
 * File:   Main.c
 * Author: HP
 *
 * Created on 13 de agosto de 2022, 03:43 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <builtins.h>
#include "Configuracion.h"
#include "LCD_PIC.h"


//CORAZON
//  0x0A,
//  0x1F,
//  0x1F,
//  0x1F,
//  0x0E,
//  0x04,
//  0x00,
//  0x00

int main(int argc, char** argv) {
    
    ConfigClock();
    LCD_PIC_Init();
    
    LCD_PIC_New_Char(1,0x0A,0x1F,0x1F,0x1F,0x0E,0x04,0x00,0X00);
    LCD_PIC_New_Char(2,0x0E,0x1F,0x15,0x1F,0x0E,0x0E,0x00,0x00);
    LCD_PIC_New_Char(3,0x03,0x07,0x09,0x09,0x09,0x1B,0x1B,0x00);
    LCD_PIC_SetCursor(0,Fila1);
    LCD_PIC_String("Bienvenidos :3"); 
    LCD_PIC_SetCursor(0,Fila2);
    LCD_PIC_String("Al Curso de"); 
    LCD_PIC_SetCursor(0,Fila3);
    LCD_PIC_String("PIC en C"); 
    LCD_PIC_SetCursor(0,Fila4);
    LCD_PIC_String("Umaker");
    __delay_ms(1000);
    __delay_ms(1000);
    LCD_PIC_Clear();
    LCD_PIC_Home();
    LCD_PIC_SetCursor(0,Fila1);
    LCD_PIC_String("Bienvenidos :3"); 
    LCD_PIC_SetCursor(0,Fila2);
    LCD_PIC_String("PIC18F57Q43");
    LCD_PIC_Write_New_Char(1);
    LCD_PIC_SetCursor(0,Fila3);
    LCD_PIC_String("PIC en Assembler"); 
    LCD_PIC_Write_New_Char(2);
    LCD_PIC_SetCursor(0,Fila4);
    LCD_PIC_String("Peru-Umaker ");
    LCD_PIC_Write_New_Char(3);
    for(;;){
    
    
    }
    
    
    return (EXIT_SUCCESS);
}

