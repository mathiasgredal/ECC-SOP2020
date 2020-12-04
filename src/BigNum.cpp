#include "BigNum.h"

BigNum::BigNum()
{
    mpz_init_set_si(bignum, 0);
}

BigNum::BigNum(const char *input)
{
    mpz_init_set_str(bignum, input, 10);
}

BigNum::BigNum(const long long input)
{
    mpz_init_set_si(bignum, input);
}

BigNum::BigNum(const BigNum& input)
{
    mpz_init_set(bignum, input.bignum);
}

BigNum::~BigNum()
{
    mpz_clear(bignum);
}

BigNum BigNum::operator=(const char* input)
{
    mpz_init_set_str(bignum, input, 10);
    return *this;
}

BigNum BigNum::operator=(const long input)
{
    mpz_init_set_ui(bignum, input);
    return *this;
}

BigNum BigNum::operator=(const BigNum &input)
{
    mpz_init_set(bignum, input.bignum);
    return *this;
}

BigNum BigNum::operator+(const BigNum& inputnum) const
{
    BigNum out;
    mpz_add(out.bignum, this->bignum, inputnum.bignum);
    return out;
}

 BigNum BigNum::operator-(const BigNum& inputnum) const
{
    BigNum out;
    mpz_sub(out.bignum, this->bignum, inputnum.bignum);
    return out;
}

 BigNum BigNum::operator*(const BigNum& inputnum) const
{
    BigNum out;
    mpz_mul(out.bignum, this->bignum, inputnum.bignum);
    return out;
}

 BigNum BigNum::operator/(const BigNum& inputnum) const
{
    BigNum out;
    mpz_divexact(out.bignum, this->bignum, inputnum.bignum);
    return out;
 }

BigNum BigNum::operator%(const BigNum &rhs) const
{
    BigNum out;
    mpz_mod(out.bignum, this->bignum, rhs.bignum);
    return out;
}

 bool BigNum::operator==(const BigNum &rhs) const
 {
     if(mpz_cmp(this->bignum, rhs.bignum) == 0)
         return true;
     else
         return false;
 }

 bool BigNum::operator!=(const BigNum &rhs) const
 {
    return !(*this==rhs);
 }

 bool BigNum::operator<(const BigNum &rhs) const
 {
     if(mpz_cmp(this->bignum, rhs.bignum) == -1)
         return true;
     else
         return false;
 }

 bool BigNum::operator<=(const BigNum &rhs) const
 {
    return !(rhs < *this);
 }

 bool BigNum::operator>(const BigNum &rhs) const
 {
    return rhs < *this;
 }

 bool BigNum::operator>=(const BigNum &rhs) const
 {
    return !(*this < rhs);
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


BigNum powm(const BigNum &a, const BigNum &b, const BigNum &p)
{
    BigNum out;
    mpz_powm(out.bignum, a.bignum, b.bignum, p.bignum);
    return out;
}

// Legendre symbol using Euler's criterion.
BigNum LegendreSymbol(const BigNum &a, const BigNum &p)
{
    BigNum ls = powm(a, (p - 1)/2, p);

    if (ls == p-1)
        return -1;
    else
        return ls;
}

// Tonnelli Shanks algorithm, adapted from: https://gist.github.com/60d62bdf4067ea72b7832ce9f71ae079
BigNum ModularSqrt(const BigNum &a, const BigNum &p)
{
    // Handle simple cases
    if(LegendreSymbol(a, p) != 1)
        return "0";
    else if (a == "0")
        return "0";
    else if (p == 2)
        return p;
    else if (p % 4 == 3)
        return powm(a, (p+1)/4, p);

    // Partition p-1 to s * 2^e for an odd s (i.e.
    // reduce all the powers of 2 from p-1)
    BigNum s = p - 1;
    BigNum e = "0";
    while (s % 2 == "0") {
        s = s / 2;
        e = e + 1;
    }

    BigNum n = 2;
    while (LegendreSymbol(n, p) != -1)
         n = n + 1;

    BigNum x = powm(a, (s + 1) / 2, p);
    BigNum b = powm(a, s, p);
    BigNum g = powm(n, s, p);
    BigNum r = e;

    while(3<=8) {
        BigNum t = b;
        BigNum m = "0";

        while(m != r) {
            if(t == 1)
                break;
            t = powm(t, 2, p);
            m = m + 1;
        }

        if (m == "0")
            return x;

        BigNum gs = powm(g, powm(2, (r - m - 1), p), p);
        g = (gs * gs) % p;
        x = (x * gs) % p;
        b = (b * g) % p;
        r = m;
    }

}


BigNum invmod(const BigNum &a, const BigNum &p)
{
    if (p < 2)
        throw std::runtime_error("modulus p must be greater than 1");

    BigNum g, x, y;

    // Extended euclid algorithm
    mpz_gcdext(g.bignum, x.bignum, y.bignum, a.bignum, p.bignum);

    if (g != 1)
        throw std::runtime_error("no inverse modulus found for a and n");
    else {
        return x % p;
    }
}

std::random_device rd;
std::mt19937 mt(time(nullptr));

///
/// \brief Generate a random number, with the specified length in bits
/// \param length of the generated number in bits
/// \return
///
BigNum random(const BigNum &length)
{
    std::string out;

    // If the random device is not available, then seed with the that
    if(rd.entropy() != 0)
        mt = std::mt19937(rd());

    std::uniform_int_distribution<> dist(0, 1); // define the range

    for(BigNum i = 0ll; i < length; i = i + 1) {
        out.append(std::to_string(dist(mt)));
    }

    mpz_t binary_num;
    mpz_init_set_str(binary_num, out.c_str(), 2);
    BigNum integer_num = mpz_get_str(nullptr, 10, binary_num);

    return integer_num;
}
