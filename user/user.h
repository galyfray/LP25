#ifndef USER_H
#define USER_H

#define USERNAME_LENGTH 25;
#define PWD_LENGTH 64;


typedef struct S_user {
    int * publicModulo;
    int * privateModulo;
    int * publicExponent;
} user;


#endif /*USER_H*/
