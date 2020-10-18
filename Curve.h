#ifndef CURVE_H
#define CURVE_H

#include <iostream>
#include <array>

#include "BigNum.h"
#include "Point.h"


enum CurveType {ShortWeierstrass, Montgomery};

class Curve {
public:
    Curve(CurveType type,const BigNum& _A,const BigNum& _B,const BigNum& _P,const Point& G);

    Point GetPoint(BigNum x);
    Point PointDouble(Point a) const;
    Point PointAdd(Point a, Point b) const;
private:
    const CurveType curvetype;
    const BigNum A;
    const BigNum B;
    const BigNum P;
    const Point G;
};

// Some common and secure curves (perhaps not the nist curve)
const Curve nistp256 = Curve(CurveType::ShortWeierstrass, "-3",
                         "41058363725152142129326129780047268409114441015993725554835256314039467401291",
                         "115792089210356248762697446949407573530086143415290314195533631308867097853951",
                         {"48439561293906451759052585252797914202762949526041747995844080717082404635286",
                               "36134250956749795798585127919587881956611106672985015071877198253568414405109"});

const Curve secp256k1 = Curve(CurveType::ShortWeierstrass, "0", "7",
                         "115792089237316195423570985008687907853269984665640564039457584007908834671663",
                         {"55066263022277343669578718895168534326250603453777594175500187360389116729240",
                               "32670510020758816978083085130507043184471273380659243275938904335757337482424"});

const Curve curve25519 = Curve(CurveType::Montgomery,
                           "19298681539552699237261830834781317975544997444273427339909597334573241639236",
                           "55751746669818908907645289078257140818241103727901012315294400837956729358436",
                           "57896044618658097711785492504343953926634992332820282019728792003956564819949",
                           {"19298681539552699237261830834781317975544997444273427339909597334652188435546",
                                 "14781619447589544791020593568409986887264606134616475288964881837755586237401"});
#endif // CURVE_H
