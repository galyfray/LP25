#include "crypto.h"
#include "../utils/utils.h"



char* hasher(char* password,char*userName,uint8_t offset,char*hashOutput)
{
    size_t passLenth=strlen(password),Hl=passLenth+SHLenth;
    uint8_t offsetM=offset%passLenth; /**< offsetM et forc�ment plus petit que la longueur de MdP et assure la d�coupe de celui-ci*/
    char hashOffset[FHLenth],hashP1[(passLenth+abs(passLenth-2*(offsetM)))/2 +1 /**< d�termine le max entre passLent-(offsetM) et offsetM */];
    char Thash[Hl];//contiendra la chaine a hacher;

    uint32_t state[8]={0xa9f5b3d9*offset,0x25abc59e*offsetM,0xa54ff53a*passLenth,0x9b05688c,0xa25fe45f,0xf255ad64,0xfafad,0x836d5f8a};

    truncated_md5(userName,offset,strlen(userName),hashOffset);/**< hashage du nom d'utilisateur*/

    /** 1:troncage du MdP a longueur de OffsetM
     *  2:stockage de cette partie tronqu�e
     *  3:concat�nation de la partie tronqu�e avec le hash du nom d'utilisateur
     *  4:concat�nation avec le type de l'utilisateur
     *  5:d�coupage du MdP afin d'en obtenir la moiti� manquante
     *  6:concat�nation du tout sous la forme [MdP partie1][hash du Usrnm][[MdP partie2]
     */
    strcut(hashP1,password,0,offsetM);
    strcpy(Thash,hashP1);
    strcat(Thash,hashOffset);
    strcut(hashP1,password, offsetM,passLenth);
    strcat(Thash,hashP1);

    sha256(state,(uint8_t *)password,strlen(password)*8,hashOffset);/**< hash du MdP sal� */

    sprintf(hashOutput,"%02x%s",offset,hashOffset);/**< concat�nation du hash avec l'offset stock� sur 2 caract�res hexad�cimaux pour se fondre dans le hash*/

    return hashOutput;
}
