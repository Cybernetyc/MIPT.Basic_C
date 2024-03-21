/* Черкашин Дмитрий. 
Домашнее задание №8. Задача 1. Среднее арифметическое чисел.
MFTI_Homeworks DZ7 main1.c
21.03.24
Условие:            Ввести с клавиатуры массив из 5 элементов
                    Найти среднее арифметическое всех элементов массива
Вход:               5 ненулевых чисел через пробел
Выход:              Одно число в формате %.3f*/

#include <stdio.h>  // Подключим стандартную библиотеку ввода вывода
 
int main (void)
{
    /* Объявим беззнаковую цельночисленную типа int*/
    unsigned n;
    float summ=0.0;

    /* Предложение ввести кол-во элементов массива*/
    puts("Please enter the number of array elemets:");

    /* Присвоим значение переменной n функцией scanf*/
    scanf("%d", &n);

    /* Объявим массив данных из n введёных элементов типа int*/
    int arr[n];

    /* Предложение ввести значение элементов массива*/
    printf("Please enter the value of %d array elemets separated by space\n", n);

    /* Инициализируем значения массива циклом for*/
    for (unsigned i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
        summ+=arr[i];
        printf("%f ", summ);
    }
    
      for (unsigned i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("%.3f ",(float)summ/n);
    puts("");
    return 0;
}