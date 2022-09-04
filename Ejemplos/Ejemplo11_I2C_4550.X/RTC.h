/* 
 * File:   RTC.h
 * Author: HP
 *
 * Created on September 4, 2022, 5:52 PM
 */

#ifndef RTC_H
#define	RTC_H

#include <xc.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


void DS1307_Config(void);
void DS1307_Write_Hours_24(uint8_t horas,uint8_t minutos,uint8_t segundos);
void DS1307_Write_Date(uint8_t dia_mes,uint8_t mes ,uint8_t year,uint8_t dia_semana);
void DS1307_Read_H_24(uint8_t *horas ,uint8_t *minutos,uint8_t *segundos);
void DS1307_Read_Date(uint8_t *year ,uint8_t *mes,uint8_t *dia_mes ,uint8_t *dia_semana);


#endif	/* RTC_H */

