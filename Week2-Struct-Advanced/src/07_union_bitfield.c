#include <stdio.h>
#include <stdint.h>

union myunio {
    int a;
    char b;
    float c;
};

struct flag {
    unsigned int flag_a : 1;
    unsigned int flag_b : 1;
    unsigned int value : 3;
};

int main(void) {

    union myunio pu = {0};

    printf("%p, %p, %p\n", &pu.a,&pu.b, &pu.c);

    pu.a = 65;
    printf("%c\n", pu.b);

    printf("%d, %d\n", sizeof(union myunio),sizeof(pu.c));

    struct flag bit;
    bit.flag_a = 1;
    bit.flag_b = 1;
    bit.value = 10;
    
    printf("%d, %d, %d\n",bit.flag_a, bit.flag_b, bit.value);
    
    printf("%d", sizeof(struct flag));
    return 0;
}