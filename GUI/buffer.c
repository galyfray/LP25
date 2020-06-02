#include <stdio.h>
#include <stdlib.h>

void buffer() // Fonction permettant de vider le buffer
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}
