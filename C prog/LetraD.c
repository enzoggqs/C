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

int remove_depois (celula *p){
    int dado;
    celula *lixo;
    lixo = p->prox;
    dado = lixo -> dado;
    p->prox = lixo->prox;
    free (lixo);
    return dado;
}

void remove_elemento (celula *le, int x){
   celula *p, *q;
   p = le;
   q = le->prox;
   while (q != NULL && q->dado != x) {
      p = q;
      q = q->prox;
   }
   if (q != NULL) {
      p->prox = q->prox;
      free (q);
   }
}

void remove_todos_elementos (celula *le, int x){
    celula *p, *q, *lixo;
    lixo = le;
    p = le;
    q = le->prox;
    while (q != NULL){
        if(q->dado == x){

            p->prox = q->prox;
            free (q);
            /* lixo = q;
            p = q -> prox;
            free(lixo);
            q = p -> prox; */
        }else{
            p = q;
            q = q->prox;
        }

    }
}