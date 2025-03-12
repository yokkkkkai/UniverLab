#include "intmod.h"
#include <iostream>
#include <stdexcept>

template <typename Operation>
void func_test(IntMod obj1, IntMod obj2, Operation op, const std::string& op_name) {
    std::cout << "Testing " << op_name << ":\n";
    std::cout << "Value 1: " << obj1;
    std::cout << "Value 2: " << obj2;

    try {
        IntMod result = op(obj1, obj2);
        std::cout << "Result: " << result << "\n\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Error in " << op_name << ": " << e.what() << "\n\n";
    }
}

template <typename Comparison>
void compare_test(IntMod obj1, IntMod obj2, Comparison cmp, const std::string& cmp_name) {
    try {
        std::cout << "Testing " << cmp_name << ": ";
        std::cout << (cmp(obj1, obj2) ? "true" : "false") << "\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Error in " << cmp_name << ": " << e.what() << "\n";
    }
}

int main() {
    IntMod obj1, obj2;

    try {
        std::cin >> obj1 >> obj2;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "Initial Values:\n";
    std::cout << "Value(1): " << obj1 << "\n";
    std::cout << "Value(2): " << obj2 << "\n\n";

    IntMod copy1 = obj1, copy2 = obj2;

    func_test(copy1, copy2, [](IntMod a, IntMod b) { return a + b; }, "+");
    func_test(copy1, copy2, [](IntMod a, IntMod b) { return a += b; }, "+=");
    func_test(copy1, copy2, [](IntMod a, IntMod b) { return a - b; }, "-");
    func_test(copy1, copy2, [](IntMod a, IntMod b) { return a -= b; }, "-=");
    func_test(copy1, copy2, [](IntMod a, IntMod b) { return a * b; }, "*");
    func_test(copy1, copy2, [](IntMod a, IntMod b) { return a *= b; }, "*=");

    func_test(copy1, copy2, [](IntMod a, IntMod b) { return a / b; }, "/");
    func_test(copy1, copy2, [](IntMod a, IntMod b) { return a /= b; }, "/=");

    compare_test(copy1, copy2, [](IntMod a, IntMod b) { return a == b; }, "==");
    compare_test(copy1, copy2, [](IntMod a, IntMod b) { return a != b; }, "!=");
    compare_test(copy1, copy2, [](IntMod a, IntMod b) { return a > b; }, ">");
    compare_test(copy1, copy2, [](IntMod a, IntMod b) { return a >= b; }, ">=");
    compare_test(copy1, copy2, [](IntMod a, IntMod b) { return a < b; }, "<");
    compare_test(copy1, copy2, [](IntMod a, IntMod b) { return a <= b; }, "<=");

    return 0;
}
