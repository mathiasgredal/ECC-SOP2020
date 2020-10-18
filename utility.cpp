#include "utility.h"

///
/// \brief Compute the Legendre symbol a|p using Euler's criterion. p is a prime, a is relatively prime to p (if p divides a, then a|p = 0)
/// \param out Returns 1 if a has a square root modulo p, -1 otherwise.
/// \param a is relativly prime
/// \param p is a prime
///
//int ECC::legendre_symbol(mpz_t a, mpz_t p)
//{
//    // (p - 1)
//    mpz_t pmin1;
//    mpz_init(pmin1);
//    mpz_sub_ui(pmin1, p, 1);

//    // (p - 1) // 2
//    mpz_t pmin1div2;
//    mpz_init(pmin1div2);
//    mpz_divexact_ui(pmin1div2, pmin1, 2);

//    mpz_t ls;
//    mpz_init(ls);
//    mpz_powm(ls, a, pmin1div2, p);

//    if (mpz_cmp(ls, pmin1))
//        return mpz_get_si(ls);
//    else
//        return -1;
//}

//int mod_2(mpz_t s)
//{
//    mpz_t res;
//    mpz_init(res);
//    mpz_mod_ui(res, s, 2);
//    return mpz_get_si(res);
//}

//void ECC::modular_sqrt(mpz_t out, mpz_t a, mpz_t p)
//{
//    // Handle common simple cases
//    if (legendre_symbol(a, p) != 1) {
//        return mpz_set_ui(out, 0);
//    } else if (!mpz_cmp_ui(a, 0)) {
//        return mpz_set_ui(out, 0);
//    } else if (!mpz_cmp_ui(p, 2)) {
//        return mpz_set(out, p);
//    } else {
//        mpz_t pmod4;
//        mpz_init(pmod4);
//        mpz_mod_ui(pmod4, p, 4);

//        if (!mpz_cmp_ui(pmod4, 3)) {
//            mpz_t padd1;
//            mpz_init(padd1);
//            mpz_add_ui(padd1, p, 1);

//            mpz_t padd1div4;
//            mpz_init(padd1div4);
//            mpz_add_ui(padd1div4, padd1, 4);

//            mpz_t apowpadd1div4;
//            mpz_init(apowpadd1div4);
//            mpz_powm(apowpadd1div4, a, padd1div4, p);

//            return mpz_set(out, apowpadd1div4);
//        }
//    }

//    mpz_t s;
//    mpz_init(s);
//    mpz_sub_ui(s, p, 1);

//    mpz_t e;
//    mpz_init_set_ui(e, 0);

//    while (mod_2(s) == 0) {
//        mpz_divexact_ui(s, s, 2);
//        mpz_add_ui(e, e, 1);
//    }

//    mpz_t n;
//    mpz_init_set_ui(n, 2);
//    while (legendre_symbol(n, p) != -1)
//        mpz_add_ui(n, n, 1);

//    mpz_t sadd1;
//    mpz_init(sadd1);
//    mpz_add_ui(sadd1, s, 1);

//    mpz_t sadd1div2;
//    mpz_init(sadd1div2);
//    mpz_divexact_ui(sadd1div2, sadd1, 2);

//    mpz_t x;
//    mpz_init(x);
//    mpz_powm(x, a, sadd1div2, p);

//    mpz_t b;
//    mpz_init(b);
//    mpz_powm(b, a, s, p);

//    mpz_t g;
//    mpz_init(g);
//    mpz_powm(g, n, s, p);

//    mpz_t r;
//    mpz_init_set(r, e);

//    while (3 <= 8) {
//        mpz_t t;
//        mpz_init_set(t, b);
//        mpz_t m;
//        mpz_init_set_si(m, 0);

//        while (mpz_cmp(m, r)) {
//            if (!mpz_cmp_ui(t, 1))
//                break;
//            mpz_powm_ui(t, t, 2, p);
//            mpz_add_ui(m, m, 1);
//        }

//        if (!mpz_cmp_ui(m, 0)) {
//            mpz_init_set(out, x);
//            return;
//        }

