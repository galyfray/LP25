#include "user.h"
#include "../utils/utils.h"
#include <string.h>

#define ch(x, y, z)     ((x & y)^(~x & z))
#define maj(x, y, z)     ((x & y) ^ (x & z) ^ (y & z))

user* userFactory(char* userName,char*pwd){
    user* uuser = (user*)malloc(sizeof(user));

    char H[SHLenth];
    
    truncated_md5(userName,(uint8_t)pwd[userName[1]%strlen(userName)],strlen(userName),H);
    
    DLList * numbers = primeNumberGenerator(10000);
    
    int s=DLL_floor(*numbers,1000),e=DLList_Length(*numbers);
    
    DLList * sub = DLList_subset(*numbers,s,e);
    
    DLL_Free(numbers);
    
    int l=DLList_Length(*sub);
    
    int n1=maj(H[1],H[2],H[0])%l,n2=ch(H[6],H[7],H[5])%l;
    
    DLNode *node = DLList_find(*sub,n1);
    
    n1=*((int*)(node->data));
    
    node = DLList_find(*sub,n2);
    n2=*((int*)(node->data));
    
    publicKeyGenerator(&(uuser->publicModulo), &(uuser->publicExponent), n1, n2);
    
    privateKeyGenerator(&(uuser->privateExponent), (uuser->publicExponent), n1, n2);
    
    memcpy(uuser->userName,userName,USERNAME_LENGTH);
    
    DLL_Free(sub);
    return uuser;
}
