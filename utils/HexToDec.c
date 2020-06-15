#include "utils.h"
#include <string.h>

int HexToDec(char* str)
{
    int lenth=strlen(str),i,R=0,T,pow=1;
    for (i=lenth-1;i>=0;i--)
    {

        if ((str[i]-'a')<0)
        {
            T=str[i]-48;
        }
        else
        {
            T=str[i]-'a'+10;
        }
        T *= pow;
        pow *= 16;
        R =R+T;
    }
    return R;
}

