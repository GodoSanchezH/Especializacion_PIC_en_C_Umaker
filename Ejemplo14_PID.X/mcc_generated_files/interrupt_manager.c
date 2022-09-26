/**
  Generated Interrupt Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    interrupt_manager.h

  @Summary:
    This is the Interrupt Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description:
    This header file provides implementations for global interrupt handling.
    For individual peripheral handlers please see the peripheral driver for
    all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F57Q43
        Driver Version    :  2.12
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above or later
        MPLAB 	          :  MPLAB X 5.45
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "interrupt_manager.h"
#include "mcc.h"
#include "tmr0.h"
#include "pin_manager.h"
#include "uart1.h"
#include "pwm1.h"
#include "../PID.h"
#include <stdio.h>
#include <string.h>

uint16_t PULSOS;
float  rpm,FrecAngular;
char data_TX[50],data_RX[50];
float ref;
extern ControladorPID MotorDC;
float U;
char byte;
uint8_t j=0;
void  INTERRUPT_Initialize (void)
{
    // Enable Interrupt Priority Vectors
    INTCON0bits.IPEN = 1;

    // Assign peripheral interrupt priority vectors

    // URXI - high priority
    IPR4bits.U1RXIP = 1;


    // TMRI - low priority
    IPR3bits.TMR0IP = 0;    

    // UTXI - low priority
    IPR4bits.U1TXIP = 0;    

}

void __interrupt() INTERRUPT_InterruptManagerHigh (void)
{
   // interrupt handler
    if(PIE4bits.U1RXIE == 1 && PIR4bits.U1RXIF == 1)
    {
        UART1_RxInterruptHandler();
        
         byte = U1RXB;
    
    if (byte == 'D') {
        M1_SetHigh();
        M2_SetLow();
    }
    else     if (byte == 'I') {
        M2_SetHigh();
        M1_SetLow();
    }
    else if(byte=='x'){
            ref = atof(data_RX);
            memset(data_RX,0,j);
            j=0;
    
    }else{
    
        data_RX[j]=byte;
        j++;
    }

    }
    else
    {
        //Unhandled Interrupt
    }
}

void __interrupt(low_priority) INTERRUPT_InterruptManagerLow (void)
{
    // interrupt handler
    if(PIE3bits.TMR0IE == 1 && PIR3bits.TMR0IF == 1)
    {
        TMR0_ISR();
          PULSOS = (TMR1H<<8) + TMR1L;
    TMR1H =0;
    TMR1L =0;
    /*calculode rmp y la frecuencia angular*/
    
    rpm = PULSOS*60.0/(0.01*120);
    FrecAngular = rpm*(2*3.14159265359)/60;//W
    
    /*calculo del pid*/
    U = ControladorPID_Calculo(&MotorDC,ref,FrecAngular)*799/12.0;
    
    PWM1_LoadDutyValue((uint16_t) U);
    
    sprintf(data_TX,"%.2f\n\r",FrecAngular);
    UART_Print_String(data_TX);
      memset(data_TX,0,49);
        
        
    }
    else if(PIE4bits.U1TXIE == 1 && PIR4bits.U1TXIF == 1)
    {
        UART1_TxInterruptHandler();
    }
    else
    {
        //Unhandled Interrupt
    }
}
/**
 End of File
*/
