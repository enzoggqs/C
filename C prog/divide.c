#include <stdio.h>
typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

void divide_lista (celula *l, celula *l1, celula *l2){
 
    celula *ptr=l->prox;
    celula *ptr1=l1;
    celula *ptr2=l2;
    int num;

    while(ptr!=NULL){
        num = ptr->dado;

    if(ptr->dado % 2==0){
        ptr2->prox=ptr;
        ptr2=ptr2->prox;
    }else{
        ptr1->prox=ptr;
        ptr1=ptr1->prox;
    }
        ptr=ptr->prox;
    }

    ptr1->prox=NULL;
    ptr2->prox=NULL;

}