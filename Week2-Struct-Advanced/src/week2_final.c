#include <stdio.h>
#include <stdint.h>

typedef struct {
	uint32_t a;
	uint32_t b;
}Cell;

typedef struct {
	Cell cell[4];
}Module;

typedef struct{
	Module module[3];
}Bank;

typedef struct {
	uint32_t PIN5 : 2;
}GPIO_register;

typedef union {
	uint32_t all;
	GPIO_register bit;
}u_gpio;

int main(void){
	Bank my_m = { 0 };
	my_m.module[1].cell[1].a = 10;
	
	printf("%d\n", my_m.module[1].cell[1].a);

	u_gpio a;
	a.all = 0x00000000;
	a.bit.PIN5 = 1;
	printf("%d", a.bit.PIN5);

	return 0;
}
