# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {

	int32_t * pi;
	pi = (int32_t*)malloc(5 * sizeof(int32_t));

	if (pi == NULL) {
		exit(1);
	}
	*pi = 1;
	*(pi + 1) = 2;
	*(pi + 2) = 3;
	*(pi + 3) = 4;
	*(pi + 4) = 5;

	for (int i = 0; i < 5;i++) {
		printf("%d\n", *(pi+i));
	}
	free(pi);
	return 0;
}
/* ================================================
 * [실무 비교] 정적 할당 방식 (차량 SW에서 선호)
 * ================================================
 *
 * 오늘 겪은 문제(HEAP CORRUPTION)처럼,
 * malloc은 범위를 살짝만 벗어나도
 * 이런 심각한 에러가 날 수 있음
 *
 * 정적 할당 예시:
 * #define ARR_SIZE 5
 * int32_t static_arr[ARR_SIZE];
 *
 * → free 필요 없음, 크기가 컴파일 시점에 고정
 * → 차량 ECU, BMS 등에서 이 방식을 표준으로 사용하는 이유:
 *    "예측 가능성"과 "안전성" 때문
 * ================================================ */