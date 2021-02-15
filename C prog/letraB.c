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

celula *busca (celula *le, int x){
   celula *p;
   for (p = le; p != NULL && p->dado != x; 
      p = p->prox);
   return p;
}

celula *busca_rec (celula *le, int x){
    if (le == NULL)
        return NULL;
    if (le->dado == x)  return le;
        return busca_rec (le->prox, x);
} 