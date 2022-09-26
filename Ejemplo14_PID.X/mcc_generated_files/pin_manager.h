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

// get/set RC0 procedures
#define RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()              PORTCbits.RC0
#define RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RC0_SetPullup()             do { WPUCbits.WPUC0 = 1; } while(0)
#define RC0_ResetPullup()           do { WPUCbits.WPUC0 = 0; } while(0)
#define RC0_SetAnalogMode()         do { ANSELCbits.ANSELC0 = 1; } while(0)
#define RC0_SetDigitalMode()        do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set M1 aliases
#define M1_TRIS                 TRISEbits.TRISE0
#define M1_LAT                  LATEbits.LATE0
#define M1_PORT                 PORTEbits.RE0
#define M1_WPU                  WPUEbits.WPUE0
#define M1_OD                   ODCONEbits.ODCE0
#define M1_ANS                  ANSELEbits.ANSELE0
#define M1_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define M1_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define M1_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define M1_GetValue()           PORTEbits.RE0
#define M1_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define M1_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define M1_SetPullup()          do { WPUEbits.WPUE0 = 1; } while(0)
#define M1_ResetPullup()        do { WPUEbits.WPUE0 = 0; } while(0)
#define M1_SetPushPull()        do { ODCONEbits.ODCE0 = 0; } while(0)
#define M1_SetOpenDrain()       do { ODCONEbits.ODCE0 = 1; } while(0)
#define M1_SetAnalogMode()      do { ANSELEbits.ANSELE0 = 1; } while(0)
#define M1_SetDigitalMode()     do { ANSELEbits.ANSELE0 = 0; } while(0)

// get/set M2 aliases
#define M2_TRIS                 TRISEbits.TRISE1
#define M2_LAT                  LATEbits.LATE1
#define M2_PORT                 PORTEbits.RE1
#define M2_WPU                  WPUEbits.WPUE1
#define M2_OD                   ODCONEbits.ODCE1
#define M2_ANS                  ANSELEbits.ANSELE1
#define M2_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define M2_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define M2_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define M2_GetValue()           PORTEbits.RE1
#define M2_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define M2_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define M2_SetPullup()          do { WPUEbits.WPUE1 = 1; } while(0)
#define M2_ResetPullup()        do { WPUEbits.WPUE1 = 0; } while(0)
#define M2_SetPushPull()        do { ODCONEbits.ODCE1 = 0; } while(0)
#define M2_SetOpenDrain()       do { ODCONEbits.ODCE1 = 1; } while(0)
#define M2_SetAnalogMode()      do { ANSELEbits.ANSELE1 = 1; } while(0)
#define M2_SetDigitalMode()     do { ANSELEbits.ANSELE1 = 0; } while(0)

// get/set RF0 procedures
#define RF0_SetHigh()            do { LATFbits.LATF0 = 1; } while(0)
#define RF0_SetLow()             do { LATFbits.LATF0 = 0; } while(0)
#define RF0_Toggle()             do { LATFbits.LATF0 = ~LATFbits.LATF0; } while(0)
#define RF0_GetValue()              PORTFbits.RF0
#define RF0_SetDigitalInput()    do { TRISFbits.TRISF0 = 1; } while(0)
#define RF0_SetDigitalOutput()   do { TRISFbits.TRISF0 = 0; } while(0)
#define RF0_SetPullup()             do { WPUFbits.WPUF0 = 1; } while(0)
#define RF0_ResetPullup()           do { WPUFbits.WPUF0 = 0; } while(0)
#define RF0_SetAnalogMode()         do { ANSELFbits.ANSELF0 = 1; } while(0)
#define RF0_SetDigitalMode()        do { ANSELFbits.ANSELF0 = 0; } while(0)

// get/set RF1 procedures
#define RF1_SetHigh()            do { LATFbits.LATF1 = 1; } while(0)
#define RF1_SetLow()             do { LATFbits.LATF1 = 0; } while(0)
#define RF1_Toggle()             do { LATFbits.LATF1 = ~LATFbits.LATF1; } while(0)
#define RF1_GetValue()              PORTFbits.RF1
#define RF1_SetDigitalInput()    do { TRISFbits.TRISF1 = 1; } while(0)
#define RF1_SetDigitalOutput()   do { TRISFbits.TRISF1 = 0; } while(0)
#define RF1_SetPullup()             do { WPUFbits.WPUF1 = 1; } while(0)
#define RF1_ResetPullup()           do { WPUFbits.WPUF1 = 0; } while(0)
#define RF1_SetAnalogMode()         do { ANSELFbits.ANSELF1 = 1; } while(0)
#define RF1_SetDigitalMode()        do { ANSELFbits.ANSELF1 = 0; } while(0)

// get/set RF2 procedures
#define RF2_SetHigh()            do { LATFbits.LATF2 = 1; } while(0)
#define RF2_SetLow()             do { LATFbits.LATF2 = 0; } while(0)
#define RF2_Toggle()             do { LATFbits.LATF2 = ~LATFbits.LATF2; } while(0)
#define RF2_GetValue()              PORTFbits.RF2
#define RF2_SetDigitalInput()    do { TRISFbits.TRISF2 = 1; } while(0)
#define RF2_SetDigitalOutput()   do { TRISFbits.TRISF2 = 0; } while(0)
#define RF2_SetPullup()             do { WPUFbits.WPUF2 = 1; } while(0)
#define RF2_ResetPullup()           do { WPUFbits.WPUF2 = 0; } while(0)
#define RF2_SetAnalogMode()         do { ANSELFbits.ANSELF2 = 1; } while(0)
#define RF2_SetDigitalMode()        do { ANSELFbits.ANSELF2 = 0; } while(0)

// get/set IO_RF3 aliases
#define IO_RF3_TRIS                 TRISFbits.TRISF3
#define IO_RF3_LAT                  LATFbits.LATF3
#define IO_RF3_PORT                 PORTFbits.RF3
#define IO_RF3_WPU                  WPUFbits.WPUF3
#define IO_RF3_OD                   ODCONFbits.ODCF3
#define IO_RF3_ANS                  ANSELFbits.ANSELF3
#define IO_RF3_SetHigh()            do { LATFbits.LATF3 = 1; } while(0)
#define IO_RF3_SetLow()             do { LATFbits.LATF3 = 0; } while(0)
#define IO_RF3_Toggle()             do { LATFbits.LATF3 = ~LATFbits.LATF3; } while(0)
#define IO_RF3_GetValue()           PORTFbits.RF3
#define IO_RF3_SetDigitalInput()    do { TRISFbits.TRISF3 = 1; } while(0)
#define IO_RF3_SetDigitalOutput()   do { TRISFbits.TRISF3 = 0; } while(0)
#define IO_RF3_SetPullup()          do { WPUFbits.WPUF3 = 1; } while(0)
#define IO_RF3_ResetPullup()        do { WPUFbits.WPUF3 = 0; } while(0)
#define IO_RF3_SetPushPull()        do { ODCONFbits.ODCF3 = 0; } while(0)
#define IO_RF3_SetOpenDrain()       do { ODCONFbits.ODCF3 = 1; } while(0)
#define IO_RF3_SetAnalogMode()      do { ANSELFbits.ANSELF3 = 1; } while(0)
#define IO_RF3_SetDigitalMode()     do { ANSELFbits.ANSELF3 = 0; } while(0)

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

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/