#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *cria_lista () {
    celula *le;
    le = NULL;
    return le;
}

void mescla_listas (celula *l1, celula *l2, celula *l3){
    if (l1->prox == NULL){
        l3->prox = l2->prox;
        return;
    }else if(l2 -> prox == NULL){
        l3 -> prox = l1 -> prox;
        return;
    }else if(l1->prox->dado <= l2->prox->dado){
        celula *t = l1->prox->prox;
        l3->prox = l1->prox;
        l3 = l3->prox;
        l3->prox = NULL;
        l1->prox = t;
        return mescla_listas(l1, l2, l3);        
    }else if(l1->prox->dado > l2->prox->dado){
        celula *b = l2->prox->prox;
        l3->prox = l2->prox;
        l3 = l3->prox;
        l3->prox = NULL;
        l2->prox = b;
        return mescla_listas(l1, l2, l3);
    }
}
