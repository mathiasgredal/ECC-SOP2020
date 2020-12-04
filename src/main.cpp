#include <iostream>

//#define MAXBITS 40000
//#define COUNT 900000
//#include <matplot/matplot.h>

//#include <matplot/backend/opengl.h>
//#include <mini-gmp.h>
//#include <set>

//#include "ellipticcurve.h"
//#include "utility.h"

#include "BigNum.h"
#include "Curve.h"
#include "Point.h"

using namespace std;
//using namespace matplot;

int main()
{
    Point a = Point("55066263022277343669578718895168534326250603453777594175500187360389116729240", "32670510020758816978083085130507043184471273380659243275938904335757337482424");

    std::cout << "Doing ECDH" << std::endl;

    BigNum bob_private = random(100);
    std::cout << "Bobs private: " << bob_private << std::endl;
    Point bobs_public = secp256k1.DoubleAndAdd(bob_private , secp256k1.GetGenerator());
    std::cout << "Bobs public: " << bobs_public.x << std::endl;

    BigNum alice_private = random(100);
    std::cout << "Alice private: " << alice_private << std::endl;
    Point alice_public = secp256k1.DoubleAndAdd(alice_private , secp256k1.GetGenerator());
    std::cout << "Alice public: " << alice_public.x << std::endl;


    std::cout << "Alice shared: " << secp256k1.DoubleAndAdd(alice_private , bobs_public).x << std::endl;
    std::cout << "Bobs shared: " << secp256k1.DoubleAndAdd(bob_private , alice_public).x << std::endl;


    //std::cout << "Y: " << d.y << std::endl;

    // Create figure with backend
    //        auto f = figure<backend::opengl>(true);
    //        auto ax = f->current_axes();
    //        ax->xlim({ 0., 2. * pi });
    //        ax->ylim({ -1.5, 1.5 });
    //        ax->yticks(iota(-1.5, 0.5, +1.5));
    //        ax->xticks(iota(0., 1., 2. * pi));

    //        // Another figure
    //        auto f2 = figure<backend::opengl>(true);
    //        auto ax2 = f2->add_subplot(2, 1, 0);
    //        auto ax3 = f2->add_subplot(2, 1, 1);

    //        // Create plots
    //        double seconds = backend::opengl::get_time();
    //        std::vector<double> x = linspace(0., 2. * pi);
    //        std::vector<double> y = transform(x, [&](auto x) { return sin(x + seconds); });
    //        ax->hold(off);
    //        ax->plot(x, y, "-o");
    //        ax->hold(on);
    //        const vector_1d minus_y = transform(y, [](auto y) { return -y; });
    //        ax->plot(x, minus_y, "--xr");
    //        ax->plot(x, transform(x, [](auto x) { return x / pi - 1.; }), "-:gs");
    //        ax->plot({ 1.0, 0.7, 0.4, 0.0, -0.4, -0.7, -1 }, "k");

    //        // Only one line in figure 2
    //        ax2->plot(x, y, "-o");
    //        ax3->plot(x, minus_y, "--xr");

    //        // Start rendering
    //        while (!f->should_close() && !f2->should_close()) {
    //            // Draw the figures
    //            f->draw();
    //            f2->draw();
    //        }
}
