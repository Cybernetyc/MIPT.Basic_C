#ifndef TEMP_API_C
#define TEMP_API_C
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "temp_api.h"
#include "unistd.h"
#include "struct.h"

result_of_arg_t interface (int argc, char *argv[])     ///< Функция обработки аргументов main
{
  result_of_arg_t out = {0};                           ///< Структура для заполнения данными

  char help = 0;                                       ///< Переменные флаги
  char month = 0;
  char file = 0;
  char err = 0;

  int rez = 0;                                        ///< Переменная для хранения арг. командной строки
  while ((rez = getopt(argc, argv, "hHf:m:")) !=-1){
    switch (rez){                                     ///< Поднять флаг для справки       
      case 'h':
      case 'H':
          help = 1;
          break;
      case 'f':                                       ///< Поднять флаг для последующего введения имени файла
          file = 1;
          strcpy(out.path, optarg);
          break;
      case 'm':                                       ///< Поднять флаг месяца
          month = 1;
          out.mounth = atoi(optarg);
          break;
      case '?':                                       ///< Иное - поднять флаг ошибки
          err = 1;
          break;
    }
  }

  if (err){                                          ///< Если ошибка , обработать с выводом в консоль.
    out.status = ERR;
    print_error_key();
    return out;                                      ///< В main вернуть ошибку
  }

  if (help && (month || file)) {                     ///< Запрос справки + ключ месяца или файла 
    out.status = ERR;                                ///< Ошибка с выводом в консоль
    print_error_help_with_another_key();
    return out;                                      ///< В main вернуть ошибку
  }

  if ((month) && ((out.mounth >12) || (out.mounth < 1))){  ///< Неправильное знаение месяца 
    out.status = ERR;                                      ///< Ошибка с выводом в консоль
    print_error_months();
    return out;                                            ///< В main вернуть ошибку
  }

  if (!file && !month && !help)                            ///< Если нет ключей
    print_help();

  if ((!file) && (month))                                  ///< Если нет ключа файла, но есть месяц
    print_error_key();

  if (help)                                                ///< Если запрос справки
    print_keys();

  if (file){                                               ///< Передали ключ файла
    if (strlen(out.path) !=0 ){                            ///< и существует путь
       out.status = CLC;                                   ///< Отдать на просчёт
       return out;                                         ///< Вернуть в main
    }
    else {
      print_error_key_file();                              ///< Иначе вывод в консоль ошибки
    }
  }

  return out;                                              ///< Вернуть в main out
}

/* Функция подсчёта среднемесячной температуры согласно условия задачи с заглушкой*/
int8_t avr_temp_month (sensor_t *info, int size_info, int month)
{
  long long total_temp = 0;                                ///< Переменная для подсчёта общей температуры
  int counter_of_rec_month = 0;                            ///< Кол-во месяцев в по которым требуется просчёт

  for(int i = 0; i < size_info; i++){                      ///< i меньеш чем общее кол-во записей
    if(info[i].month == month){                            ///< если полуили требуемый месяц
      total_temp += info[i].temperature;                   ///< Просуммировали общую температуру
      counter_of_rec_month ++;                             ///< Кол-во месяцеов инкрементировать
    }
  }
  int8_t avr_t_m = total_temp / counter_of_rec_month;      ///< Вычислить среднемесячную температуру

  return avr_t_m;                                          ///< Вернуть среднемесячную температуру
}

/* Функция вычисления минимальной температуры в месяце согласно условия задачи с заглушкой*/
int8_t min_temp_month (sensor_t *info, int size_info, int month)
{
  int8_t min_temp = 100;                                   ///< Инициализация минимальной температуры
  for(int i = 0; i < size_info; i++)                       ///< Поиск минимальной температуры в массиве
    if(info[i].month == month)
      if (min_temp > info[i].temperature)
          min_temp = info[i].temperature;

  return min_temp;                                         ///< Вернуть минимальную температуру
}

/* Функция вычисления максимальной температуры в месяце согласно условия задачи с заглушкой*/
int8_t max_temp_month(sensor_t *info, int size_info, int month)
{
  int8_t max_temp = -100;                                  ///< Инициализация максимальной температуры
    
  for(int i = 0; i < size_info; i++)                       ///< Поиск максимальной температуры во всех записях
    if(info[i].month == month)                     
      if (max_temp < info[i].temperature)
          max_temp = info[i].temperature;
  
  return max_temp;                                         ///< Вернуть максимальную температуру
}

/* Функция вычисления среднегодовой температуры согласно условия задачи с заглушкой*/
int8_t avr_temp_year (sensor_t *info, int size_info)
{     
  long long total_temp = 0;                                ///< Переменная подсчёта общей температуры

  for (int i = 0; i < size_info; i++)                      ///< Суммируем все записи температуры
    total_temp += info[i].temperature;                   

  int8_t avr_t_y = total_temp / size_info;                 ///< Находим среднегодовую температуру
  return avr_t_y;                                          ///< Вернём среднегодовую температуру
}

/* Функция вычисления минимальной годовой температуры согласно условия задачи с заглушкой*/
int8_t min_temp_year(sensor_t *info, int size_info)
{
  int8_t min_temp = 100;                                   ///< Инициализация минимальной температуры
  for(int i = 0; i < size_info; i++)                       ///< Поик минимальной температуры
    if (min_temp > info[i].temperature) 
      min_temp = info[i].temperature;

  return min_temp;                                         ///< Вернуть значение минимальной температуры  
}

/* Функция вычисления минимальной годовой температуры согласно условия задачи с заглушкой*/
int8_t max_temp_year(sensor_t *info, int size_info)
{
  int8_t max_temp = -100;                                  ///< Инициализация максимальной температуры
  for(int i = 0; i < size_info; i++)                       ///< Поиск максимальной температуры
    if (max_temp < info[i].temperature)
        max_temp = info[i].temperature;

  return max_temp;                                         ///< Вернуть максимальную температуру
}

void print_error_key(void)                                 ///< Ошибка неправильно введёные ключи
{
    puts("\n=========================================");
    puts("=\t\t EROR \t\t\t=");
    puts("=========================================");
    puts("\n\t  No such key exists.\n  Use the -H or -h switches to get help\n");
}

void print_help(void)                                      ///< Подсказка для вызова справки
{
    puts("\n=========================================");
    puts("=    Use the -H or -h key to get help   =");
    puts("=========================================\n");
}

void print_error_months(void)                              ///< Ошибка неверного вводе значения месяца
{
  puts("\n=========================================");
  puts("=\t\t ERROR\t\t\t=");
  puts("=========================================");
  puts("\n   The month must be between 1 and 12\n");
}

void print_error_help_with_another_key(void)               ///< Ошибка неверного ввода ключей
{
  puts("\n=========================================");
  puts("=\t\t ERROR\t\t\t=");
  puts("=========================================");
  puts("\n   The -h switch is entered separately\n\
          from other switches.\n\
  Use the -H or -h switches to get help\n"); 
}

void print_error_key_file(void)                            ///< Ошибка отсутсвия ключа файла
{
  puts("\n=========================================");
  puts("=\t\t ERROR\t\t\t=");
  puts("=========================================");
  puts("\n\t  Path to file = 0.\n  Use the -H or -h switches to get help\n\n");
}

void print_keys(void)                                     ///< Справка по работе с программой
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
  puts(" -f [name of file]               OUTPUT STATISTICS PER YEAR");
  puts(" -f [name of file] -m [mounth]   OUTPUT STATISTICS CURRENT MOUNTH");
}

#endif
