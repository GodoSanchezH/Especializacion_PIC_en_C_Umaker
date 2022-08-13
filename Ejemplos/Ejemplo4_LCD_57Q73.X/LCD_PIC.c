
#include <xc.h>
#include "LCD_PIC.h"

void LCD_PIC_DataBus(uint8_t a){
    // D4 D5 D6 D7 
    //0000 1111
    if(a & 0x1)  D4 = 1;else D4 = 0;
    if(a & 0x2)  D5 = 1;else D5 = 0;
    if(a & 0x4)  D6 = 1;else D6 = 0;
    if(a & 0x8)  D7 = 1;else D7 = 0;
}
void LCD_PIC_Cmd(uint8_t a){
    E = 0;
    E = 1;
    LCD_PIC_DataBus(a);
    __delay_ms(1);
    E = 0;
}

void LCD_PIC_Init(void){

    
    //d0d1d2d3
    TRISD &= ~((1<<0)|(1<<1)|(1<<2)|(1<<3));//RF3 SALIDA
    ANSELD &= ~((1<<0)|(1<<1)|(1<<2)|(1<<3));//PIN DIGITAL
    WPUD &= ~((1<<0)|(1<<1)|(1<<2)|(1<<3));//pull-up off
    INLVLD &= ~((1<<0)|(1<<1)|(1<<2)|(1<<3));//TTL
    ODCOND &= ~((1<<0)|(1<<1)|(1<<2)|(1<<3));//PushPull
    SLRCOND |= (1<<0)|(1<<1)|(1<<2)|(1<<3 );//Limit Rate
    
    //e2
    TRISE &= ~(1<<2);//RF3 SALIDA
    ANSELE &= ~(1<<2);//PIN DIGITAL
    WPUE &= ~(1<<2);//pull-up off
    INLVLE &= ~(1<<2);//TTL
    ODCONE &= ~(1<<2);//PushPull
    SLRCONE |= (1<<2);//Limit Rate
   
    //c7
    TRISC &= ~(1<<7);//RF3 SALIDA
    ANSELC &= ~(1<<7);//PIN DIGITAL
    WPUC &= ~(1<<7);//pull-up off
    INLVLC &= ~(1<<7);//TTL
    ODCONC &= ~(1<<7);//PushPull
    SLRCONC |= (1<<7);//Limit Rate
    
    LCD_PIC_Cmd(0x03);
    LCD_PIC_Cmd(0x03);
    LCD_PIC_Cmd(0x03);
    LCD_PIC_Cmd(0x02);
    LCD_PIC_Cmd(0x02);
    LCD_PIC_Cmd(0x08);
    LCD_PIC_Cmd(0x00);
    LCD_PIC_Cmd(0x08);
    LCD_PIC_Cmd(0x00);
    LCD_PIC_Cmd(0x01);
    LCD_PIC_Cmd(0x00);
    LCD_PIC_Cmd(0x0D);
}


void LCD_PIC_SetCursor(uint8_t x,Ubicacion y){
    RS = 0;
    uint8_t m,n;
    
    switch(y){
        case Fila1:
            m = 0x80+x;
            n = (0x80+x)>>4;
            LCD_PIC_Cmd(n); //alta
            LCD_PIC_Cmd(m); //baja
            
            break;
            
        case Fila2:
            m = 0xC0+x;
            n = (0xC0+x)>>4;
            LCD_PIC_Cmd(n); //alta
            LCD_PIC_Cmd(m); //baja
            
            break; 
            
        case Fila3:
            m = 0x94+x;
            n = (0x94+x)>>4;
            LCD_PIC_Cmd(n); //alta
            LCD_PIC_Cmd(m); //baja
            
            break; 
            
        case Fila4:
            m = 0xD4+x;
            n = (0xD4+x)>>4;
            LCD_PIC_Cmd(n); //alta
            LCD_PIC_Cmd(m); //baja
            
            break;
    
    }

}

void LCD_PIC_Char(char c){// 'a' = 0b1100 1000
    uint8_t m,n;
    m = c;
    n = (c>>4); 
    RS = 1;
    LCD_PIC_Cmd(n); //alta
    LCD_PIC_Cmd(m); //baja
}

void LCD_PIC_String(char *a){
    char *ptr;
    ptr = a;
    while(*ptr)
        LCD_PIC_Char(*ptr++);
}

void LCD_PIC_Clear(void){
    RS = 0;
    LCD_PIC_Cmd(0x00);
    LCD_PIC_Cmd(0x01);
}

