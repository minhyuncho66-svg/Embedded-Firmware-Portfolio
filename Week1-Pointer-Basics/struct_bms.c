# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct BMS_Data {
	int16_t temperature;
	uint8_t humidity;
	uint32_t timestamp;
}BMS;
void sc(BMS* pdata);

int main(void) {
	BMS data = { 0,0,0 };
	printf("업데이트 전 값 = %d, %d, %d\n", data.temperature, data.humidity,data.timestamp);
	
	sc(&data);
	printf("업데이트 후 값 = %d, %d, %d\n", data.temperature, data.humidity, data.timestamp);

	printf("%d vs %d",sizeof(BMS), sizeof(data));
}
void sc(BMS* pdata) {
	if (pdata == NULL) {
		exit(1);
	}
	pdata->temperature = 25;
	pdata->humidity = 60;
	pdata->timestamp = 1000;
}
