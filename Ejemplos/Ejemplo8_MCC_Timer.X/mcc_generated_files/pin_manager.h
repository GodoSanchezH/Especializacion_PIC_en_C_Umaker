/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F57Q43
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set led aliases
#define led_TRIS                 TRISBbits.TRISB4
#define led_LAT                  LATBbits.LATB4
#define led_PORT                 PORTBbits.RB4
#define led_WPU                  WPUBbits.WPUB4
#define led_OD                   ODCONBbits.ODCB4
#define led_ANS                  ANSELBbits.ANSELB4
#define led_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define led_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define led_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define led_GetValue()           PORTBbits.RB4
#define led_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define led_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define led_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define led_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define led_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define led_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define led_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define led_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);




#endif // PIN_MANAGER_H
/**
 End of File
*/