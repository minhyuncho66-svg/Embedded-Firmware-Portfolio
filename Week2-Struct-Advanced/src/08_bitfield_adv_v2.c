#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint32_t PIN0 : 2;
    uint32_t PIN1 : 2;
    uint32_t PIN2 : 2;
    uint32_t PIN3 : 2;
    uint32_t PIN4 : 2;
    uint32_t PIN5 : 2;
    uint32_t PIN6 : 2;
    uint32_t PIN7 : 2;
    uint32_t PIN8 : 2;
    uint32_t PIN9 : 2;
    uint32_t PIN10 : 2;
    uint32_t PIN11 : 2;
    uint32_t PIN12 : 2;
    uint32_t PIN13 : 2;
    uint32_t PIN14 : 2;
    uint32_t PIN15 : 2;
} GPIO_MODER_bits;

typedef union {
    uint32_t all;
    GPIO_MODER_bits bit;

} GPIO_MODER_Union;

int main(void) {
    GPIO_MODER_Union g_GPIO_MODER;
    g_GPIO_MODER.all = 0x00000000;

    printf("초기값: 0x%08X\n\n", g_GPIO_MODER.all);

    g_GPIO_MODER.bit.PIN5 = 1;

    printf("PIN5 출력 설정 후: 0x%08X\n", g_GPIO_MODER.all);
    printf("PIN0=%d, PIN4=%d, PIN5=%d, PIN6=%d\n",
        g_GPIO_MODER.bit.PIN0, g_GPIO_MODER.bit.PIN4,
        g_GPIO_MODER.bit.PIN5, g_GPIO_MODER.bit.PIN6);

    return 0;
}
