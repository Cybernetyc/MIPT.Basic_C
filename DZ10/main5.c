/* Черкашин Дмитрий.
Домашнее задание №10. Задача 5. Количество букв.
MFTI_Homeworks DZ10 main3.c
08.04.24
Условие:            В файле .txt считать символьную строку, не более 10 000 символов.
                    Посчитать количество строчных (маленьких) и прописных (больших) букв в введенной строке.
                    Учитывать только английские буквы. Результат записать в файл .txt.

Данные на входе:    Строка состоящая из английских букв, цифр, пробелов и знаков препинания.
Данные на выходе: 	Два целых числа. Количество строчных букв и количество заглавных букв.

Пример №1
Данные на входе: 	aabbAB
Данные на выходе: 	4 2

Пример №2
Данные на входе: 	HELLO WORLD
Данные на выходе: 	0 10         */

/* Подключение библиотеки стандартного ввода-вывода для работы функций*/
#include <stdio.h>

/* *input_fn - указатель на имя файла для чтения input.txt
    тип - char */
char *INPUT_FILE_NAME = "input.txt";

/* *output_fn - указатель на имя файла для чтения input.txt
    тип - char */
char *OUTPUT_FILE_NAME = "output.txt";

int count_letters(int *count_low_case, int *count_capital_letters);
int print_count(int *count_low_case, int *count_capital_letters);


/* main - вход в программу */
int main(void)
{
    /*  i - счётчик строчных букв
       *count_low_case - указатель на него
        тип - int */
    int i = 0;
    int *count_low_case = &i;

    /*  j - счётчик прописных букв
        count_capital_letters - указатель на него
        тип - int*/
    int j = 0;
    int *count_capital_letters = &j;

    /*  Вызов функции подсчёта символов 
        если функция вернула ошибку */
    if (count_letters(count_low_case, count_capital_letters)==1)
    {
        /* Выйти из main c ошибкой */
        return 1;
    }
    
    /*  Вызов функции печати символов в файл 
        если функция вернула ошибку */
    if(print_count(count_low_case, count_capital_letters)==1)
    {
        /* Выйти из main c ошибкой */
        return 1;
    }

    /* Выйти из main без ошибки */
    return 0;
}

/*  count letters - 
Принимает:
1) *arr - указатель на массив arr
2) *var_arr -указатель на массив var_arr
3) count - значение числа считанных элементов
4) space_pointer - индекс символа пробела из массива 
Ничего не возвращает*/
int count_letters(int *count_low_case, int *count_capital_letters)
{
    /* Указатель на файл */
    FILE *fp;

    /*  c - переменная для работы с данными из файла
        тип - char */
    char c;

    /*  Проверка на наличие файла input.txt */
    if ((fp = fopen(INPUT_FILE_NAME, "r")) == NULL)
    {
        /* Вывод ошибки из потока ошибок. */
        perror("Error occured while opening input file!");
        return 1;
    }

    /* Считываем посимвольно пока не конец файла или не перевод строки */
    while (((c = getc(fp)) != EOF) && (c != '\n'))
    {
        /* Если символ - строчная буква */
        if (c <= 'z' && c >= 'a')
        {
            /* Увеличить счётчик строчных букв */
            (*count_low_case)++;
        }
        /* Иначе если символ - прописная буква */
        else if (c <= 'Z' && c >= 'A')
        {
            /* Увеличить счётчик прописных букв */
            (*count_capital_letters)++;
        }
    }
    /* Закрытие файла */
    fclose(fp);
}

int print_count(int *count_low_case, int *count_capital_letters)
{
    /* Указатель на файл */
    FILE *fp;

    if ((fp = fopen(OUTPUT_FILE_NAME, "w")) == NULL)
    {
        /* Вывод ошибки в случае нарушения работы функции*/
        perror("Error occured while opening output file!");
        return 1;
    }
    fprintf(fp, "%d %d", *count_low_case, *count_capital_letters);

    fclose(fp);
}