#include "ecdh_openssl.h"

std::string Calc_Shared_Key(EC_KEY* key, const EC_POINT *pubkey) {
    int key_length;

    key_length = EC_GROUP_get_degree(EC_KEY_get0_group(key));
    key_length = (key_length + 7) / 8;

    unsigned char *secret = (unsigned char*)malloc(key_length);
    key_length = ECDH_compute_key(secret, key_length, pubkey, key, NULL);

    BIGNUM *shared = BN_new();

    BN_bin2bn(secret, key_length, shared);

    std::string shared_key = std::string(BN_bn2dec(shared));
    delete secret;

    return shared_key;
}

EC_KEY* Generate_key()
{
    EC_KEY *key;

    key = EC_KEY_new_by_curve_name(NID_secp256k1);
    if (key == NULL)
        throw std::runtime_error("Failed to initialize key");

    if (!EC_KEY_generate_key(key))
        throw std::runtime_error("Failed to generate key");

    return key;
}


void Print_Key(EC_KEY* key) {
    const EC_GROUP *ec_group = EC_KEY_get0_group(key);
    const EC_POINT *pub = EC_KEY_get0_public_key(key);
    const BIGNUM *priv = EC_KEY_get0_private_key(key);

    std::cout << "KEY INFO: " << std::endl;
    std::cout << "private: " << BN_bn2dec(priv) << std::endl;
    BIGNUM *x = BN_new();
    BIGNUM *y = BN_new();
    if (EC_POINT_get_affine_coordinates_GFp(ec_group, pub, x, y, NULL)) {
        std::cout << "public: (" << BN_bn2dec(x) << ", " <<  BN_bn2dec(y) << ")" << std::endl;
    }
}

KeyPair CreateKeyPairFromECKEY(EC_KEY* key) {
    BigNum priv_key = BN_bn2dec(EC_KEY_get0_private_key(key));
    Point pub_key = Point(0ll, 0ll);

    const EC_GROUP *ec_group = EC_KEY_get0_group(key);
    const EC_POINT *pub = EC_KEY_get0_public_key(key);

    BIGNUM *x = BN_new();
    BIGNUM *y = BN_new();
    if (EC_POINT_get_affine_coordinates_GFp(ec_group, pub, x, y, NULL)) {
        pub_key = Point(BN_bn2dec(x), BN_bn2dec(y));
    }

    return {priv_key, pub_key, secp256k1};
}


std::pair<std::string, KeyPair> PerformECDH()
{
    EC_KEY *alice_key = Generate_key();
    EC_KEY *bob_key = Generate_key();

    std::string alice_shared = Calc_Shared_Key(alice_key, EC_KEY_get0_public_key(bob_key));
    std::string bob_shared = Calc_Shared_Key(bob_key, EC_KEY_get0_public_key(alice_key));

    if(alice_shared != bob_shared)
        throw std::runtime_error("Shared keys do not match");

    return std::make_pair(alice_shared, CreateKeyPairFromECKEY(alice_key));
}

EC_KEY* Gen_Keypair_OpenSSL()
{
    return Generate_key();
}

std::string Gen_Shared_OpenSSL(EC_KEY* key, const EC_POINT* pubkey)
{
    return Calc_Shared_Key(key, pubkey);
}

std::string Get_Private_Key(EC_KEY *key)
{
    return BN_bn2dec(EC_KEY_get0_private_key(key));
}

Point Get_Public_Key(EC_KEY *key)
{
    Point pub_key = Point(0ll, 0ll);

    const EC_GROUP *ec_group = EC_KEY_get0_group(key);
    const EC_POINT *pub = EC_KEY_get0_public_key(key);

    BIGNUM *x = BN_new();
    BIGNUM *y = BN_new();
    if (EC_POINT_get_affine_coordinates_GFp(ec_group, pub, x, y, NULL)) {
        pub_key = Point(BN_bn2dec(x), BN_bn2dec(y));
    }

    return pub_key;
}
