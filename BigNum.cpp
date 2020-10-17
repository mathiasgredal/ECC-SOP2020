#include "BigNum.h"

BigNum::BigNum()
{
    mpz_init_set_si(bignum, 0);
}

BigNum::BigNum(const char* input)
{
    mpz_init_set_str(bignum, input, 10);
}

BigNum::BigNum(const long long input)
{
    mpz_init_set_si(bignum, input);
}

BigNum::~BigNum()
{
    mpz_clear(bignum);
}

BigNum BigNum::operator=(const char* input)
{
    return BigNum(input);
}

BigNum BigNum::operator=(const long input)
{
    return BigNum(input);
}

BigNum BigNum::operator+=(const BigNum& rhs)
{
    return *this + rhs;
}

BigNum BigNum::operator-=(const BigNum& rhs)
{
    return *this - rhs;
}

BigNum BigNum::operator*=(const BigNum& rhs)
{
    return *this * rhs;
}

BigNum BigNum::operator/=(const BigNum& rhs)
{
    return *this / rhs;
}

BigNum BigNum::operator+(const BigNum& inputnum)
{
    BigNum out;
    mpz_add(out.bignum, this->bignum, inputnum.bignum);
    return out;
}

BigNum BigNum::operator-(const BigNum& inputnum)
{
    BigNum out;
    mpz_sub(out.bignum, this->bignum, inputnum.bignum);
    return out;
}

BigNum BigNum::operator*(const BigNum& inputnum)
{
    BigNum out;
    mpz_mul(out.bignum, this->bignum, inputnum.bignum);
    return out;
}

BigNum BigNum::operator/(const BigNum& inputnum)
{
    BigNum out;
    mpz_divexact(out.bignum, this->bignum, inputnum.bignum);
    return out;
}

std::string BigNum::toString() const
{
    return std::string(mpz_get_str(nullptr, 10, bignum));
}

std::ostream& operator<<(std::ostream& os, const BigNum& num)
{
    os << num.toString();
    return os;
}
