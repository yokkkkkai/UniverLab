#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "dtoa.h"

int main() {
    double number = 0;
    int nfr = 0;

    printf("Enter number: ");
    scanf("%lf", &number);

    printf("Enter the number of decimal places: ");
    scanf("%d", &nfr);

    int int_part = dgts((int)number);
    char* str = (char*)malloc(int_part + nfr + 2);

    dtoa(number, int_part + nfr + 1, nfr, str);
    printf("Result: %s\n", str);

    free(str);
    return 0;
}
