#include "ellipticcurve.h"

EllipticCurve::EllipticCurve()
{
    // Initialize curve 25519
    mpz_init_set_ui(a, 486662);
    mpz_init_set_ui(b, 1);
    mpz_init_set_str(p, "57896044618658097711785492504343953926634992332820282019728792003956564819949", 10);
}
