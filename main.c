#include "GUI/GUI.h"
#include "crypto/crypto.h"

int main(int argc, char** argv)
{
	S_menu menus [40];
    	rechercheMenu(menus,40,6);
	int choix;
	do
	{
		choix = afficherGUI(0, menus, 2);
		if(choix == 1)
		{
			//fonction de connection
			do
			{
				choix = afficherGUI(1, menus, 3);
				switch(choix)
				{
					case 1: choix = afficherGUI(2, menus, 5);
						switch(choix)
						{
							case 1: choix = afficherGUI(4, menus, 3);
								switch(choix)
								{
									case 1: //fonction generation manuelle de mdp
										break;
									case 2: //fonction generation mdp aleatoire
										break;
									case 3: choix = 0;
										break;
									default: break;
								}
								break;
							case 2: //fonction supprimer mot de passe
								break;
							case 3: //fonction modifier mot de passe
								choix=0;
								break;
							case 4: //fonction afficher mots de passes
								break;
							case 5: break;
							default: break;
						}
						break;
					case 2: choix = afficherGUI(3, menus, 3);
						switch(choix)
						{
							case 1: //fonction modifier username
								break;
							case 2:	//fonction modifier mot de passe de son compte
								break;
							case 3: choix = 0;
								break;
							default: break;
						}
					case 3: break;
					default: break;
				}
			}while(choix!=3);
								
			
			choix = 0;
		}
	}while(choix!=2);	
	return 0;
}
