#ifndef TEMP_API_H
#define TEMP_API_H
#include <stdint.h>
#include "struct.h"

    /* Прототипы функций согласно условия задачи */
    int8_t avr_temp_month (int size_info, sensor *info, int year, int month);
    int8_t min_temp_month (int size_info, sensor *info, int year, int month);
    int8_t max_temp_month (int size_info, sensor *info, int year, int month);
    int8_t avr_temp_year  (int size_info, sensor *info, int year);
    int8_t min_temp_year  (int size_info, sensor *info, int year);
    int8_t max_temp_year  (int size_info, sensor *info, int year);
    
#endif