//        mpz_t madd1;
//        mpz_init(madd1);
//        mpz_add_ui(madd1, m, 1);

//        mpz_t rsubmsub1;
//        mpz_init(rsubmsub1);
//        mpz_sub(rsubmsub1, r, madd1);

//        mpz_t num2;
//        mpz_init_set_si(num2, 2);
//        mpz_t rsubmsub1pow;
//        mpz_init(rsubmsub1pow);
//        mpz_powm(rsubmsub1pow, num2, rsubmsub1, p);

//        mpz_t gs;
//        mpz_init(gs);
//        mpz_powm(gs, g, rsubmsub1pow, p);

//        mpz_t gsmulgs;
//        mpz_init(gsmulgs);
//        mpz_mul(gsmulgs, gs, gs);

//        mpz_t g;
//        mpz_init(g);
//        mpz_mod(g, gsmulgs, p);

//        mpz_mul(x, x, gs);
//        mpz_mod(x, x, p);

//        mpz_mul(b, b, g);
//        mpz_mod(b, b, p);

//        mpz_set(r, m);
//    }
//}

//void invmod(mpz_t out, mpz_t a, mpz_t n)
//{
//    if (mpz_cmp_ui(n, 2) == -1)
//        throw std::runtime_error("modulus n must be greater than 1");

//    mpz_t g, x, y;
//    mpz_init(g);
//    mpz_init(x);
//    mpz_init(y);

//    // Extended euclid algorithm
//    mpz_gcdext(g, x, y, a, n);

//    if (mpz_cmp_ui(g, 1))
//        throw std::runtime_error("no inverse modulus found for a and n");
//    else {
//        mpz_init(out);
//        mpz_mod(out, x, n);
//        return;
//    }
//}

//// Point doubling on regular elliptic curves NOT montogery curve like Curve 25517
//void ECC::point_double(mpz_t out, mpz_t n, Curve curve)
//{
//    // Calculate x
//    mpz_t xsquared;
//    mpz_init(xsquared);
//    mpz_pow_ui(xsquared, curve.x1, 2);

//    mpz_t xsquaredmul3;
//    mpz_init(xsquaredmul3);
//    mpz_mul_ui(xsquaredmul3, xsquared, 3);

//    mpz_t xsquaredmul3adda;
//    mpz_init(xsquaredmul3adda);
//    mpz_add(xsquaredmul3adda, xsquaredmul3, curve.a);

//    mpz_t ymul2;
//    mpz_init(ymul2);
//    mpz_mul_ui(ymul2, curve.y1, 2);

//    mpz_t invymul2;
//    invmod(invymul2, ymul2, curve.p);

//    mpz_t s;
//    mpz_init(s);
//    mpz_mul(s, xsquaredmul3adda, invymul2);

//    mpz_t ssquared;
//    mpz_init(ssquared);
//    mpz_pow_ui(ssquared, s, 2);

//    mpz_t xmul2;
//    mpz_init(xmul2);
//    mpz_mul_ui(xmul2, curve.x1, 2);

//    mpz_t ssquaredsubxmul2;
//    mpz_init(ssquaredsubxmul2);
//    mpz_sub(ssquaredsubxmul2, ssquared, xmul2);

//    mpz_t x2;
//    mpz_init(x2);
//    mpz_mod(x2, ssquaredsubxmul2, curve.p);

//    mpz_t xsubx2;
//    mpz_init(xsubx2);
//    mpz_sub(xsubx2, curve.x1, x2);

//    mpz_t smulxsubx2;
//    mpz_init(smulxsubx2);
//    mpz_mul(smulxsubx2, s, xsubx2);

//    mpz_t smulxsubx2suby;
//    mpz_init(smulxsubx2suby);
//    mpz_sub(smulxsubx2suby, smulxsubx2, curve.y1);

//    mpz_t y2;
//    mpz_init(y2);
//    mpz_mod(y2, smulxsubx2suby, curve.p);

//    std::cout << "X: " << mpz_get_str(NULL, 10, x2) << std::endl;
//    std::cout << "Y: " << mpz_get_str(NULL, 10, y2) << std::endl;
//}
