#include"utils.h"

DLList* DLL_push_tail(DLList* list,void* data,size_t datasize){
    if (list == NULL){
        list = (DLList *)malloc(sizeof(DLList));
        list->tail=NULL;
        list->head=NULL;
    }    
        
    DLNode * node = (DLNode *)malloc(sizeof(DLNode));
    node->data=malloc(datasize);
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
    for (i=0; i<datasize; i++) 
        ((uint8_t *)(node->data))[i] = ((uint8_t *)(data))[i];
    
    return list;
}

void DLL_Free(DLList * list){
    DLNode* node = list->head, *node2=list->head->next;

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
    DLNode* node =list.head;
    while(node != NULL){
        l++;
        node=node->next;
    }
    return l;
}

DLNode* DDList_find(DLList list,int index){
    int l=0;
    DLNode* node =list.head;
    while(node != NULL && l<index){
        l++;
        node=node->next;
    }
    return node;
}

DLList* DLList_subset(DLList oldList,int from,int to){
    int l=0;
    DLNode * node = oldList.head;
    DLList * nList;
    
    while (l<from && node !=NULL){
        node = node->next;
        l++;
    }
    
    while (l<to && node != NULL){
        nList= DLL_push_tail(NULL,node->data,sizeof((*node->data)));
        node = node -> next;
        l++;
    }
    
    return nList;

}
