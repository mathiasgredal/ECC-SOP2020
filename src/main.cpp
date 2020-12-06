#include <iostream>

//#define MAXBITS 40000
//#define COUNT 900000
//#include <matplot/matplot.h>

//#include <matplot/backend/opengl.h>
//#include <mini-gmp.h>
//#include <set>

//#include "ellipticcurve.h"
//#include "utility.h"

#include "ECDH.h"

using namespace std;
//using namespace matplot;

int main()
{
    Point a = Point("55066263022277343669578718895168534326250603453777594175500187360389116729240", "32670510020758816978083085130507043184471273380659243275938904335757337482424");

    std::cout << "Doing ECDH" << std::endl;

    KeyPair alice_key = ECDH::Generate_Keypair();
    std::cout << "ALICE KEY: " << std::endl;
    std::cout << "\t private key: " << alice_key.priv_key << std::endl;
    std::cout << "\t public key: " << alice_key.pub_key;

    KeyPair bob_key = ECDH::Generate_Keypair();
    std::cout << "BOBS KEY: " << std::endl;
    std::cout << "\t private key: " << bob_key.priv_key << std::endl;
    std::cout << "\t public key: " << bob_key.pub_key;


    Point alice_shared = ECDH::Create_Shared_Key(alice_key, bob_key.pub_key);
    Point bob_shared = ECDH::Create_Shared_Key(bob_key, alice_key.pub_key);
    std::cout << "SHARED KEYS: " << std::endl;
    std::cout << "ALICE: " << alice_shared;
    std::cout << "  BOB: " << bob_shared;

    for(long long i = 0ll; i < 20; i++) {
        std::cout << secp256k1.GetPoint(i) << std::endl;
    }

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
