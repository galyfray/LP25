#include "../GUI/GUI.h"
#include "../crypto/crypto.c"
#include <stdio.h>

user login(void){
    // 11 correspond a la longueur de users/data/ c'est juste pour limité les variable 
    char username[USERNAME_LENGTH],pwd[PWD_LENGTH],path[USERNAME_LENGTH + 11];
    
    char hash[]
    
    printf("Nom d'utilisateur:");
    
    strentry(username,USERNAME_LENGTH);
    
    FILE * userFile;
    sprintf(path,"users/data/%s",username);
    
    if ((userFile=fopen(path))){
        strentry(pwd,PWD_LENGTH);
        
    }
}
