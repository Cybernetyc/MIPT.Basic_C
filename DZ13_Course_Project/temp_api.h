#ifndef TEMP_API_H
#define TEMP_API_H
#include <stdint.h>
#include "struct.h"

typedef enum {
  ERR,          ///< Ошибка
  CLC,          ///< Подсчёт
  HELP,         ///< Помощь
} status_t;

typedef struct       ///< Стктура для хранения обработанных данных
{
  status_t status;   ///< Статус из ENUM
  char mounth;       ///< Месяц
  char path[60];     ///< Путь к файлу
} result_of_arg_t;   

/* Прототипы используемых функций */ 

result_of_arg_t interface (int argc, char *argv[]);                 ///< Обработка аргументов функции main

int8_t avr_temp_month (sensor_t *info, int size_info, int month);   ///< Среднемесячная температура
int8_t min_temp_month (sensor_t *info, int size_info, int month);   ///< Минимальная температура в месяце
int8_t max_temp_month (sensor_t *info, int size_info, int month);   ///< Максимальная температура в месяце
int8_t avr_temp_year  (sensor_t *info, int size_info);              ///< Среднегодовая температура
int8_t min_temp_year  (sensor_t *info, int size_info);              ///< Минимальная годовая температура
int8_t max_temp_year  (sensor_t *info, int size_info);              ///< Максимальная годовая температура
    
void print_help(void);                                              ///< Вывод сообщения о вызове справки
void print_keys(void);                                              ///< Вывод справки по использованию ключей
void print_error_key(void);                                         ///< Вывод ошибки несоответсвия ключей
void print_error_months (void);                                     ///< Вывод ошибки навалидного номера месяца
void print_error_key_file(void);                                    ///< Вывод ошибки пути файла
void print_error_help_with_another_key (void);                      ///< Вывод ошибки и подсказки по ключам

#endif