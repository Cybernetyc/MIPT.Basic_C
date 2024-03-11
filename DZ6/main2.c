/*
Черкашин Дмитрий. 
Домашнее задание №6. Задача 2. Cумма от 1 до N
MFTI_Homeworks DZ5 main2.c
11.03.24
Условие:            Написать функцию, которая определяем сумму всех чисел
                    от 1 до N.
Вход:               Целое неотрицательных число N
Выход:              Cумма чисел от 1 до N
*/

#include <stdio.h>

/* Объявим прототип функции 
вычисления суммы от 1 до N*/ 
int summ1_n (int a);

int main (void)
{
    /* Объявим цельночисленную переменную */
    int N;

    /* Предложение ввести число N */
    puts("Please enter the value N");

WRONG: // Метка для возврата к введению числа 

    /* Считывание значеня переменной N функцией scanf */
    scanf("%d",&N);

    /* Ecли введёное число не отвечает условия, просьба
     ввести число зановое*/
    if (N<=0)
    {
        puts("N <= 0. Reenter the value N");
        goto WRONG;
    }
    
    /* Вывод на экран значения суммы числе от 1 до N как требует условие. 
    Аргумент в функцию printf передаёт функция summ1_n */
    printf("Summ 1 ... %d = %d\n",N,summ1_n(N));
    
    return 0;
}

/* Функция summ1_n. принимаемы значения типа int,
 возвращаемые типа int. */
int summ1_n (int a)
{
    /* Объявим и инициализируем 
    переменную summ типа int*/
    int summ = 0;

    /* Посчитаем сумму чисел от 1 до N*/
    for (int i=1; i<=a; i++)
    {
        summ+=i;
    }
 
    // Вернуть вычисленное значение
    return summ;
}