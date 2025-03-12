#include <iostream>

#pragma once

class IntMod {
private:
    int value;
    int mod;

    bool isPrime(int n) const;
    int md(int a, int b) const;
    int gcd(int a, int b) const;
    int powerMod(int a, int b, int p) const;
    bool equalMods(int mod, int other_mod) const;
    int new_prime(int num) const;
    int new_mod(int mod, int other_mod) const;

    template <typename Operation>
    IntMod binOp(const IntMod& other, Operation op) const;

    template <typename Operation>
    IntMod binOpThis(const IntMod& other, Operation op);

    template <typename Comparison>
    bool compare(const IntMod& other, Comparison c) const;

public:
    IntMod();
    IntMod(int value, int mod);

    friend std::istream& operator>>(std::istream& in, IntMod& obj);
    friend std::ostream& operator<<(std::ostream& out, const IntMod& obj);

    int getValue() const;
    int getMod() const;
    void setValue(const int value);
    void setMod(const int mod);

    bool operator==(const IntMod& other) const;
    bool operator!=(const IntMod& other) const;
    bool operator>(const IntMod& other) const;
    bool operator>=(const IntMod& other) const;
    bool operator<(const IntMod& other) const;
    bool operator<=(const IntMod& other)const;

    IntMod& operator=(const IntMod& other);
    IntMod operator+(const IntMod& other) const;
    IntMod operator+=(const IntMod& other);
    IntMod operator-(const IntMod& other) const;
    IntMod operator-=(const IntMod& other);
    IntMod operator*(const IntMod& other) const;
    IntMod operator*=(const IntMod& other);
    IntMod operator/(const IntMod& other) const;
    IntMod operator/=(const IntMod& other);
};
