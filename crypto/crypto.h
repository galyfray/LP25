#ifndef CRYPTO_H
#define CRYPTO_H

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "../utils/utils.h"

//longueur des Hash produit pas les fonctions de hash \0 compris
#define FHLenth 67 // hash produit par hasher
#define SHLenth 9  // hash produit par truncated_md5

// the gcd function 
int gcd(int, int);

// Compute the inverse of a (mod b) thanks to the extended euclidean algorithm
int modularMultiplicativeInverse(int, int);

// Generate the RSA encryption's public keys, the KeyModulus and the KeyExponent, thanks to help 
// of two prime numbers
void publicKeyGenerator(int*, int*, int, int);

// Compute a^k (mod n)
int modularExponentiation(int, int, int);

// Generate the RSA decryption's private key, the KeyExponent, thanks to help 
// of two prime numbers and the publicKeyExponent
void privateKeyGenerator(int*, int, int, int);

// Encryption of a message thanks to the RSA system
int* RSAencryption(char*, int, int, int);

// Decryption of a encrypted message with the RSA system
char* RSAdecryption(int*, int, int, int);

DLList* primeNumberGenerator(int);

int floor(DLList,int);

char* hasher(char* ,char* ,uint8_t ,char* );

char* truncated_md5(char* ,uint8_t ,size_t ,char* );

char* sha256(uint32_t*,uint8_t* ,uint32_t ,char* );

uint8_t hashComp(char*,char*,char*);

#endif /* CRYPTO_H */
