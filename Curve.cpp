#include "Curve.h"

Curve::Curve(CurveType type, const BigNum& _A, const BigNum& _B, const BigNum& _P, const Point& _G)
    : curvetype(type)
    , A(_A)
    , B(_B)
    , P(_P)
    , G(_G)
{
}

Point Curve::GetPoint(BigNum x)
{
    std::cout << "ERROR: GetPoint() NOT IMPLEMENTED" << std::endl;
    return G;
}

Point Curve::PointDouble(Point a) const
{
    if (curvetype == Montgomery) {
        throw std::runtime_error("ERROR: Montgomery curves not implemented");
    }

    BigNum s = (powm(a.x, 2, P) * 3 + A) * invmod(a.y * 2, P);

    BigNum bx = (powm(s, 2, P) - a.x * 2) % P;
    BigNum by = (s * (a.x - bx) - a.y) % P;

    return Point(bx, by);
}

Point Curve::PointAdd(Point a, Point b) const
{
    if (curvetype == Montgomery) {
        throw std::runtime_error("ERROR: Montgomery curves not implemented");
    }

    BigNum s = (a.y - b.y) * invmod(a.x - b.x, P);

    BigNum cx = (powm(s, 2, P) - a.x - b.x) % P;
    BigNum cy = (s * (a.x - cx) - a.y) % P;

    return Point(cx, cy);
}

Point Curve::DoubleAndAdd(BigNum a, Point b) const
{
    std::string k = mpz_get_str(NULL, 2, a.bignum);

    Point result = { 0.f, 0.f };
    Point addend = b;

    for (auto n : k) {
        std::cout << n << std::endl;
        if (n == '1')
            result = this->PointAdd(result, addend);

        addend = this->PointDouble(addend);
    }

    return result;
}
