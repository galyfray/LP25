#ifndef GETCHARAC_H_INCLUDED
#define GETCHARAC_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structure_menu.h"

int choice(char[], int, int,int);
void buffer();
void conversionUE (char []);
void affichageMenu(S_menu menu, int nbMenu, char* STRMENU);
void rechercheMenu(S_menu [], int, int);
int afficherGUI(int numeroMenu, S_menu* menus, int nbChoix);

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
