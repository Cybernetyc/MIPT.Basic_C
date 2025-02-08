#ifndef TEMP_API_C
#define TEMP_API_C
#include <stdint.h>
#include <stdio.h>
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

void print_help1(void)
{
    puts("\n=========================================");
    puts("= Use the -H or -h switches to get help =");
    puts("=========================================\n");
}

void print_keys1(void)
{
    puts("\n=========================================");
    puts("\tThis console application\n\
     displays temperature statistics\n\
   collected by the sensor for a year.");
    puts("=========================================");
    puts("\n\tBelow is a list of keys\n\
    that processes this application\n\
           and their purpose.");
    puts("");
}

void print_error_key1(void)
{
    puts("\n=========================================");
    puts("=\t\t EROR \t\t\t=");
    puts("=========================================");
    puts("\n\t  No such key exists.\n  Use the -H or -h switches to get help\n");
}

#endif