#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

int randomInt(int max){
    static char init=0;
    if (init ==0) {
        srand(time(0));
        init=1;
    }
    return rand()%max;
}

int rangedRandom(int rangestart, int rangeend){
    return randomInt(rangestart)+(rangeend-rangestart);
}

void pwdCreator(char* pwdOut,int length)
{
    srand((unsigned int) time(0));

    // ASCII characters 33 to 126
    for(int i = 0; i < length-1; i++)
    {
    	pwdOut[i] = rand()%94+33;
    }
    pwdOut[length-1]='\0';

}
