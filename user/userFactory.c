#include "user.h"
#include "../utils/utils.h"
#include <string.h>

#define ch(x, y, z)     ((x & y)^(~x & z))
#define maj(x, y, z)     ((x & y) ^ (x & z) ^ (y & z))

user* userFactory(char* userName,char*pwd){
    user* uuser = (user*)malloc(sizeof(user));

    char H[SHLength];
    
    truncated_md5(userName,(uint8_t)pwd[userName[1]%strlen(userName)],strlen(userName),H);
    
    DLList * numbers = primeNumberGenerator(10000);
    
    int s=floor(*numbers,1000),e=DLList_Length(*numbers);
    
    DLList * sub = DLList_subset(*numbers,s,e);
    
    DLL_Free(numbers);
    
    int l=DLList_Length(sub);
    
    int n1=maj(H[1],H[2],H[0])%l,n2=ch(H[6],H[7],H[5])%l;
    
    n1=DLList_find(sub,n1);
    n2=DLList_find(sub,n2)
    
    publicKeyGenerator(&(uuser->publicModulo), &(uuser->publicExponent), n1, n2);
    
    privateKeyGenerator(&(uuser->privateExponent), (uuser->publicExponent), n1, n2);
    
    uuser->userName=(char*)malloc(USERNAME_LENGTH);
    
    void * memcpy(uuser->userName,userName,USERNAME_LENGTH);
    
    DLL_Free(sub);
    return uuser;
}
