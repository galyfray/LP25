#include "user.h"
#include "../GUI/GUI.h"

user* create(){
    // 11 correspond a la longueur de users/data/ c'est juste pour limité les variable 
    char username[USERNAME_LENGTH],pwd[PWD_LENGTH],path[USERNAME_LENGTH + 11];
    printf("Nom d'utilisateur:");
    strentry(username,USERNAME_LENGTH);
    strentry(pwd,PWD_LENGTH);
    
    //FILE * userFile;
    sprintf(path,"users/data/%s",username);
    
    printf("genrating keys ...");
    
    user* uuser=userFactory(username,pwd);
    
    return uuser;
    
}
