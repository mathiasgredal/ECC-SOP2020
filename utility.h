#ifndef UTILITY_H
#define UTILITY_H

#include "ellipticcurve.h"
#include <mini-gmp.h>

namespace ECC {

int legendre_symbol(mpz_t a, mpz_t p);
void modular_sqrt(mpz_t out, mpz_t a, mpz_t p);

void point_double(mpz_t out, mpz_t n, Curve curve);

}

#endif // UTILITY_H
