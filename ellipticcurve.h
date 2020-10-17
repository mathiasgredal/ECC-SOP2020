#ifndef ELLIPTICCURVE_H
#define ELLIPTICCURVE_H

#include <iostream>
#include <mini-gmp.h>

class EllipticCurve {
public:
    EllipticCurve();

private:
    mpz_t a;
    mpz_t b;
    mpz_t p;
};

struct Curve {
    mpz_t a;
    mpz_t b;
    mpz_t p;
    mpz_t x1;
    mpz_t y1;
};

#endif // ELLIPTICCURVE_H
