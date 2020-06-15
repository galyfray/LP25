#include"utils/utils.h"

#include<math.h>
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

int floor(DLList list,int value){
    if(list == NULL){return -1;}
    int index=0;
    DLNode* node = list.head;
    while( node != NULL && *(int*)node.value < value ){
        index++;
        node=node->next;
    }
    return index;
}

int randomPrimeNumberGenerator(int rangestart,int rangeend){
    DLList* numbers = primeNumberGenerator(rangeend);
    int l = DLList_Length(*numbers),s=floor(*numbers,rangestart);
    int n = rangedRandom(s,l);
    return *(int*)(DLList_find(*numbers,n)->value);
}

