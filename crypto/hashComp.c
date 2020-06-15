#include "crypto.h"
#include "../utils/utils.h"

uint8_t hashComp(char* hashStored,char*userName,char*password,char* userType)
{
    char t[3],H[FHLenth];

    int offset=HexToDec(strcut(t,hashStored,0,2));/**< récupation de l'offset a partir du hash*/

    if(strcmp(hashStored,hasher(password,userName,userType,offset,H))==0)/**< envoie des données dans la fonction de hashage afin de le comparer avec nos données stockées */
    {
        return 0;
    }
    return 1;
}
