#ifndef ECDH_H
#define ECDH_H

#include "BigNum.h"
#include "Curve.h"

struct KeyPair {
    BigNum priv_key;
    Point pub_key;
    Curve curve;
};

class ECDH
{
public:
    static KeyPair Generate_Keypair(BigNum priv_key, Curve c = secp256k1, int keysize = 256);
    static KeyPair Generate_Keypair(Curve c = secp256k1, int keysize = 256);
    static Point Create_Shared_Key(KeyPair key, Point pubkey);
private:
    ECDH() = default;
};

#endif // ECDH_H
