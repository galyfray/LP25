#ifndef GETCHARAC_H_INCLUDED
#define GETCHARAC_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structure_menu.h"

int strentry(char*, int); //Entrée de chaîne de caractère sécurisée sans dépassement de buffer
int choice(char[], int, int,int); //Permet à partir d'une chaîne de caractère de générer une interface de sélection de menu avec le curseur
void buffer(); //Vide le buffer
void conversionUE (char []); //Converti les underscores d'une chaîne de caractère en espaces
void affichageMenu(S_menu menu, int nbMenu, char* STRMENU); //Change un menu en une unique chaîne de caractère 
void rechercheMenu(S_menu [], int, int); //Va chercher les différents menus dans le .txt où ils sont stockés
int afficherGUI(int numeroMenu, S_menu* menus, int nbChoix); //Affiche le GUI à l'aide des fonctions choice et affichageMenu

#ifdef __linux__
int getch(void); //Permet de réaliser getch en Linux donc, sans conio.h
int getche(void); //Permet de réaliser getche en Linux donc, sans conio.h
#define Curseur(x,y) printf("\033[%d;%dH", (y), (x)) //Déplace le curseur sous Linux


#elif _WIN32
#include <conio.h>
#include <tchar.h>
#include <windows.h>
void Curseur(int,int); //Déplace le curseur sous Windows

#endif

#endif
