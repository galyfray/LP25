#include "crypto.h"
#include <time.h>

DLList* primeNumberGenerator(int max){
    if (max <2){
        return (DLList *)NULL;    
    }
    
    int i=2,sqr;
    
    DLList* list = DLL_push_tail(NULL,&i,sizeof(int));
    DLNode* node;
    
    for(i=3;i<=max;i++){
        node = list->head;
        sqr = sqrt(i);
        while(node != NULL && *(int*)node->data <= sqr && i%*(int*)node->data != 0){
            node=node->next;
        }
        if(node == NULL || *(int*)node->data > sqr ){
            list = DLL_push_tail(list,&i,sizeof(int));
        }
    }
    
    return list;
    
}

int DLL_floor(DLList list,int value){
    int index=0;
    DLNode* node = list.head;
    while( node != NULL && *(int*)node->data < value ){
        index++;
        node=node->next;
    }
    return index;
}

