/* 
 * File:   Main.c
 * Author: HP
 *
 * Created on 13 de agosto de 2022, 05:43 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pic18.h>
#include "Configuracion.h"
#include "LCD_PIC.h"

void Config_GPIO(void);

int main(int argc, char** argv) {

    Clock_Config();
      Config_GPIO();
    __delay_ms(3000);
     __delay_ms(3000);
    LCD_PIC_Init();
    LCD_PIC_New_Char(1,0x0A,0x1F,0x1F,0x1F,0x0E,0x04,0x00,0X00);
    LCD_PIC_New_Char(2,0x03,0x07,0x09,0x09,0x09,0x1B,0x1B,0x00);
    LCD_PIC_SetCursor(0,Fila1);
    LCD_PIC_String("Curso PIC en C"); 
    LCD_PIC_Write_New_Char(1);
    LCD_PIC_SetCursor(0,Fila2);
    LCD_PIC_String("Umaker"); 
    LCD_PIC_Write_New_Char(2);
    
  
    for(;;){
  
    LATF ^= (1<<3);
    __delay_ms(200);
    
    
    }
    
    
    return (EXIT_SUCCESS);
}


void Config_GPIO(void) {


    
    TRISF &= ~(1<<3);//RF3 SALIDA
    ANSELF &= ~(1<<3);//PIN DIGITAL
    WPUF &= ~(1<<3);//pull-up off
    INLVLF &= ~(1<<3);//TTL
    ODCONF &= ~(1<<3);//PushPull
    SLRCONF |= (1<<3);//Limit Rate
    
    
    //entrada digital al pin rb4
    TRISB |= (1<<4);//RB4 ENTRADA
    ANSELB &= ~(1<<4);//digital
    WPUB |= (1<<4);//pull-up ON
    INLVLB &= ~(1<<4);//TTL
    ODCONB &= ~(1<<4);//PushPull
    SLRCONB |= (1<<4);//Limit Rate
    
}
       

