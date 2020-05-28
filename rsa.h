#ifndef rsa_h
#define rsa_h

// the gcd function 
int gcd(int a, int b);

// Compute the inverse of a (mod b) thanks to the extended euclidean algorithm
int modularMultiplicativeInverse(int a, int b);

// Generate the RSA encryption's public keys, the KeyModulus and the KeyExponent, thanks to help 
// of two prime numbers
void publicKeyGenerator(int* publicKeyModulus, int* publicKeyExponent, int primeNumber1, int primeNumber2);

// Compute a^k (mod n)
int modularExponentiation(int a, int k, int n);

// Generate the RSA decryption's private key, the KeyExponent, thanks to help 
// of two prime numbers and the publicKeyExponent
void privateKeyGenerator(int* privateKeyExponent, int publicKeyExponent, int primeNumber1, int primeNumber2);

// Encryption of a message thanks to the RSA system
int* RSAencryption(char* message, int messageSize, int publicKeyExponent, int publicKeyModulus);

// Decryption of a encrypted message with the RSA system
char* RSAdecryption(int* message, int messageSize, int privateKeyExponent, int publicKeyModulus);


#endif /* rsa_h */