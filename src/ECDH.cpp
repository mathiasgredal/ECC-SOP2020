#include "ECDH.h"

KeyPair ECDH::Generate_Keypair(BigNum priv_key, Curve c, int keysize)
{
    Point pub_key = c.DoubleAndAdd(priv_key, c.GetGenerator());
    return {priv_key, pub_key, c};
}

KeyPair ECDH::Generate_Keypair(Curve c, int keysize)
{
    BigNum priv_key = random(keysize);
    return Generate_Keypair(priv_key, c, keysize);
}

Point ECDH::Create_Shared_Key(KeyPair key, Point pubkey)
{
    return key.curve.DoubleAndAdd(key.priv_key, pubkey);
}
