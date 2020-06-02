#include "GUI.h"
#ifdef __linux__
#define ENTREE 10

#elif _WIN32
#define ENTREE 13

#endif

/*Flèche haut Linux 27 91 65
Flèche bas Linux 27 91 66
Flèche droit Linux 27 91 67
Flèche gauche Linux 27 91 68
Entrée Linux 10*/

int choice(char T[], int nbchoix, int lignedebut,int forceNumPad/**< si !=0 alors les indications via pavé numérique valideront automatiquement la saisie */)
{
    int entree, y=lignedebut;
	#ifdef _WIN32
    system("cls"); // Ferme la console et en ouvre une nouvelle vierge
    printf("%s", T);
    Curseur(0,y); // Place le curseur au niveau du choix
	
    do
    {
       entree = getch();
       if (entree == 224) // Si getch() renvoie 224 alors il garde des données dans le buffer pour certaines touches du clavier comme les flèches par exemple
       {
            entree = entree + getch(); // Ajoute aux 224 déjà obtenue la valeurs restante dans le buffer
            if (entree == 296) // Changement de la ligne du curseur en fonction des différents appuis sur les flèches du clavier
            {
                y--;
            }
            if (entree == 304)
            {
                y++;
            }
       }
       else
       {
           //permet de choisir avec les nombres
            if (entree<=57 && entree>=49)
            {
                y=entree-49+lignedebut;
                if(forceNumPad)
                    entree=ENTREE;
            }
        }
        if (y>nbchoix-1+lignedebut)
        {
            y=nbchoix-1+lignedebut;
        }
        if (y < lignedebut)
        {
            y=lignedebut;
        }
        Curseur(0,y); // Déplacement du curseur avec la nouvelle valeur de y

    }
    while(entree != ENTREE); // 13 est ce que renvoie getch() lorsqu'on appuie sur "Entrée"
    system("cls"); // Ferme la console et en ouvre une nouvelle vierge
	#elif __linux__
	system("clear");
	printf("%s", T);
	Curseur(0,y+1);
	
	do
	{
		entree = getch();
		if(entree == 27)
		{
			entree += getch();
			if(entree == 118)
			{
				entree += getch();
				if (entree == 183)
				{
					y--;
				}
				if (entree == 184)
					y++;
			}
		}
		else
       {
           //permet de choisir avec les nombres
            if (entree<=57 && entree>=49)
            {
                y=entree-49+lignedebut;
                if(forceNumPad)
                    entree=ENTREE;
            }
        }
        if (y>nbchoix-1+lignedebut)
        {
            y=nbchoix-1+lignedebut;
        }
        if (y < lignedebut)
        {
            y=lignedebut;
        }
        Curseur(0,y+1); // Déplacement du curseur avec la nouvelle valeur de y
	}
	while(entree != ENTREE);
	system("clear");
	#endif
	
    return y+1-lignedebut; // Renvoie la valeur du choix fait par l'utilisateur
}

#ifdef _WIN32
void Curseur(int x,int y)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE); // Défini la fenêtre où l'on modifiera le curseur
    COORD C; // Défini une variable du type coordonées
    C.X=(SHORT)x; // Défini la ligne où on veut placer le point C
    C.Y=(SHORT)y; // Défini la colonne où l'on veut placer C
    SetConsoleCursorPosition(H,C); // Place le curseur au niveau du point C défini
}
#endif
