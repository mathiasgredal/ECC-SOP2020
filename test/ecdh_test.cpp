#include <string>
#include <catch.hpp>

#include <ECDH.h>
#include "ecdh_openssl.h"

using namespace std;

TEST_CASE("Compare ECDH implementation speed", "[benchmark]")
{
    BENCHMARK("Custom ECDH Library")
    {
        KeyPair alice_key = ECDH::Generate_Keypair();
        KeyPair bob_key = ECDH::Generate_Keypair();
        Point alice_shared = ECDH::Create_Shared_Key(alice_key, bob_key.pub_key);
        Point bob_shared = ECDH::Create_Shared_Key(bob_key, alice_key.pub_key);
    };

    BENCHMARK("OpenSSL ECDH")
    {
        auto shared = PerformECDH();
    };
}


TEST_CASE("Compare ECDH correctness", "[ecdh]")
{
    // First we use openssl to compute some random private/public keypairs
    EC_KEY* alice_openssl = Gen_Keypair_OpenSSL();
    EC_KEY* bob_openssl = Gen_Keypair_OpenSSL();

    // We can then do the same in the custom library
    KeyPair alice_key = ECDH::Generate_Keypair(Get_Private_Key(alice_openssl).c_str());
    KeyPair bob_key = ECDH::Generate_Keypair(Get_Private_Key(bob_openssl).c_str());

    // We can now compute the shared key using both openssl and the custom library
    std::string alice_shared_openssl = Gen_Shared_OpenSSL(alice_openssl, EC_KEY_get0_public_key(bob_openssl));
    std::string bob_shared_openssl = Gen_Shared_OpenSSL(bob_openssl, EC_KEY_get0_public_key(alice_openssl));

    Point alice_shared = ECDH::Create_Shared_Key(alice_key, bob_key.pub_key);
    Point bob_shared = ECDH::Create_Shared_Key(bob_key, alice_key.pub_key);

    // All of these should match
    REQUIRE(alice_shared_openssl == bob_shared_openssl);
    REQUIRE(alice_shared_openssl == alice_shared.x.toString());
    REQUIRE(bob_shared_openssl == bob_shared.x.toString());
    REQUIRE(alice_shared == bob_shared);
}
