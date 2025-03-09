#pragma once

class IntMod {
private:
    int value;
    int mod;

    bool isPrime(int n) const;
    int md(int a, int b) const;
    int gcd(int a, int b) const;
    int powerMod(int a, int b, int p) const;
    void equalMods(int mod, int other_mod) const;

    template <typename Operation>
    IntMod binOp(const IntMod& other, Operation op) const;

    template <typename Operation>
    IntMod binOpThis(const IntMod& other, Operation op);

    template <typename Comparison>
    bool compare(const IntMod& other, Comparison c) const;

public:
    IntMod();
    IntMod(int value, int mod);

    int getValue() const;
    int getMod() const;
    void setValue(const int value);
    void setMod(const int mod);

    bool operator==(const IntMod& other) const;
    bool operator!=(const IntMod& other) const;
    bool operator>(const IntMod& other);
    bool operator>=(const IntMod& other);
    bool operator<(const IntMod& other);
    bool operator<=(const IntMod& other);

    IntMod& operator=(const IntMod& other);
    IntMod operator+(const IntMod& other) const;
    IntMod operator+=(const IntMod& other);
    IntMod operator-(const IntMod& other) const;
    IntMod operator-=(const IntMod& other);
    IntMod operator*(const IntMod& other) const;
    IntMod operator*=(const IntMod& other);
    IntMod operator/(const IntMod& other);
    IntMod operator/=(const IntMod& other);
};