#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int arr[5] = {20, 10, 35, 30, 7};
	int max = *(arr + 0);
	int min = *(arr + 0);

	for (int i = 0; i < 5;i++) {
		if (*(arr + i) > max) {
			max = *(arr + i);
		}
		if (*(arr + i) < min) {
			min = *(arr + i);
		}
	}
	printf("최솟값 : %d, 최댓값 : %d", min, max);
	return 0;
}
////
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int arr[10] = { 1, 10, 4, 9, 2, 3, 8, 5, 7, 6 };
	int x = 5;

	for (int i = 0; i < 10;i++) {
		if (*(arr + i) < x) {
			printf("%d",  * (arr + i));
		}
	}
}
///
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int arr[9] = {3, 29, 38, 12, 57, 74, 40, 85, 61};
	int max = *(arr + 0);
	int max_index = 0;

	for (int i = 0; i < 9;i++) {
		if (max < *(arr + i)) {
			max = *(arr + i);
			max_index = i+1;
		}
	}
	printf("%d, %d", max, max_index);
}
