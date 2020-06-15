#ifndef CRYPTO_H
#define CRYPTO_H

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

int randomPrimeNumberGenerator(int rangestart,int rangeend);

#endif /* CRYPTO_H */