void LCD_PIC_Home(void){
    RS = 0;
    LCD_PIC_Cmd(0x00);
    LCD_PIC_Cmd(0x02);
}

void LCD_PIC_New_Char(uint8_t a,uint8_t b,uint8_t c,uint8_t d,uint8_t e,uint8_t f,uint8_t g,uint8_t h,uint8_t i){
    uint8_t m,n;
    switch(a){
        case 1:
        LCD_PIC_Cmd(0x04);
        LCD_PIC_Cmd(0x00);
        RS = 1;
        m=b>>4;
        n=b;
        LCD_PIC_Cmd(m);
        LCD_PIC_Cmd(n);
        m=c>>4;
        n=c;
        LCD_PIC_Cmd(m);
        LCD_PIC_Cmd(n);
        m=d>>4;
        n=d;
        LCD_PIC_Cmd(m);
        LCD_PIC_Cmd(n);
        m=e>>4;
        n=e;
        LCD_PIC_Cmd(m);
        LCD_PIC_Cmd(n);
        m=f>>4;
        n=f;
        LCD_PIC_Cmd(m);
        LCD_PIC_Cmd(n);
        m=g>>4;
        n=g;
        LCD_PIC_Cmd(m);
        LCD_PIC_Cmd(n);
        m=h>>4;
        n=h;
        LCD_PIC_Cmd(m);
        LCD_PIC_Cmd(n);
        m=i>>4;
        n=i;
        LCD_PIC_Cmd(m);
        LCD_PIC_Cmd(n);
        RS = 0;
        LCD_PIC_Cmd(0x00);
        LCD_PIC_Cmd(0x01);
        __delay_ms(100);
        break;
        case 2:
            LCD_PIC_Cmd(0x04);
            LCD_PIC_Cmd(0x08);
           RS = 1;
        m=b>>4;
        n=b;
        LCD_PIC_Cmd(m);
        LCD_PIC_Cmd(n);
        m=c>>4;
        n=c;
        LCD_PIC_Cmd(m);
        LCD_PIC_Cmd(n);
        m=c>>4;
        n=c;
        LCD_PIC_Cmd(m);
        LCD_PIC_Cmd(n);
        m=d>>4;
        n=d;
        LCD_PIC_Cmd(m);
        LCD_PIC_Cmd(n);
        m=e>>4;
        n=e;
        LCD_PIC_Cmd(m);
        LCD_PIC_Cmd(n);
        m=f>>4;
        n=f;
        LCD_PIC_Cmd(m);
        LCD_PIC_Cmd(n);
        m=g>>4;
        n=g;
        LCD_PIC_Cmd(m);
        LCD_PIC_Cmd(n);
        m=h>>4;
        n=h;
        LCD_PIC_Cmd(m);
        LCD_PIC_Cmd(n);
        m=i>>4;
        n=i;
        LCD_PIC_Cmd(m);
        LCD_PIC_Cmd(n);
        RS = 0;
        LCD_PIC_Cmd(0x00);
        LCD_PIC_Cmd(0x01);
        __delay_ms(100);
        break;
        case 3:
            LCD_PIC_Cmd(0x04);
            LCD_PIC_Cmd(0xFF);
        RS = 1;
        m=b>>4;
        n=b;
        LCD_PIC_Cmd(m);
        LCD_PIC_Cmd(n);
        m=c>>4;
        n=c;
        LCD_PIC_Cmd(m);
        LCD_PIC_Cmd(n);
        m=d>>4;
        n=d;
        LCD_PIC_Cmd(m);
        LCD_PIC_Cmd(n);
        m=e>>4;
        n=e;
        LCD_PIC_Cmd(m);
        LCD_PIC_Cmd(n);
        m=f>>4;
        n=f;
        LCD_PIC_Cmd(m);
        LCD_PIC_Cmd(n);
        m=g>>4;
        n=g;
        LCD_PIC_Cmd(m);
        LCD_PIC_Cmd(n);
        m=h>>4;
        n=h;
        LCD_PIC_Cmd(m);
        LCD_PIC_Cmd(n);
        m=i>>4;
        n=i;
        LCD_PIC_Cmd(m);
        LCD_PIC_Cmd(n);
        RS = 0;
        LCD_PIC_Cmd(0x00);
        LCD_PIC_Cmd(0x01);
        __delay_ms(100);
        break;
    }
}

void LCD_PIC_Write_New_Char(uint8_t a){
    RS = 1;
    LCD_PIC_Cmd(0x00);
    LCD_PIC_Cmd(a-1);
    RS = 0;
}


