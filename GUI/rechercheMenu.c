#include "GUI.h"

void rechercheMenu(S_menu* listeMenu,int nbrMenu, int nbMenu){
    char ligne[30];
    FILE* fichier = NULL;

    fichier = fopen("liste_menus.txt", "r");
    int i=0;

    if(fichier != NULL)
    {
    	while(fgets(ligne,30,fichier)!= NULL &&i<nbrMenu)
    	{
        	fscanf(fichier,"/----\n%s\n%s\n%s\n%s\n%s\n%s\n----/", listeMenu[i].menu1, listeMenu[i].menu2, listeMenu[i].menu3, listeMenu[i].menu4, listeMenu[i].menu5, listeMenu[i].menu6);

        	conversionUE(listeMenu[i].menu1);
        	conversionUE(listeMenu[i].menu2);
        	conversionUE(listeMenu[i].menu3);
        	conversionUE(listeMenu[i].menu4);
        	conversionUE(listeMenu[i].menu5);
        	conversionUE(listeMenu[i].menu6);
        	i++;
    	}
        fclose(fichier);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier liste_menus.txt");
    }
}
