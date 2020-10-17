#ifndef ECCURVE_H
#define ECCURVE_H
#include "bignum.h"
#include <iostream>

class ECCurve {
public:
    ECCurve();

private:
    BigNum A;
    BigNum B;
    BigNum P;
    ECPoint G;
};

#endif // ECCURVE_H
