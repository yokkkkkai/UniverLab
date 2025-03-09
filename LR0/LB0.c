#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int number1, number2, number3, number4, result1 = 0, result2 = 0;

	printf("Enter four numbers: ");
	scanf("%d %d %d %d", &number1, &number2, &number3, &number4);

	result1 = number1 * number2;
	printf("Result: %d * %d = %d\n", number1, number2, result1);

	result2 = number1 * number2 - number3 * number4;
	printf("Result: %d * %d - %d * %d = %d", number1, number2, number3, number4, result2);

	return 0;
}

// ввести еще число и вывести разность произведений первого на второе и третьего на четвертое