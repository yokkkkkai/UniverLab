#include "root.h"
#include <cmath>
#include <cstdlib>

double root_k(double x, int k, double eps, double* &array, int& cnt) {
    if (x == 0) return 0;
    if (k <= 0) return -1;

    double y_prev = 1;
    double y_next;
    array[0] = y_prev;

    while (1) {
        double pow_y_prev = pow(y_prev, k - 1);
        if (pow_y_prev == 0) return -1;

        y_next = y_prev + (x / pow_y_prev - y_prev) / k;

        double* tmp = (double*)realloc(array, (cnt + 1) * sizeof(double));
        array = tmp;
        array[cnt] = y_next;

        if (fabs(y_next - y_prev) < eps) return y_next;

        y_prev = y_next;
        cnt++;
    }
}