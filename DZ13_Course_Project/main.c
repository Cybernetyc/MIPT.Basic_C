/* Черкашин Дмитрий.
ДЗ №13. Курсовой проект. Coздание консольного приложения - Статистика температуры.
08.02.25 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "struct.h"                 ///< Пользовательские заголовки
#include "temp_api.h"
#include "module_for_FILE_read.h"

int main (int argc, char *argv[])
{
  result_of_arg_t abc = interface(argc, argv);  ///< Обработка входных аргументов функции main

  if (abc.status == CLC) ///< Если ключ на подсчёт - обрабатываем файлы
  {
    int size_for_dynamic = FILE_Count_rec (abc.path);                ///< Грубо вычислили требуемое кол-во динамической памяти.
    sensor_t * info = malloc(size_for_dynamic * sizeof(sensor_t));   ///< Выделили память.
    int record_count = FILE_Read(abc.path, info);                    ///< Подсчитали кол-во записей.

    /**
     * Если получен ключи для вычисления месячные температур
     * и номер месяца валиден
     */
    if ( abc.mounth >=1 && abc.mounth <= 12 )
    {
      /**
       * Производим подсчёт:
       * 1. Средней температуры по заданному месяцу
       * 2. Минимальной температуры по заданному месяцу
       * 3. Максимальной температуры по заданному месяца
       */
      int AToM  = avr_temp_month(info, record_count, abc.mounth);
      int MiToM = min_temp_month(info, record_count, abc.mounth);
      int MaToM = max_temp_month(info, record_count, abc.mounth);

      /**
       * Вывод вычисленных значений в stdout:
       * 1. Средней температуры по заданному месяцу
       * 2. Минимальной температуры по заданному месяцу
       * 3. Максимальной температуры по заданному месяцу
       */
      printf("Average Temperature of %d month = %d\n", abc.mounth, AToM);
      printf("Minimum Temperature of %d month = %d\n", abc.mounth, MiToM);
      printf("Maximum Temperature of %d month = %d\n", abc.mounth, MaToM);
    }
      else
    {
      /**
       * Производим подсчёт:
       * 1. Среднегодовой температуры
       * 2. Минимальной годовой температуры
       * 3. Максимальной годовой температуры
       */
      int AToY = avr_temp_year(info, record_count);
      int MiToY = min_temp_year(info, record_count);
      int MaToY = max_temp_year(info, record_count);

      /**
       * Вывод вычисленных значений в stdout:
       * 1. Среднегодовой температуры
       * 2. Минимальной годовой температуры
       * 3. Максимальной годовой температуры
       */
      printf("Average Temperature of year = %d \n", AToY);
      printf("Minimal Temperature of year = %d \n", MiToY);
      printf("Maximal Temperature of year = %d \n", MaToY);
    }

    free(info);   ///< Высвободили динамическую память
    info = NULL;  ///< Указатель в NULL
  }
  return EXIT_SUCCESS;
}
