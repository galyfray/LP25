#include "GUI.h"

int strentry(char *chaine, int longueur) // Permet l'entrée de chaînes de caractères de manière sécurisées
{
    char *positionEntree = NULL;
    if (fgets(chaine, longueur, stdin) != NULL)
    {
        positionEntree = strchr(chaine, '\n');
        if (positionEntree != NULL)
        {
            *positionEntree = '\0';
        }
        else
        {
            buffer();
            chaine[longueur -1] = '\0';
        }
        return 1;
    }
    else
    {
        buffer();
        return 0;
    }
}
