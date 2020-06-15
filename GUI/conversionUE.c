#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void conversionUE(char information[]){ //transforme les underscores d'une chaîne de caractères en espaces

    int i=0;

    while(information[i] != '\0'){
        if(information[i]=='_')
        {
            information[i] = ' ';
        }
        i++;
    }
}
