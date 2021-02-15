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
   for (p = le; p != NULL; p = p->prox)
      printf ("%d -> ", p->dado);
    printf("NULL\n");
}

void imprime_rec (celula *le) {
   if (le != NULL) {
      printf ("%d -> ", le->dado);
      imprime (le->prox);
   }else{
       printf("NULL\n");
   }
}

void inserir_inicio (celula **p, int x) {
    celula *novo = malloc (sizeof (celula));
    if (novo == NULL) exit (1);
    novo -> dado = x;
    novo->prox = *p;
    *p = novo;
}

void busca_e_insere (celula *le, int x, int y){
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
    lixo = q-> prox;
    while (lixo != NULL){
        if(lixo->dado == x){
            free(lixo);
            p = lixo->prox;
            q = p->prox;
            lixo = q -> prox;
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

void mescla_listas (celula *l1, celula *l2, celula *l3){
    if(l2 && l1){
        if(l1 -> dado <= l2 -> dado){
            l3 = l1;
            l1 = l3 -> prox;
        }else{
            l3 = l2;
            l2 = l3 -> prox;
        }
    }
    while(l1 && l2){
        if(l1 -> dado <= l2 -> dado){
            l3 -> prox = l1;
            l3 = l1;
            l1 = l3 -> prox;
        }else{
            l3 -> prox = l2;
            l3 = l2;
            l2 = l3->prox;
        }
    }
}

int main () {
    celula *p = cria_lista();
    celula *q = cria_lista();
    celula *t = cria_lista();

    imprime_rec (p);
    imprime (p);
    
    inserir_inicio(&p, 85);
    inserir_inicio(&p, 324);
    inserir_inicio(&p, 342);
   inserir_inicio(&p, 242);
    inserir_inicio(&p, 324);
    inserir_inicio(&p, 242);
    inserir_inicio(&p, 324);

    imprime_rec(p);
    imprime(p);


    imprime_rec(p);
    imprime(p);
  
    inserir_inicio(&q, 70);
    inserir_inicio(&q, 330);
    inserir_inicio(&q, 500);

    imprime(q);

    mescla_listas(p, q, t);

    imprime(t);

    return 0;
}


/* void imprimir (no *p) {
    printf("p -> ");
    for (no *ptr = p; ptr != NULL; ptr = ptr->prox)
        printf("%d -> ", ptr->dado);void imprimir (no *p) {
    printf("p -> ");
    for (no *ptr = p; ptr != NULL; ptr = ptr->prox)
        printf("%d -> ", ptr->dado);
    printf("NULL\n");
}
    printf("NULL\n");
} */