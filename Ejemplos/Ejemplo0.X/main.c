
#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    asm("nop");
    
    SYSTEM_Initialize();
        
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    while (1)
    {  //****bLINK LED***
        /*   LED0_Toggle();
        __delay_ms(400);
         */
        
       /*BUTTON

        */
        if (SW0_GetValue() == 0) {
            LED0_SetLow();
        }
        else {    
            LED0_SetHigh();
        }

       
    }
}
/**
 End of File
*/