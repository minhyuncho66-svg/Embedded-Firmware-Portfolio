# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>

int main()
{
    char x = 'a';
    char* px = &x;

    int16_t int16_t_var = 100;   
    int16_t* pa = &int16_t_var;

    int32_t b = 100000;
    int32_t* pb = &b;

    double y = 3.14;
    double* py = &y;


    printf("%c,%hd,%d,%f\n", *px, *pa, *pb, *py);
    printf("%zd,%zd, %zd, %zd", sizeof(px), sizeof(pa), sizeof(pb), sizeof(py));




}