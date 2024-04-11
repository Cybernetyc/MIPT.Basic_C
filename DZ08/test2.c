#include <stdio.h>

int main()
{
    // Для всех типов данных размера адресов (и размеры значений в указател
    //определяется только архитектурой
    char x = 0;
    long y = 22222;
    printf("Разрядность адресной шины %d-bit! Через адрес любой переменной\n\n", sizeof(&y)*8);
    
    // Для переменой типа инт создаем указатель и смотрим что он имеет:
    printf("Hello, int pointer!\n");
    int a = 10;
    int *p = &a;
    printf("- a (value): %d, &a(address) : %p\n", a, &a);
    printf("- p(address of a): %p, *p (value of a): %d, &p  (address of pointer): %p\n\n", p, *p, &p);
    
    // Для переменой типа чар
    printf("Hello, char pointer!\n");
    char b = 'A';
    char *pb = &b;
    printf("- b (value): %d, &b(address) : %p\n", b, &b);
    printf("- pb(address of b): %p, *pb (value of b): %d, &pb  (address of pointer): %p\n\n", pb, *pb, &pb);
    
    // Для массива
    printf("Hello, array pointer!\n");
    int arr[5] = {100, 101, 102, 103, 104};
    int *parr = &arr;
    printf("- arr[0] (value): %d, &arr(address) : %p\n", arr[0], &arr);
    printf("- parr(address of arr): %p, *parr (value of arr): %d, &parr  (address of pointer): %p\n\n", parr, *parr, &parr);
    
    // Печать элементов массива по индексу и по указателю (сдвинули адрес и разыменовали)
    printf(" i, arr[i], *(parr + i\n");
    for (int i=0; i<5;i++)
        printf("- %d) %d,  %d\n", i, arr[i], *(parr + i));

    return 0;
}