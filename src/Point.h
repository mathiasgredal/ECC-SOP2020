#ifndef ECPOINT_H
#define ECPOINT_H

#include "BigNum.h"

class Point
{
public:
    Point(const BigNum& _x, const BigNum& _y);

    bool operator==(const Point& rhs) const;

    BigNum x;
    BigNum y;
};

std::ostream& operator<<(std::ostream& os, const Point& p);


#endif // ECPOINT_H
