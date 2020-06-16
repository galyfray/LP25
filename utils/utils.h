#ifndef UTILS
#define UTILS

#include<stdint.h>
#include<stdio.h> 
#include<stdlib.h> 


//double linked node
typedef struct S_DLNode{
    void* data;
    size_t size;
    struct S_DLNode* prev;
    struct S_DLNode* next;
    
} DLNode;

//double linked list
typedef struct S_DLList{
    DLNode* head;
    DLNode* tail; 
} DLList;

DLList* DLL_push_tail(DLList*,void*,size_t);

void printList(DLList, void (*fptr)(void *));

int DLList_Length(DLList);

DLNode* DLList_find(DLList,int);

void DLL_Free(DLList*);

DLList* DLList_subset(DLList,int,int);

int rangedRandom(int , int);

int randomInt(int);

int HexToDec(char*);

char* strcut(char*,char*,int,int);

void pwdCreator(char*,int);

#endif
