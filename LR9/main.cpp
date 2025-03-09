#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "root.h"

int main() {
    double x, eps;
    int k;

    printf("Enter number x: ");
    scanf("%lf", &x);

    printf("Enter root degree k: ");
    scanf("%d", &k);

    printf("Enter precision eps: ");
    scanf("%lf", &eps);

    double result = root_k(x, k, eps);

    printf("Answer: %lf\n", result);

    return 0;
}
