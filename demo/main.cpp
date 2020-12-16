#include <iostream>
#include <random>
#include <cmath>

//#define MAXBITS 40000
//#define COUNT 900000
//#include <matplot/matplot.h>
//#include <matplot/backend/opengl.h>

#include "ECDH.h"

using namespace std;
//using namespace matplot;

//double wrap(double a, double low, double high) {
//    if (a < low)
//        return high - std::fmod(low - a, (high - low));
//    else
//        return low + std::fmod(a - low, high - low);
//}

int main()
{
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

//    for(long long i = 0ll; i < 20; i++) {
//        std::cout << secp256k1.GetPoint(i) << std::endl;
//    }

    //std::cout << "Y: " << d.y << std::endl;


//    std::random_device dev;
//    std::mt19937 rng(dev());
//    std::uniform_int_distribution<std::mt19937::result_type> dist(0,96);

//    auto curve = Curve(ShortWeierstrass, 5, 7, 97, Point(1, 2));
//    auto x_list = std::vector<double>();
//    auto y_list = std::vector<double>();

//    for(long x = 0ll; x < 97; x++) {
//        for(long y = 0ll; y < 97; y++) {
//            if((y*y)%97==(x*x*x+5*x+7)%97) {
//                x_list.push_back(x);
//                y_list.push_back(y);
//            }
//        }
//    }

//    int p1 = dist(rng);
//    int p2 = dist(rng);
//    auto p3 = curve.PointAdd(Point(x_list[p1], y_list[p1]), Point(x_list[p2], y_list[p2]));

//    std::cout << "P1: (" << x_list[p1] << ", " << y_list[p1] << ")" << std::endl;
//    std::cout << "P2: (" << x_list[p2] << ", " << y_list[p2] << ")" << std::endl;
//    std::cout << "P3: (" << p3.x << ", " << p3.y << ")" << std::endl;


//    double slope = (y_list[p2]-y_list[p1])/(x_list[p2]-x_list[p1]);
//    std::cout << "SLOPE: " << slope << std::endl;

//    double b = y_list[p2]-slope*x_list[p2];
//    std::cout << "B: " << b << std::endl;


//    for(int i = 0; i < 20; i++) {
//        fplot([&](double x) {
//            x += 97*i;
//            return wrap(slope*x+b, 0, 97);
//        }, std::array<double, 2>{0, 97});
//        hold(on);
//    }

//    scatter(x_list,y_list);

//    show();
}
