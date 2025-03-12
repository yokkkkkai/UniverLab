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

bool IntMod::equalMods(int mod, int other_mod) const {
    return mod == other_mod;
}

int IntMod::new_prime(int num) const {
    if (num < 2) return 2;
    if (isPrime(num)) return num;

    int left = num - 1;
    int right = num + 1;

    while (true) {
        if (left >= 2 && isPrime(left)) return left;
        if (isPrime(right)) return right;

        left--;
        right++;
    }
}

int IntMod::new_mod(int mod, int other_mod) const {
    if (equalMods(mod, other_mod)) return mod;

    int lcm = mod * other_mod;

    return new_prime(lcm);
}

template <typename Operation>
IntMod IntMod::binOp(const IntMod& other, Operation op) const {
    int n_mod = new_mod(mod, other.mod);
    int n_value = md(op(value, other.value), n_mod);

    return IntMod(n_value, n_mod);
}

template <typename Operation>
IntMod IntMod::binOpThis(const IntMod& other, Operation op) {
    int n_mod = new_mod(mod, other.mod);
    value = md(op(value, other.value), n_mod);
    mod = n_mod;

    return *this;
}

template <typename Comparison>
bool IntMod::compare(const IntMod& other, Comparison c) const {
    if (!equalMods(mod, other.mod)) {
        throw std::invalid_argument("For comparison mods must be equal");
    }

    int rem_1 = md(value, mod);
    int rem_2 = md(other.value, mod);

    return c(rem_1, rem_2);
}

IntMod::IntMod() : value(0), mod(2) {}

IntMod::IntMod(int value, int mod) {
    if (!isPrime(mod)) throw std::invalid_argument("Mod must be a prime number!");

    this->value = md(value, mod);
    this->mod = mod;
}

std::istream& operator>>(std::istream& in, IntMod& obj) {
    int value, mod;

    in >> value >> mod;
    obj.setMod(mod);
    obj.setValue(value);

    return in;
}

std::ostream& operator<<(std::ostream& out, const IntMod& obj) {
    out << obj.getValue() << " mod " << obj.getMod() << std::endl;
    return out;
}

int IntMod::getValue() const {
    return value;
}

int IntMod::getMod() const {
    return mod;
}

void IntMod::setValue(const int value) {
    this->value = md(value, mod);
}

void IntMod::setMod(const int mod) {
    if (!isPrime(mod)) throw std::invalid_argument("Mod must be a prime number!");

    this->mod = mod;
}

bool IntMod::operator==(const IntMod& other) const {
    return compare(other, [](int a, int b) {return a == b; });
}

bool IntMod::operator!=(const IntMod& other) const {
    return compare(other, [](int a, int b) {return a != b; });
}

bool IntMod::operator>(const IntMod& other) const {
    return compare(other, [](int a, int b) {return a > b; });
}

bool IntMod::operator>=(const IntMod& other) const {
    return compare(other, [](int a, int b) {return a >= b; });
}

bool IntMod::operator<(const IntMod& other) const {
    return compare(other, [](int a, int b) {return a < b; });
}

bool IntMod::operator<=(const IntMod& other) const {
    return compare(other, [](int a, int b) {return a <= b; });
}

IntMod& IntMod::operator=(const IntMod& other) {
    if (this == &other) return *this;

    this->setMod(other.mod);
    this->setValue(other.value);

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

IntMod IntMod::operator/(const IntMod& other) const {
    if (other.value == 0) throw std::invalid_argument("Divider can not be zero!");

    int n_mod = new_mod(mod, other.mod);
    if (gcd(other.value, n_mod) != 1) throw std::invalid_argument("The number and modulus must be coprime!");

    int reverse_value = powerMod(other.value, n_mod - 2, n_mod);
    int n_value = md(value * reverse_value, n_mod);

    return IntMod(n_value, n_mod);
}

IntMod IntMod::operator/=(const IntMod& other) {
    if (other.value == 0) throw std::invalid_argument("Divider can not be zero!");

    int n_mod = new_mod(mod, other.mod);
    if (gcd(other.value, n_mod) != 1) throw std::invalid_argument("The number and modulus must be coprime!");

    int reverse_value = powerMod(other.value, n_mod - 2, n_mod);
    this->setValue(md(value * reverse_value, n_mod));
    this->setMod(n_mod);

    return *this;
}
