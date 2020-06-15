#include "user.h"
#include "../GUI/GUI.h"

user* login(void){
    // 11 correspond a la longueur de users/data/ c'est juste pour limité les variable 
    char username[USERNAME_LENGTH],pwd[PWD_LENGTH],path[USERNAME_LENGTH + 11];
    
    char hash[FHLenth];
    
    user* uuser=NULL;
    int test;
    
    printf("Nom d'utilisateur:");
    
    strentry(username,USERNAME_LENGTH);
    
    FILE * userFile;
    sprintf(path,"users/data/%s",username);
    
    if ((userFile=fopen(path))){
        strentry(pwd,PWD_LENGTH);
        fgets(hash,FHLenth,userFile);
        test = hashComp(hash,userName,pwd);
        if (test ==0){
            printf("Succesfully login genrating keys");
            uuser = userFactory(username,pwd);
        }else{
            printf("Wrong PassWord");
        }
    } else {
        char t='f';
        while (t!='y' && t!= 'Y' && t!='n' && t != 'N'){
            printf("unknown username do you want to create a new user ?(y/n)");
            t=getch();
        }
        if (t == 'y' || t=='Y'){
            uuser=create();
        }
    }
    
    return uuser;
}
