#ifndef BIGNUM_H
#define BIGNUM_H

#include <iostream>
#include <mini-gmp.h>

class BigNum {
public:
    // Constructor
    BigNum();
    BigNum(const char* input);
    BigNum(const long long input);
    BigNum(const BigNum&);

    // Destructor
    ~BigNum();

    std::string toString() const;

    BigNum operator=(const char* input);
    BigNum operator=(const long input);
    BigNum operator=(const BigNum& input);
    BigNum operator+(const BigNum& rhs) const;
    BigNum operator-(const BigNum& rhs) const;
    BigNum operator*(const BigNum& rhs) const;
    BigNum operator/(const BigNum& rhs) const;
    BigNum operator%(const BigNum& rhs) const;

    bool operator==(const BigNum& rhs) const;
    bool operator!=(const BigNum& rhs) const;
    bool operator<(const BigNum& rhs)  const;
    bool operator<=(const BigNum& rhs) const;
    bool operator>(const BigNum& rhs)  const;
    bool operator>=(const BigNum& rhs) const;

    mpz_t bignum;
};

std::ostream& operator<<(std::ostream& os, const BigNum& num);

// Useful math functions
BigNum powm(const BigNum& a, const BigNum& b, const BigNum& p);
BigNum invmod(const BigNum& a, const BigNum& p);
BigNum LegendreSymbol(const BigNum& a, const BigNum& p);
BigNum ModularSqrt(const BigNum& a, const BigNum& p);

#endif // BIGNUM_H
