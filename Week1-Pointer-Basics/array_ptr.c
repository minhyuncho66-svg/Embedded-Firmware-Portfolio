#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>

int main(void) {
    int32_t arr[5] = { 1,2,3,4,5 };
    int32_t* ptr = arr;

    printf("%p, %p\n", ptr, &arr[0]);

    for (int i = 0; i <= 4; i++) {
        printf("%d\n", *(ptr + i));
    }

    for (int i = 0; i <= 4; i++) {
        printf("%p\n", (ptr + i));
    }
}