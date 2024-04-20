#ifndef TEMP_API_C
#define TEMP_API_C
#include <stdint.h>
#include "struct.h"
#include "temp_api.h"

/* Функция подсчёт среднемесячной температуры согласно условия задачи с заглушкой*/
int8_t avr_temp_month(int size_info, sensor *info, int year, int month)
{   
    int8_t avr_t_m = 1;
    return avr_t_m;
}

/* Функция вычисления минимальной температуры в месяце согласно условия задачи с заглушкой*/
int8_t min_temp_month(int size_info, sensor *info, int year, int month)
{
    int8_t min_t_m = 2;
    return min_t_m;
}

/* Функция вычисления максимальной температуры в месяце согласно условия задачи с заглушкой*/
int8_t max_temp_month(int size_info, sensor *info, int year,  int month)
{
    int8_t max_t_m = 3;
    return max_t_m;
}

/* Функция вычисления среднегодовой температуры согласно условия задачи с заглушкой*/
int8_t avr_temp_year(int size_info, sensor *info, int year)
{
    int8_t avr_t_y = 4;
    return avr_t_y;
}

/* Функция вычисления минимальной годовой температуры согласно условия задачи с заглушкой*/
int8_t min_temp_year(int size_info, sensor *info, int year)
{
    int8_t min_t_y = 5;
    return min_t_y;
}

/* Функция вычисления минимальной годовой температуры согласно условия задачи с заглушкой*/
int8_t max_temp_year(int size_info, sensor *info, int year)
{
    int8_t max_t_y = 6;
    return max_t_y;
}

#endif 