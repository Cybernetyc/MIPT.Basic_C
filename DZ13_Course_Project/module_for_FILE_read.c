#include "module_for_FILE_read.h"
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>

int FILE_Read(char path[], sensor_t info[])  ///< Функция чтения данных их файла
{
  char string[60] = {0};                     ///< Буфферный массив для хранения промежуточных данных
  sensor_t temp_rec;                         ///< Буфферная структура для промежуточных хранений данных 
  FILE *f;                                   ///< Указатель на файл
  f = fopen(path,"r");                       ///< Открыть файл из пути на чтение
    
  int record_counter = 0;                    ///< Переменная для подсчёта кол-ва записей.
    
  for(int i = 0; (fscanf (f, "%[^\n]\n", string) == 1); i++){    ///< Вычитали строку из файла
      if (sscanf (string, "%hd;%hhd;%hhd;%hhd;%hhd;%hhd", &temp_rec.year, &temp_rec.month,  &temp_rec.day,
      /* Если не успешно распарсили в структуру*/         &temp_rec.hour, &temp_rec.minute, &temp_rec.temperature) != 6)
      {
        printf("Line number №%d. Impossible to read\n", i);      ///< Вывод строки с кривыми данными
        continue;                                                ///< Продолжить считывание
      }
      info[record_counter++] = temp_rec;                         ///< Переписали структуру  
    }
    
  fclose(f);                                         ///< Закрыли файл. 
  return record_counter;                             ///< Вернули кол-во записей
}

int FILE_Count_rec (char path[])                     ///< Функция для грубого подсчёта памяти
{                                                    ///< считаем сколько памяти отдать в malloc
  FILE *f;                                           ///< Указатель на файл
  f = fopen(path,"r");                               ///< Открыть файл из пути на чтение
  int fseek(FILE *stream, long offset, int origin);  

  if (fseek(f, 0, SEEK_END) == -1){                  ///< Указатель файла в конец
    perror("FSEEK ERROR. Don't Find EOF");           ///< Ошибка если не нашёлся
    exit(-1);
  }
   
  long size_of_file = ftell(f);                      ///< Получение размера файла

  int size_for_dynamic = size_of_file * 1.2 / 18.0;  ///< Грубый подсчёт требуемого кол-ва памяти
  return size_for_dynamic;                           ///< Вернуть подсчитанное значение
}