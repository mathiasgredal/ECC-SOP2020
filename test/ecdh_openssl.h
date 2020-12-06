#ifndef ECDH_OPENSSL_H
#define ECDH_OPENSSL_H
#include <iostream>
#include <string>

#include <openssl/ec.h>
#include <openssl/ecdh.h>
#include <openssl/evp.h>

#include <ECDH.h>

std::pair<std::string, KeyPair> PerformECDH();
EC_KEY* Gen_Keypair_OpenSSL();
std::string Gen_Shared_OpenSSL(EC_KEY* key, const EC_POINT* pubkey);
std::string Get_Private_Key(EC_KEY* key);
Point Get_Public_Key(EC_KEY* key);


#endif // ECDH_OPENSSL_H
