#include <time.h>
#include <stdlib.h>

int rangedRandom(int rangestart, int rangeend){
    return random(rangestart)+(rangeend-rangestart);
}

int random(int max){
    static char init=0;
    if (init ==0) {
        srand(time(0));
        init=1;
    }
    return rand()%max;
}
