#include <stdio.h>
#include <stdlib.h>

typedef struct no{
   int dado;
   struct no *esq;
   struct no *dir;
} no;

no *criaPilha(int elem){
   no *node;

   node = (no *) malloc(sizeof(no));

   node->dado = elem;
   node->esq = NULL;
   node->dir = NULL;

   return node;
}

void pre_ordem(no *raiz){
    no *pilha[1000];
    int topo=-1;

    no *ptr = raiz;


    if (ptr == NULL)
        return;

    do{
    while (ptr != NULL)
    {
        pilha[++topo] = ptr; 
        if(ptr != NULL){
            printf("%d ", ptr->dado);
        }
        ptr = ptr->esq;
        
        
        
    }

    if (topo == -1)
        break;
 
    ptr = pilha[topo--];
    ptr = ptr->dir;
    } while((ptr != NULL) || (topo > -1));

}
