#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <openssl/ec.h>
#include <openssl/ecdh.h>
/*NID_X9_62_prime256v1*/
#include <openssl/evp.h>

/*Nice little macro to save a few lines.*/
void die(char *reason)
{
    fprintf(stderr, reason);
    fflush(stderr);
    exit(1);
}

/*Elliptic Curve Diffie-Hellman function*/
int EC_DH(unsigned char **secret, EC_KEY *key, const EC_POINT *pPub)
{
    int secretLen;

    secretLen = EC_GROUP_get_degree(EC_KEY_get0_group(key));
    secretLen = (secretLen + 7) / 8;

    *secret = (unsigned char*)malloc(secretLen);
    if (!(*secret))
        die("Failed to allocate memory for secret.\n");
    secretLen = ECDH_compute_key(*secret, secretLen, pPub, key, NULL);

    return secretLen;
}

/*Key generation function for throwaway keys.*/
EC_KEY* gen_key(void)
{
    EC_KEY *key;

    key = EC_KEY_new_by_curve_name(NID_secp256k1);
    if (key == NULL)
        die("Failed to create lKey object.\n");

    if (!EC_KEY_generate_key(key))
        die("Failed to generate EC key.\n");

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

int main(int argc, char **argv)
{
    EC_KEY *lKey, *pKey;
    int lSecretLen, pSecretLen;
    unsigned char *lSecret, *pSecret;

    lKey = gen_key();
    pKey = gen_key();

    lSecretLen = EC_DH(&lSecret, lKey, EC_KEY_get0_public_key(pKey));
    pSecretLen = EC_DH(&pSecret, pKey, EC_KEY_get0_public_key(lKey));
    if (lSecretLen != pSecretLen)
        die("SecretLen mismatch.\n");

    if (memcmp(lSecret, pSecret, lSecretLen))
        die("Secrets don't match.\n");

    BIGNUM *shared = BN_new();

    BN_bin2bn(lSecret, lSecretLen, shared);
    std::cout <<  BN_bn2dec(shared) << std::endl;

    Print_Key(pKey);

    Print_Key(lKey);

    free(lSecret);
    free(pSecret);
    EC_KEY_free(lKey);
    EC_KEY_free(pKey);
    CRYPTO_cleanup_all_ex_data();

    return 0;
}
