#include "GUI.h"

void affichageMenu(S_menu menu, int nbMenu, char* STRMENU)
{   
	strcat(STRMENU, "1: "); //Ecrit tout d'abord le premier choix dans la chaîne de caractère et en fonction du nombre de choix ajoute les choix manquants
	strcat(STRMENU, menu.menu1);
    	switch (nbMenu)
    	{
    		case 2:	strcat(STRMENU, "\n2: ");
			strcat(STRMENU, menu.menu2);
        		break;
    		case 3:	strcat(STRMENU, "\n2: ");
			strcat(STRMENU, menu.menu2);
        		strcat(STRMENU, "\n3: ");
			strcat(STRMENU, menu.menu3);
        		break;
    		case 4:	strcat(STRMENU, "\n2: ");
			strcat(STRMENU, menu.menu2);
        		strcat(STRMENU, "\n3: ");
			strcat(STRMENU, menu.menu3);
			strcat(STRMENU, "\n4: ");
			strcat(STRMENU, menu.menu4);
        		break;
    		case 5:	strcat(STRMENU, "\n2: ");
			strcat(STRMENU, menu.menu2);
        		strcat(STRMENU, "\n3: ");
			strcat(STRMENU, menu.menu3);
			strcat(STRMENU, "\n4: ");
			strcat(STRMENU, menu.menu4);
			strcat(STRMENU, "\n5: ");
			strcat(STRMENU, menu.menu5);
        		break;
    		case 6:	strcat(STRMENU, "\n2: ");
			strcat(STRMENU, menu.menu2);
        		strcat(STRMENU, "\n3: ");
			strcat(STRMENU, menu.menu3);
			strcat(STRMENU, "\n4: ");
			strcat(STRMENU, menu.menu4);
			strcat(STRMENU, "\n5: ");
			strcat(STRMENU, menu.menu5);
        		strcat(STRMENU, "\n6: ");
			strcat(STRMENU, menu.menu6);
        		break;
    		default:break;
    }
    strcat(STRMENU, "\0");
}

int afficherGUI(int numeroMenu, S_menu* menus, int nbChoix)
{
	char STRMENU[600];
	int choix;
	affichageMenu(menus[numeroMenu], nbChoix, STRMENU); //Transforme le Menu en chaîne de caractère formatée
	choix = choice(STRMENU, nbChoix, 0, 0); //Affiche l'interface à partir de la chaîne de caractère et du nombres de choix pour permettre un choix
	strcpy(STRMENU, ""); //Vide la chaîne de caractères
	return choix;
}
