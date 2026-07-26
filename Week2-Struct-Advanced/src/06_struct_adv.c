# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct BMS_Cell {
	int16_t voltage;
	int16_t temperature;
};
struct BMS_Module {
	struct BMS_Cell cell[4];
};
struct BMS_Bank {
	struct BMS_Module module[2];
};
struct BMS_Pack {
	struct BMS_Bank bank[2];
};
void update_cell_voltage(struct BMS_Pack* pack, int bank_idx, int module_idx, int cell_idx, int16_t voltage);

int main(void) {
	struct BMS_Pack myPack = {0};

	update_cell_voltage(&myPack, 0, 1, 2, 3700);
	for (int b = 0; b < 2; b++) {          
		for (int m = 0; m < 2; m++) {      
			for (int c = 0; c < 4; c++) { 
				printf("%d\n",myPack.bank[b].module[m].cell[c].voltage);
			}
		}
	}
	printf("%d, %d, %d\n", sizeof(struct BMS_Cell), sizeof(struct BMS_Module), sizeof(struct BMS_Pack));
}
void update_cell_voltage(struct BMS_Pack* pack, int bank_idx,int module_idx, int cell_idx,int16_t voltage) {
	if (pack == NULL) {
		exit(1);
	}
	pack->bank[bank_idx].module[module_idx].cell[cell_idx].voltage = voltage;
}