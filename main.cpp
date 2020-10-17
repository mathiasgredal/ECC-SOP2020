#include <iostream>

//#define MAXBITS 40000
//#define COUNT 900000
#include <matplot/matplot.h>

#include <matplot/backend/opengl.h>
#include <mini-gmp.h>
#include <set>

#include "ellipticcurve.h"
#include "utility.h"

#include "BigNum.h"

using namespace std;
using namespace matplot;

Curve initialize_nistp256()
{
    Curve nistp256;
    mpz_init_set_si(nistp256.a, -3);
    mpz_init_set_str(nistp256.b, "41058363725152142129326129780047268409114441015993725554835256314039467401291", 10);
    mpz_init_set_str(nistp256.p, "115792089210356248762697446949407573530086143415290314195533631308867097853951", 10);

    mpz_init_set_ui(nistp256.x1, 5);
    mpz_init_set_str(nistp256.y1, "31468013646237722594854082025316614106172411895747863909393730389177298123724", 10);

    return nistp256;
}

int main()
{
    BigNum a = "31468013646237722594854082025316614106172411895747863909393730389177298123724";

    std::cout << "A: " << a * a << std::endl;

    //    Curve nistp256 = initialize_nistp256();

    //    mpz_t privatekey;
    //    mpz_init_set_si(privatekey, 5);
    //    mpz_t public_key;
    //    mpz_init(public_key);
    //    ECC::point_double(public_key, privatekey, nistp256);

    //    std::cout << "Result: " << mpz_get_str(NULL, 10, public_key) << std::endl;

    //    // Create figure with backend
    //    auto f = figure<backend::opengl>(true);
    //    auto ax = f->current_axes();
    //    ax->xlim({ 0., 2. * pi });
    //    ax->ylim({ -1.5, 1.5 });
    //    ax->yticks(iota(-1.5, 0.5, +1.5));
    //    ax->xticks(iota(0., 1., 2. * pi));

    //    // Another figure
    //    auto f2 = figure<backend::opengl>(true);
    //    auto ax2 = f2->add_subplot(2, 1, 0);
    //    auto ax3 = f2->add_subplot(2, 1, 1);

    //    // Create plots
    //    double seconds = backend::opengl::get_time();
    //    std::vector<double> x = linspace(0., 2. * pi);
    //    std::vector<double> y = transform(x, [&](auto x) { return sin(x + seconds); });
    //    ax->hold(off);
    //    ax->plot(x, y, "-o");
    //    ax->hold(on);
    //    const vector_1d minus_y = transform(y, [](auto y) { return -y; });
    //    ax->plot(x, minus_y, "--xr");
    //    ax->plot(x, transform(x, [](auto x) { return x / pi - 1.; }), "-:gs");
    //    ax->plot({ 1.0, 0.7, 0.4, 0.0, -0.4, -0.7, -1 }, "k");

    //    // Only one line in figure 2
    //    ax2->plot(x, y, "-o");
    //    ax3->plot(x, minus_y, "--xr");

    //    // Start rendering
    //    while (!f->should_close() && !f2->should_close()) {
    //        // Draw the figures
    //        f->draw();
    //        f2->draw();
    //    }
}
