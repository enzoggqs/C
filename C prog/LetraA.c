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

void imprime (celula *le) {
   celula *p;
   for (p = le->prox; p != NULL; p = p->prox)
      printf ("%d -> ", p->dado);
    printf("NULL\n");
}

void imprime_rec (celula *le) {

    if (le != NULL) {
        if(le -> dado != 0)
        printf ("%d -> ", le->dado);
        imprime_rec (le->prox);
    }else{
        printf("NULL\n");
    }
}