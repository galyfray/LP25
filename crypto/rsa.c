// rsa.c
// RSA system

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "crypto.h"

/*************************************************************************************************/

int gcd(int a, int b)
{
	while(a != b)
	{
		if(a > b) a = a - b;
	    else b -= a;
	}
    return a;
}

/*************************************************************************************************/

int ModularMultiplicativeInverse(int a, int b)
{
    int x = 0, y = 1, lastx = 1, lasty = 0, temp;
    while (b != 0)
    {
    	int quotient = a / b;
        int remainder = a % b;
 
        a = b;
        b = remainder;
 
       	temp = x;
        x = lastx - quotient * x;
        lastx = temp;
 
        temp = y;
        y = lasty - quotient * y;
        lasty = temp;            
        }

    if (lastx <= 0) return lasty;
    else return lastx;
}

/*************************************************************************************************/

void publicKeyGenerator(int* publicKeyModulus, int* publicKeyExponent, int primeNumber1, int primeNumber2)
{
    // First Key :
    *publicKeyModulus = primeNumber1*primeNumber2;
    int phiOfKeyModulus = (primeNumber1-1)*(primeNumber2-1);

    // Second Key :
    // We are looking for the GCD of publicKeyExponent and phiOfKeyModulus such that it is equal to 1 
    // and that the publicKeyExponent is big enough
    *publicKeyExponent = 3;
    while((gcd(*publicKeyExponent,phiOfKeyModulus) != 1) || (primeNumber1*2 >= *publicKeyExponent) || (primeNumber2*2 >= *publicKeyExponent))
    {
        *publicKeyExponent = *publicKeyExponent + 1;
    } 
}

/*************************************************************************************************/

void privateKeyGenerator(int* privateKeyExponent, int publicKeyExponent, int primeNumber1, int primeNumber2)
{
	int phiOfKeyModulus = (primeNumber1-1)*(primeNumber2-1);
	// The private Key Exponent is the inverse of the public Key Exponent modulus phiOfKeyModulus
    *privateKeyExponent = ModularMultiplicativeInverse(publicKeyExponent,phiOfKeyModulus);
}

/*************************************************************************************************/

int modularExponentiation(int a, int k, int n) 
{ 
    long power = 1;
    a = a%n;
    while (k %2==0 && k>0)
    {
      a*=a;
      a = a%n;
    }
    for (int i=0;i<k;i++)
    {
      power *= a;
      power = power %n;
    }
    return power;
}

/*************************************************************************************************/

int* RSAencryption(char* message, int messageSize, int publicKeyExponent, int publicKeyModulus)
{
    int* encryptedMessage = malloc(messageSize*sizeof(int));

    // Encrypt character by character the message m thanks to the public keys and ASCII codes
    // x = m^publicKeyExponent (mod publicKeyModulus)
    for(int i = 0; i < messageSize; i++)
    {
        encryptedMessage[i] = modularExponentiation(message[i],publicKeyExponent,publicKeyModulus);
    }
    return encryptedMessage;
}

/*************************************************************************************************/

char* RSAdecryption(int* message, int messageSize, int privateKeyExponent, int publicKeyModulus)
{
    char* decryptedMessage = malloc(messageSize*sizeof(char));

    // Decrypt block by block the message x 
    // thanks to the public key modulus and the private key and ASCII codes
    // m = x^privateKeyExponent (mod publicKeyModulus)
    for(int i = 0; i < messageSize; i++)
    {
        decryptedMessage[i] = modularExponentiation(message[i],privateKeyExponent,publicKeyModulus);
    }
    return decryptedMessage;
}
