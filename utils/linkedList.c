#include"linkedList.h"

DLList* DLL_push_tail(DLList* list,void* value,size_t valuesize){
    if (list == NULL){
        list = (DLList *)malloc(sizeof(DLList));
        list->tail=NULL;
        list->head=NULL;
    }    
        
    DLNode * node = (DLNode *)malloc(sizeof(DLNode));
    node->data=malloc(valuesize);
    node->next=NULL;
    if (list->tail != NULL){
        list->tail->next= node;
    }
    node->prev=list->tail;
    list->tail=node;
    
    if(list->head==NULL){
        list->head=list->tail;
    }
    
    int i; 
    for (i=0; i<valuesize; i++) 
        ((uint8_t *)(node->data))[i] = ((uint8_t *)(value))[i];
    
    return list;
}

void printList(DLList list, void (*fptr)(void *)) {
    DLNode *  node= list.head; 
    while (node != NULL){
     
        (*fptr)(node->data); 
        node = node->next; 
    } 
} 

int DLList_Length(DLList list){
    int l=0;
    if (list == NULL){return -1;}
    DLNode* node =list.head;
    while(node != NULL){
        l++;
        node=node->next;
    }
    return l;
}

DLLnode* DDList_find(DLList list,int index){
    int l=0;
    if (list == NULL){return -1;}
    DLNode* node =list.head;
    while(node != NULL && l<index){
        l++;
        node=node->next;
    }
    return node;
}
