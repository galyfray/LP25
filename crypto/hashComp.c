#include "crypto.h"


uint8_t hashComp(char* hashStored,char*userName,char*password)
{
    char t[3],H[FHLenth];

    int offset=HexToDec(strcut(t,hashStored,0,2));/**< r�cupation de l'offset a partir du hash*/

    if(strcmp(hashStored,hasher(password,userName,offset,H))==0)/**< envoie des donn�es dans la fonction de hashage afin de le comparer avec nos donn�es stock�es */
    {
        return 0;
    }
    return 1;
}
