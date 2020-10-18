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
#include "Point.h"
#include "Curve.h"

using namespace std;
//using namespace matplot;

int main()
{
    Curve c = Curve(ShortWeierstrass, 32, 732132, 38047, Point(6, 1));
    Point b = secp256k1.PointAdd(Point("55066263022277343669578718895168534326250603453777594175500187360389116729240" , "32670510020758816978083085130507043184471273380659243275938904335757337482424"),
                                 Point("89565891926547004231252920425935692360644145829622209833684329913297188986597", "12158399299693830322967808612713398636155367887041628176798871954788371653930"));


    std::cout << "X: " << b.x << std::endl; // 112711660439710606056748659173929673102114977341539408544630613555209775888121
    std::cout << "Y: " << b.y << std::endl; // 25583027980570883691656905877401976406448868254816295069919888960541586679410

    //    Curve nistp256 = initialize_nistp256();

    //    mpz_t privatekey;
    //    mpz_init_set_si(privatekey, 5);
    //    mpz_t public_key;
    //    mpz_init(public_key);
    //    ECC::point_double(public_key, privatekey, nistp256);

    //    std::cout << "Result: " << mpz_get_str(NULL, 10, public_key) << std::endl;

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
