#include "dtoa.h"
#include <math.h>

int dgts(int n) {
    int cnt = 0;
    if (n == 0) return 1;

    while (n > 0) {
        n /= 10;
        cnt++;
    }
    return cnt;
}

void dtoa(double num, int npos, int nfr, char* str) {
    int i_part = (int)num;
    double fraction = num - i_part;
    int i_digits = dgts(i_part);
    int tmp = i_part;

    for (int i = i_digits - 1; i >= 0; --i) {
        str[i] = '0' + (tmp % 10);
        tmp /= 10;
    }

    str[i_digits] = '.';

    int d_part;
    for (int i = 0; i < nfr; ++i) {
        fraction *= 10;
        d_part = (int)fraction;
        str[i_digits + 1 + i] = '0' + d_part;
        fraction -= d_part;
    }

    str[i_digits + nfr + 1] = '\0';
}