#include <stdio.h>
#include <stdint.h>

typedef struct {
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
}GPIO_Register_Map;

uint32_t  fake_hardware_memory[2] = { 0, 0 };

int main(void) {
	GPIO_Register_Map* p_gpio = (GPIO_Register_Map*)fake_hardware_memory;
	
	printf("0x%08X\n", p_gpio->MODER);

	p_gpio->MODER = 0x00000400;
	printf("%d, %d", p_gpio->MODER, fake_hardware_memory[0]);
}