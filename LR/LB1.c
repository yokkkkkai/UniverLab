#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	double maxNum = -1000000, minNum = 100000;
	double number = 1;
	int cnt = 0, cntForMin = 0, cntForMax = 0;
	printf("Enter numbers until it is zero: ");
	while(number != 0) {
		scanf("%lf", &number);
		cnt++;
		if (number < 0) {
			number = -number;
		}
		if (number > maxNum) {
			maxNum = number;
			cntForMax = cnt;
		}
		if (number < minNum && number != 0) {
			minNum = number;
			cntForMin = cnt;
		}
	}

	printf("Max absolute number: %lf\n", maxNum);
	printf("Max number position: %d\n", cntForMax);
	
	printf("Minimum absolute number: %lf\n", minNum);
	printf("Min number position: %d", cntForMin);

	return 0;
}

// найти и вывести также номер этого числа
// то же для минимума
// добавить условие остановки ввода если введен 0