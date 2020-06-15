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

void DLL_Free(DLList * list){
    DLNode* node = list->head,node2=list->head->next;

    while(node2 !=NULL){
        free(node);
        node=node2;
        node2=node->next;
    }
    free(node);
    
    free(list);

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

DLList* subset(DLList oldList,int from,int to){
    int l=0;
    DLNode * node = oldList.head;
    DLList * nList;
    
    while (l<from && node !=NULL){
        node = node->next;
        l++;
    }
    
    while (l<to && node != NULL){
        nList= DLL_push_tail(NULL,node->value,sizeof(*(node->value)));
        node = node -> next;
        l++;
    }
    
    return DLList;

}
