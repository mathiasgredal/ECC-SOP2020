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
    BigNum(const BigNum&) = default;

    // Destructor
    ~BigNum();

    std::string toString() const;

    BigNum operator=(const char* input);
    BigNum operator=(const long input);
    BigNum operator+=(const BigNum& rhs);
    BigNum operator-=(const BigNum& rhs);
    BigNum operator*=(const BigNum& rhs);
    BigNum operator/=(const BigNum& rhs);
    BigNum operator+(const BigNum& rhs);
    BigNum operator-(const BigNum& rhs);
    BigNum operator*(const BigNum& rhs);
    BigNum operator/(const BigNum& rhs);

private:
    mpz_t bignum;
};

std::ostream& operator<<(std::ostream& os, const BigNum& num);

#endif // BIGNUM_H
