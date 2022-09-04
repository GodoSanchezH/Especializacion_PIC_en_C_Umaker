/* 
 * File:   main.c
 * Author: HP
 *
 * Created on 4 de septiembre de 2022, 03:31 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <xc8debug.h>
#include <pic18.h>
#include "Configuracion.h"
#include "I2C.h"
#include "USART.h"
#include "RTC.h"

uint16_t i;
uint8_t Val_H=0, Val_L=0;
//uint8_t Display_7Seg_A[10] = {0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};
//uint16_t dato_sine[481] ={2101,2295,2052,2246,2440,2197,2390,2584,2340,2533,2725,2481,2672,2864,2618,2809,2999,2752,2941,3129,2880,3067,3254,3003,3188,3372,3119,3302,3484,3228,3409,3588,3330,3507,3684,3422,3597,3770,3506,3678,3848,3580,3749,3916,3645,3809,3973,3698,3860,4019,3741,3899,4055,3774,3927,4080,3794,3944,4093,3804,3950,4095,3802,3944,4086,3789,3927,4065,3764,3899,4033,3728,3860,3990,3682,3809,3936,3624,3749,3872,3557,3678,3797,3479,3597,3714,3392,3507,3621,3297,3409,3519,3193,3302,3410,3081,3188,3294,2963,3067,3171,2838,2941,3043,2708,2809,2909,2573,2672,2772,2434,2533,2631,2292,2390,2488,2149,2246,2343,2004,2101,2198,1859,1956,2053,1714,1812,1910,1571,1669,1768,1430,1530,1629,1293,1394,1495,1160,1262,1364,1031,1135,1240,908,1014,1121,792,900,1009,683,794,905,581,695,810,489,605,723,405,525,645,331,454,578,266,393,521,213,343,474,170,303,438,138,275,414,117,258,400,107,252,398,109,258,408,122,275,429,147,303,461,183,343,504,229,393,558,287,454,622,354,525,696,432,605,780,519,695,873,614,794,974,718,900,1083,830,1014,1199,949,1135,1322,1073,1262,1451,1203,1394,1584,1338,1530,1722,1477,1669,1862,1619,1812,2005,1762,1956,2150,1907,2101,2295,2052,2246,2440,2197,2390,2584,2340,2533,2725,2481,2672,2864,2618,2809,2999,2752,2941,3129,2880,3067,3254,3003,3188,3372,3119,3302,3484,3228,3409,3588,3330,3507,3684,3422,3597,3770,3506,3678,3848,3580,3749,3916,3645,3809,3973,3698,3860,4019,3741,3899,4055,3774,3927,4080,3794,3944,4093,3804,3950,4095,3802,3944,4086,3789,3927,4065,3764,3899,4033,3728,3860,3990,3682,3809,3936,3624,3749,3872,3557,3678,3797,3479,3597,3714,3392,3507,3621,3297,3409,3519,3193,3302,3410,3081,3188,3294,2963,3067,3171,2838,2941,3043,2708,2809,2909,2573,2672,2772,2434,2533,2631,2292,2390,2488,2149,2246,2343,2004,2101,2198,1859,1956,2053,1714,1812,1910,1571,1669,1768,1430,1530,1629,1293,1394,1495,1160,1262,1364,1031,1135,1240,908,1014,1121,792,900,1009,683,794,905,581,695,810,489,605,723,405,525,645,331,454,578,266,393,521,213,343,474,170,303,438,138,275,414,117,258,400,107,252,398,109,258,408,122,275,429,147,303,461,183,343,504,229,393,558,287,454,622,354,525,696,432,605,780,519,695,873,614,794,974,718,900,1083,830,1014,1199,949,1135,1322,1073,1262,1451,1203,1394,1584,1338,1530,1722,1477,1669,1862,1619,1812,2005,1762,1956,2150,1907,2101};
 //uint16_t dato_sawboth[481] = {3964,4095,3787,3918,4049,3741,3872,4002,3695,3825,3956,3648,3779,3909,3602,3732,3863,3555,3686,3817,3509,3640,3770,3463,3593,3724,3416,3547,3677,3370,3500,3631,3323,3454,3585,3277,3408,3538,3231,3361,3492,3184,3315,3446,3138,3268,3399,3091,3222,3353,3045,3176,3306,2999,3129,3260,2952,3083,3214,2906,3037,3167,2860,2990,3121,2813,2944,3074,2767,2897,3028,2720,2851,2982,2674,2805,2935,2628,2758,2889,2581,2712,2842,2535,2665,2796,2488,2619,2750,2442,2573,2703,2396,2526,2657,2349,2480,2610,2303,2433,2564,2256,2387,2518,2210,2341,2471,2164,2294,2425,2117,2248,2379,2071,2201,2332,2024,2155,2286,1978,2109,2239,1932,2062,2193,1885,2016,2147,1839,1970,2100,1793,1923,2054,1746,1877,2007,1700,1830,1961,1653,1784,1915,1607,1738,1868,1561,1691,1822,1514,1645,1775,1468,1598,1729,1421,1552,1683,1375,1506,1636,1329,1459,1590,1282,1413,1543,1236,1366,1497,1189,1320,1451,1143,1274,1404,1097,1227,1358,1050,1181,1312,1004,1134,1265,957,1088,1219,911,1042,1172,865,995,1126,818,949,1080,772,903,1033,726,856,987,679,810,940,633,763,894,586,717,848,540,671,801,494,624,755,447,578,708,401,531,662,354,485,616,308,439,569,262,392,523,215,346,476,169,299,430,122,3964,4095,3787,3918,4049,3741,3872,4002,3695,3825,3956,3648,3779,3909,3602,3732,3863,3555,3686,3817,3509,3640,3770,3463,3593,3724,3416,3547,3677,3370,3500,3631,3323,3454,3585,3277,3408,3538,3231,3361,3492,3184,3315,3446,3138,3268,3399,3091,3222,3353,3045,3176,3306,2999,3129,3260,2952,3083,3214,2906,3037,3167,2860,2990,3121,2813,2944,3074,2767,2897,3028,2720,2851,2982,2674,2805,2935,2628,2758,2889,2581,2712,2842,2535,2665,2796,2488,2619,2750,2442,2573,2703,2396,2526,2657,2349,2480,2610,2303,2433,2564,2256,2387,2518,2210,2341,2471,2164,2294,2425,2117,2248,2379,2071,2201,2332,2024,2155,2286,1978,2109,2239,1932,2062,2193,1885,2016,2147,1839,1970,2100,1793,1923,2054,1746,1877,2007,1700,1830,1961,1653,1784,1915,1607,1738,1868,1561,1691,1822,1514,1645,1775,1468,1598,1729,1421,1552,1683,1375,1506,1636,1329,1459,1590,1282,1413,1543,1236,1366,1497,1189,1320,1451,1143,1274,1404,1097,1227,1358,1050,1181,1312,1004,1134,1265,957,1088,1219,911,1042,1172,865,995,1126,818,949,1080,772,903,1033,726,856,987,679,810,940,633,763,894,586,717,848,540,671,801,494,624,755,447,578,708,401,531,662,354,485,616,308,439,569,262,392,523,215,346,476,169,299,430,122,3964};
//uint16_t dato_square[481] = {252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,252};
 
uint8_t decenas,centenas, unidades;

uint8_t HORA,MINUTO,SEGUNDO = 0;
uint8_t YEAR,MES,DIA_MES,DIA_SEMANA=0;

void Ejemplo1(void);
void Ejemplo2(void);
void Ejemplo3(void);

int main(int argc, char** argv) {

    ConfigClock();
    I2C_Init();
    Serial_begin(9600);
    DS1307_Config();
    DS1307_Write_Hours_24(18,30,0);
    DS1307_Write_Date(4,9,22,7);
    
    //printf("hola mundo");
    for(;;){
      
        DS1307_Read_H_24(&HORA,&MINUTO,&SEGUNDO);    
        DS1307_Read_Date(&YEAR,&MES,&DIA_MES,&DIA_SEMANA);
    
        printf("H:%02u M:%02u S:%02u \n\r",HORA,MINUTO,SEGUNDO);
        printf("A:%02u M:%02u D_M:%02u D_S:%02u \n\r",YEAR,MES,DIA_MES,DIA_SEMANA);
        __delay_ms(200);
        
        
    }
    
    
    return (EXIT_SUCCESS);
}
//void Ejemplo1(void){
//        I2C_Start();
//        I2C_Write_Address_Slave(ADDR_PCF1,Modo_Write);
//        I2C_Write_Slave(Display_7Seg_A[1]);
//        I2C_Stop();
//        
//        I2C_Start();
//        I2C_Write_Address_Slave(ADDR_PCF2,Modo_Write);
//        I2C_Write_Slave(Display_7Seg_A[2]);
//        I2C_Stop();
//        
//        I2C_Start();
//        I2C_Write_Address_Slave(ADDR_PCF3,Modo_Write);
//        I2C_Write_Slave(Display_7Seg_A[3]);
//        I2C_Stop();
//        
//        I2C_Start();
//        I2C_Write_Address_Slave(ADDR_PCF4,Modo_Write);
//        I2C_Write_Slave(Display_7Seg_A[4]);
//        I2C_Stop();
//}
//void Ejemplo2(void){
//    
//        for (centenas = 0; centenas < 10; centenas++) {
//            I2C_Start();
//            I2C_Write_Address_Slave(ADDR_PCF3,Modo_Write);
//            I2C_Write_Slave(Display_7Seg_A[centenas]);
//            for (decenas = 0; decenas < 10; decenas++) {
//                I2C_Restart();
//                I2C_Write_Address_Slave(ADDR_PCF2,Modo_Write);
//                I2C_Write_Slave(Display_7Seg_A[decenas]);
//                for (unidades = 0; unidades < 10; unidades++) {
//                    I2C_Restart();
//                    I2C_Write_Address_Slave(ADDR_PCF1,Modo_Write);
//                    I2C_Write_Slave(Display_7Seg_A[unidades]);
//                    __delay_ms(300);
//                }
//
//            }
//            I2C_Stop();
//        }
//
//}
//void Ejemplo3(void){
// for (i = 0; i<481 ;i++)
//		{
//			Val_H = dato_square[i]>>8;
//			Val_L = dato_square[i];
//			
//			I2C_Start();
//			I2C_Write_Address_Slave(0b11000000,Modo_Write);
//			I2C_Write_Slave(Val_H);
//			I2C_Write_Slave(Val_L);
//			I2C_Stop();
//			__delay_ms(5);
//		}
//
//}
//
