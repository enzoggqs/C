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

void insere_inicio (celula *p, int x){
   celula *nova;
   nova = malloc (sizeof (celula));
   nova->dado = x;
   nova->prox = p->prox;
   p->prox = nova;
}

void insere_antes (celula *le, int x, int y){
   celula *p, *q, *nova;
   nova = malloc (sizeof (celula));
   nova->dado = x;
   p = le;
   q = le->prox;
   while (q != NULL && q->dado != y) {
      p = q;
      q = q->prox;
   }
   nova->prox = q;
   p->prox = nova;
}
