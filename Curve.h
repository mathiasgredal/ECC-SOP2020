#ifndef CURVE_H
#define CURVE_H

#include <iostream>

#include "BigNum.h"
#include "Point.h"

enum CurveType {ShortWeierstrass, Montgomery};

class Curve {
public:
    Curve();

    Point GetPoint(BigNum x);


private:
    BigNum A;
    BigNum B;
    BigNum P;
    Point G;
};

#endif // CURVE_H
