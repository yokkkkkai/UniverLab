#include "intmod.h"
#include <math.h>
#include <stdexcept>

bool IntMod::isPrime(int n) const {
    if (n <= 1) return false;
    if (n == 2) return true;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }

    return true;
}

int IntMod::md(int a, int b) const {
    return (a % b + b) % b;
}

int IntMod::gcd(int a, int b) const {
    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }

    return a;
}

int IntMod::powerMod(int a, int b, int p) const {
    int res = 1;

    while (b != 0) {
        if (b % 2 == 1) {
            res = (res * a) % p;
        }

        a = (a * a) % p;
        b /= 2;
    }

    return res;
}

void IntMod::equalMods(int mod, int other_mod) const {
    if (mod != other_mod) {
        throw std::invalid_argument("Mods must be equal!");
    }
}

template <typename Operation>
IntMod IntMod::binOp(const IntMod& other, Operation op) const {
    equalMods(mod, other.mod);

    int new_value = op(value, other.value);

    return IntMod(md(new_value, mod), mod);
}

template <typename Operation>
IntMod IntMod::binOpThis(const IntMod& other, Operation op) {
    equalMods(mod, other.mod);

    value = md(op(value, other.value), mod);

    return *this;
}

template <typename Comparison>
bool IntMod::compare(const IntMod& other, Comparison c) const {
    equalMods(mod, other.mod);

    int rem_1 = md(value, mod);
    int rem_2 = md(other.value, mod);

    return c(rem_1, rem_2);
}

IntMod::IntMod() : value(0), mod(2) {}

IntMod::IntMod(int value, int mod) {
    if (!isPrime(mod)) throw std::invalid_argument("Mod must be a prime number!");

    this->value = value;
    this->mod = mod;
}

int IntMod::getValue() const {
    return value;
}

int IntMod::getMod() const {
    return mod;
}

void IntMod::setValue(const int value) {
    this->value = value;
}

void IntMod::setMod(const int mod) {
    if (!isPrime(mod)) throw std::invalid_argument("Mod must be a prime number!");

    this->mod = mod;
}

bool IntMod::operator==(const IntMod& other) const {
    equalMods(mod, other.mod);
    return md(value - other.value, mod) == 0;
}

bool IntMod::operator!=(const IntMod& other) const {
    equalMods(mod, other.mod);
    return !(*this == other);
}

bool IntMod::operator>(const IntMod& other) {
    return compare(other, [](int a, int b) {return a > b; });
}

bool IntMod::operator>=(const IntMod& other) {
    return compare(other, [](int a, int b) {return a >= b; });
}

bool IntMod::operator<(const IntMod& other) {
    return compare(other, [](int a, int b) {return a < b; });
}

bool IntMod::operator<=(const IntMod& other) {
    return compare(other, [](int a, int b) {return a <= b; });
}

IntMod& IntMod::operator=(const IntMod& other) {
    if (this == &other) return *this;

    if (mod != other.mod) {
        if (!isPrime(mod)) throw std::invalid_argument("Mod must be a prime number!");

        mod = other.mod;
    }

    value = other.value;
    return *this;
}

IntMod IntMod::operator+(const IntMod& other) const {
    return binOp(other, [](int a, int b) {return a + b; });
}

IntMod IntMod::operator+=(const IntMod& other) {
    return binOpThis(other, [](int a, int b) {return a + b; });
}

IntMod IntMod::operator-(const IntMod& other) const {
    return binOp(other, [](int a, int b) {return a - b; });
}

IntMod IntMod::operator-=(const IntMod& other) {
    return binOpThis(other, [](int a, int b) {return a - b; });
}

IntMod IntMod::operator*(const IntMod& other) const {
    return binOp(other, [](int a, int b) {return a * b; });
}

IntMod IntMod::operator*=(const IntMod& other) {
    return binOpThis(other, [](int a, int b) {return a * b; });
}

IntMod IntMod::operator/(const IntMod& other) {
    if (other.value == 0) throw std::invalid_argument("Diviver can not be zero!");
    if (gcd(other.value, mod) != 1) throw std::invalid_argument("The number and modulus must be coprime!");
    equalMods(mod, other.mod);

    int reverse_value = powerMod(other.value, mod - 2, mod);

    return *this * IntMod(reverse_value, mod);
}

IntMod IntMod::operator/=(const IntMod& other) {
    if (other.value == 0) throw std::invalid_argument("Diviver can not be zero!");
    if (gcd(other.value, mod) != 1) throw std::invalid_argument("The number and modulus must be coprime!");
    equalMods(mod, other.mod);

    int reverse_value = powerMod(other.value, mod - 2, mod);
    value = md(value * reverse_value, mod);

    return *this;
}