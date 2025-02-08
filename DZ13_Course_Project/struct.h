#ifndef STRUCT_H
#define STRUCT_H
#include <stdint.h>

/* Структура согласно условия задачи */
typedef struct
{
    uint16_t year;         ///< год
    uint8_t  month;        ///< месяц
    uint8_t  day;          ///< день  
    uint8_t  hour;         ///< час
    uint8_t  minute;       ///< минуты
    int8_t   temperature;  ///< значение температуры
} sensor_t;                ///< тип структуры, без имени. 

#endif