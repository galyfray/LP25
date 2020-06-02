#ifndef GETCHARAC_H_INCLUDED
#define GETCHARAC_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int choice(char[], int, int,int);
listeCharac ajouter(listeCharac LC, char c);
int sumChar(listeCharac LC);
int getChar();
void buffer();

#ifdef __linux__
int getch(void);
int getche(void);
#define Curseur(x,y) printf("\033[%d;%dH", (y), (x))

#elif _WIN32
#include <conio.h>
#include <tchar.h>
#include <windows.h>
void Curseur(int,int);

#endif

#endif
