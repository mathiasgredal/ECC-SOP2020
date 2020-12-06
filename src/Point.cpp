#include "Point.h"

Point::Point(const BigNum& _x, const BigNum& _y) : x(_x), y(_y)
{
}

bool Point::operator==(const Point &rhs) const
{
    return (x == rhs.x && y == rhs.y);
}


std::ostream &operator<<(std::ostream &os, const Point &p)
{
    os << "(" << p.x << ", " << p.y << ")" << std::endl;
    return os;
}
