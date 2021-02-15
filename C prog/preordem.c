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

    pilha[++topo] = ptr;

    while(ptr != NULL || topo > -1){
        printf("%d ", pilha[topo]->dado);
        topo--;

        if(ptr->dir != NULL){
            pilha[++topo] = ptr->dir;
        }

        if(ptr->esq != NULL){
            pilha[++topo] = ptr->esq;
        }
        ptr=ptr->esq;
        //return;
    }

/*     do{
    
    //printf("%d ", ptr->dado);
    if (ptr->dir != NULL){
        pilha[++topo] = ptr->dir; 
    }
    if (ptr->esq != NULL){
        pilha[++topo] = ptr->esq;
        ptr=ptr->esq;
    }

    ptr = pilha[topo--];

    printf("%d ", ptr->dado);

    ptr = pilha[topo--];

    printf("%d ", ptr->dado);

    //printf("\n%d", topo);
    //return;

    /* if (topo == -1)
        break; */
 
    //ptr = pilha[topo--];
    //printf("%d ", ptr->dado);
    //ptr = ptr->dir;
    //return;
    //} while((ptr != NULL) || (topo > -1));
 
}

int main(){
    no *raiz = NULL;

    raiz = criaPilha(1);

    raiz->esq = criaPilha(2);
    raiz->dir = criaPilha(3);
    raiz->esq->esq = criaPilha(4);
    raiz->esq->dir = criaPilha(5);
    raiz->dir->esq = criaPilha(6);
    raiz->dir->dir = criaPilha(7);

    pre_ordem(raiz);
    printf("\n");
    exit(0);
}