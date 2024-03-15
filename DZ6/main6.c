/*
Черкашин Дмитрий. 
Домашнее задание №6. Задача 5. Наибольший общий делитель
MFTI_Homeworks DZ5 main5.c
12.03.24
Условие:            Написать функцию нахождения НОД двух чисел
                    Привести пример использования
Вход:               Два целых положительных числа
Выход:              Одно целое число - НОД
*/

#include <stdio.h> 
#include <math.h>

const float PI = 3.1415926535; // объявим константу PI 

double cosx(double x); // Проптотип функции cos

int main(void)
{
double x;
    scanf("%lf",&x);
    x *= PI/180.0;
    printf("%.3f\n",cosx(x));
    return 0;
}

double cosx(double x)
{
double Xn = x;
double sum = 0.0;
int i = 1;
    do
    {
        sum += Xn;
        Xn *= -1.0 * x * x / ((2 * i) * (2 * i + 1));
        i++;
    }
    while (fabs(Xn) > 0.001);

return sum;
}