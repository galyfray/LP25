#ifndef USER_H
#define USER_H

#define USERNAME_LENGTH 25;
#define PWD_LENGTH 64;

#include "../crypto/crypto.c"
#include <stdio.h>

typedef struct S_user {
    char userName[USERNAME_LENGTH];
    int publicModulo;
    int privateExponent;
    int publicExponent;
} user;

user* login(void);

user* userFactory(char*,char*);

#endif /*USER_H*/
