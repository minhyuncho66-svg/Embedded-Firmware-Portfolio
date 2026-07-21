# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void swap_wrong(int a, int b);
void swap_correct(int* a, int* b);

int main()
{
	int a = 5;
	int b = 3;
	swap_wrong(a, b);

	printf("main에서의 a=%d, b=%d\n", a, b);

	printf("swap_wrong에서의 a는 %d이고 b는 %d이다\n", a, b);

	swap_correct(&a, &b);

	printf("main에서의 a=%d, b=%d\n", a, b);

	printf("swap_corect에서의 a는 %d이고 b는 %d이다", a, b);

	return 0;
}

void swap_wrong(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}
void swap_correct(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}