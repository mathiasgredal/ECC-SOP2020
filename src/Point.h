#ifndef ECPOINT_H
#define ECPOINT_H

#include "BigNum.h"

class Point
{
public:
    Point(const BigNum& _x, const BigNum& _y);

    BigNum x;
    BigNum y;
};

#endif // ECPOINT_H
