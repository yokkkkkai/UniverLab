#include <iostream>
#include "root.h"
#include <cstdlib>

int main() {
    double x, eps;
    int k;
    int cnt = 1;
    double* ptr = (double*)malloc(cnt * sizeof(double));

    std::cout << "Enter number x: ";
    std::cin >> x;

    std::cout << "Enter root degree k: ";
    std::cin >> k;

    std::cout << "Enter precision eps: ";
    std::cin >> eps;

    double result = root_k(x, k, eps, ptr, cnt);

    std::cout << "Answer: " << result << std::endl;

    std::cout << "Intermediate values: " << std::endl;
    for (int i = 0; i < cnt; i++) {
        std::cout << ptr[i] << std::endl;
    }

    free(ptr);

    return 0;
}

// промежуточные значения записывать в динамический массив, вывести его в main после результата 