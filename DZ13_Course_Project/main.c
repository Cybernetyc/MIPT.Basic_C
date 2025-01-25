/* Черкашин Дмитрий.
Домашнее задание №13. Coздание консольного приложения - Статистика температуры.
MFTI_Homeworks DZ12- temp.c
22.04.24 */

/*  Подключение стандартных библиотек */
#include <stdio.h>
#include <stdint.h>
#include "interface.h"
#include "module_for_FILE_read.h"

/*  Подключение заголовочного файла в котором определена структура*/
#include "struct.h"

/*  Подключение заголовочного файла с протопитами фукнций*/
#include "temp_api.h"

/*  Директива препроцессора для определения длины массива структур */
#define SIZE 100

int main (int argc, char *argv[])
{   
    result_of_arg_t abc = interface(argc, argv);

    if (abc.status == CLC)
        FILE_Read(abc.path);

    /*  info - массив cтруктур 
        SIZE - размер массива 
        тип  - sensor */
    sensor_t info[SIZE];
    
    /*  переменные для передачи в исполняемые функции 
        тип - int */
    int year = 1980 , month=1;
    
    /*
    for (int i = 0; i < argc; i++)
    {
        //printf("i=%i, ARGV[%i] = \"%s\"\n\n", i, i, argv[i]);
        //printf("i+1=%i, ARGV[%i] = \"%s\"\n\n", i+1, i+1, argv[i+1]);

        if (argv[1]== NULL)
        {
            print_help();
        }
        char *var_arr = argv[i];
        if (var_arr[0]=='-')
        {
            switch (var_arr[1])
            {
            case 'h':
            case 'H':
                print_keys();
                break;
            default :
                print_error_key();
            }
        }

    }
    */
    /*  Вызов функции подсчёта среднемесячной температуры 
        с возвратом цельночисленного значения */
    int8_t avr_t_m = avr_temp_month(SIZE, info, year, month);
    
    /*  Вызов функции подсчёта минимальной температуры в текущем месяце 
        с возвратом цельночисленного значения */
    int8_t min_t_m = min_temp_month(SIZE, info, year, month);
    
    /*  Вызов функции подсчёта максимальной температуры в текущем месяце 
        с возвратом цельночисленного значения */
    int8_t max_t_m = max_temp_month(SIZE, info, year, month);
    
    /*  Вызов функции подсчёта среднегодовой температуры 
        с возвратом цельночисленного значения */
    int8_t avr_t_y = avr_temp_year(SIZE, info, year);

    /*  Вызов функции подсчёта минимальной годовой температуры 
        с возвратом цельночисленного значения */
    int8_t min_t_y = min_temp_year(SIZE, info, year);

    /*  Вызов функции подсчёта максимальной годовой температуры 
        с возвратом цельночисленного значения */
    int8_t max_t_y = max_temp_year(SIZE, info, year);

    /*  Вывод значений полученных из функций*/
    /*puts("");
    printf("Average temperature month = %i\n", avr_t_m);
    printf("Minimal temperature month = %i\n", min_t_m);
    printf("Maximal temperature month = %i\n", max_t_m);
    puts("");
    printf("Average temperature year  = %i\n", avr_t_y);
    printf("Minimal temperature year  = %i\n", min_t_y);
    printf("Maximal temperature year  = %i\n", max_t_y);
    puts("");*/
    
    return 0;
}