#include "root.h"
#include <math.h>

double root_k(double x, int k, double eps) {
    if (x == 0) return 0;
    if (k <= 0) return -1;

    double y_prev = x / k;
    double y_next;

    while (1) {
        double pow_y_prev = pow(y_prev, k - 1);
        if (pow_y_prev == 0) return -1;

        y_next = y_prev + (x / pow_y_prev - y_prev) / k;

        if (fabs(y_next - y_prev) < eps) return y_next;

        y_prev = y_next;
    }
}