#include "crypto.h"

#define ROTR(x, y)    ((x>>y)|(x<<(32-y)))
#define ch(x, y, z)     ((x & y)^(~x & z))
#define maj(x, y, z)     ((x & y) ^ (x & z) ^ (y & z))

#define SIGMA0(x)    ( ROTR(x,2) ^ ROTR(x,13) ^ ROTR(x,22))
#define SIGMA1(x)    ( ROTR(x,6) ^ ROTR(x,11) ^ ROTR(x,25))
#define sigma0(x)    ( ROTR(x,7) ^ ROTR(x,18) ^ (x>>3))
#define sigma1(x)    ( ROTR(x,17) ^ ROTR(x,19) ^ (x>>10))


char *sha256(uint32_t stat[8]/*composante de base du hash*/, uint8_t data[]/*donnée a hasher*/,uint32_t lenth/*lenth en bits limité en 32 les opérateurs ne marchent pas avec 64*/,char out[]/*output de la fonction longeur mini:64 hormis '\0'*/)
{
    //bourrage des données entrante
    uint16_t k = (448-(lenth+1))%512;//détermine le volume k de bits a bourrer

    if(k<0)
        k+=512;//évite les k négatif

    uint32_t Dlenth=k + lenth + 65;// la longueur totale a hasher multiple de 512
    uint8_t *Data=(uint8_t*)calloc(1,Dlenth),block,i;//alloue l'espace ram nécessaire a Data et remplit l'espace alloué de 0
    memcpy(Data,data,lenth/8);//copie les données de data vers Data, on aurait put utiliser la fonction realloc, mais ceci permet de conserver data au besoin


    /*bourrage*/
    if(lenth>Dlenth)
    {
        Data[lenth/8]=0x80;
        for (i=0;i<32;i=i+8)
        {
            if(Data[(Dlenth-i)/8]==0)
                Data[(Dlenth-i)/8]=(uint8_t)(lenth>>i);
        }

    }
    /*calcul du hash*/
    //initialisation des tableaux de constantes
    uint32_t K[]=  { 0x428a2f98 ,0x71374491 ,0xb5c0fbcf ,0xe9b5dba5 ,0x3956c25b ,0x59f111f1 ,0x923f82a4 ,0xab1c5ed5
                    ,0xd807aa98	,0x12835b01	,0x243185be	,0x550c7dc3	,0x72be5d74	,0x80deb1fe	,0x9bdc06a7	,0xc19bf174
                    ,0xe49b69c1	,0xefbe4786	,0x0fc19dc6	,0x240ca1cc	,0x2de92c6f	,0x4a7484aa	,0x5cb0a9dc	,0x76f988da
                    ,0x983e5152	,0xa831c66d	,0xb00327c8	,0xbf597fc7	,0xc6e00bf3	,0xd5a79147	,0x06ca6351	,0x14292967
                    ,0x27b70a85	,0x2e1b2138	,0x4d2c6dfc	,0x53380d13	,0x650a7354	,0x766a0abb	,0x81c2c92e	,0x92722c85
                    ,0xa2bfe8a1	,0xa81a664b	,0xc24b8b70	,0xc76c51a3	,0xd192e819	,0xd6990624	,0xf40e3585	,0x106aa070
                    ,0x19a4c116	,0x1e376c08	,0x2748774c	,0x34b0bcb5	,0x391c0cb3	,0x4ed8aa4a	,0x5b9cca4f	,0x682e6ff3
                    ,0x748f82ee	,0x78a5636f	,0x84c87814	,0x8cc70208	,0x90befffa	,0xa4506ceb	,0xbef9a3f7	,0xc67178f2
                    };

    uint32_t state[8];
    memcpy(state,stat,32);//copie de stat dans states pour ne pas le modifier

    uint32_t M[64];//le tableau contiendra 64 mot de 32 bit dépendant de 512 bits de Data

    block=Dlenth/512;//découpage en block de 512 bits

    uint32_t a,b,c,d,e,f,g,h,T1,T2;// variables servant aux diverse opérations

    while(block)//travail itératif sur chaque block
    {
        memcpy(M,Data,64);//copie les 512 premier bits de Data dans M
        Data+=64;

        for (i=16;i<64;i++)//remplissage des 196 autres octet de M en fonction des 16 premiers (donc 512 premiers bits)
        {
            M[i]= sigma1(M[i-2]) + M[i-7] +sigma1(M[i-15]) + M[i-16] ;
        }

        a=state[0];
        b=state[1];
        c=state[2];
        d=state[3];
        e=state[4];
        f=state[5];
        g=state[6];
        h=state[7];

        for (i=0;i<64;i++)
        {
            T1=h+SIGMA1(e)+ch(e,f,g)+K[i]+M[i];
            T2=SIGMA0(a)+maj(a,b,c);
            h=g;
            g=f;
            f=e;
            e=d+T1;
            d=c;
            c=b;
            b=a;
            a=T1+T2;
        }
        state[0]+=a;
        state[1]+=b;
        state[2]+=c;
        state[3]+=d;
        state[4]+=e;
        state[5]+=f;
        state[6]+=g;
        state[7]+=h;

        block --;
    }

    sprintf(out,"%08x%08x%08x%08x%08x%08x%08x%08x",state[0],state[1],state[2],state[3],state[4],state[5],state[6],state[7]);

    free(Data);//libère l'espace pris par Data

    return out;
}
