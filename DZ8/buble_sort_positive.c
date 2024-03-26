/*Черкашин Дмитрий. 
Cортировка пузырьком по возрастанию
MFTI BubleSortPositive
24.03.24
Условие:            Изучить сортировку пузырьком
Вход:               Произвольный массив
Выход:              Он же отсортированный в прямой и обратной последовательности
                    с вывовдом на экран */

#include <stdio.h>  // Подключим стандартную библиотеку ввода вывода

void ArrInput(int *arr, int n);            // Объявим прототип функции инициализации
void ArrOutput (int *arr, int n);          // Объявление прототипа функции вывода массива
void ArrSortBubbleIncr(int *arr, int n);   // Объявление прототипа функции сортировки массива пузырьком

int main (void)
{ 
    /* Оъявим n типа int - кол-во элементов массива*/
    int n;

    /* Предложение ввести количество элементов массива*/
    puts("Please enter the number of array elemets:");

WRONG1:

    /* Инициализация переменной n функцией scanf*/
    scanf("%d", &n);

    if (n<1)
    {
        puts("Please enter positive value > 0");
        goto WRONG1;
    }
    
    /* Объявим массив типа cо значениями типа int */
    int arr[n];

    /* Вывов функции инициализации массива */
    ArrInput(arr, n);

    /* Вызов функции сортировки пузырьком*/
    ArrSortBubbleIncr(arr, n);
    
    /* Функцией ArrOuptut произведём вывод конечного значения изменёного массива*/
    ArrOutput(arr, n);

    return 0;
}

/* Функция ArrInput инициализации массива 
Принимает: 
1)Указатель на массив 
2)Переменную n типа int - длину массива
Ничего не возвращает*/
void ArrInput(int *arr, int n)
{
    printf("Please enter the value of %d elements of array"
    "separated by space:\n", n);
    for (int i=0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    return;
}

/* Функция ArrSortBubbleIncr сортировки пузырьком по возрастанию*/
void ArrSortBubbleIncr(int *arr, int n)
{
    int arr_var;
    /* Общее количество проходов по массиву n-1*/
    for (int i = 0; i < n-1; i++)
    {
        /* Двигаемся от крайнего правого элемента пока
        счётчик итерации больше предыдущего счётчика*/
        for (int j = n-1 ; j > i; j--)
        {
            /* Если элемент левее больше чем элемент правее*/
            if (arr[j-1]>arr[j])
            {
                /* Поменяем их местами через доп переменную*/
                arr_var=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=arr_var;
            }
        }
    }
}

/* Функция ArrOutput для вывода значений в массиве
Принимает:
1) Указатель на массив 
2) Переменную типа int - длину массива
Возвращает:
1) Выводит поэлементно значение массива. Ничего не возвращает */
void ArrOutput (int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}