#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no{
    int dado;
    struct no *prox;
}no;

typedef struct pilha{
    no *topoo;
}pilha;

void criaPilha(pilha *p){
    p->topoo = NULL;
}

void empilha(pilha *p, int dado){
    no *ptr = (no*) malloc(sizeof(no));
    ptr->dado = dado;
    ptr->prox = p->topoo;
    p->topoo = prox;
}

int desempilha(pilha *p){
    no *ptr = p->topoo;
    int dado;
    if(ptr==NULL){
        printf("Pilha vazia.\n");
    } else {
        p->topoo = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
        free(ptr);
        return dado;
    }
}

void imprime(pilha *p){
    no *ptr = p->topoo;
    if(ptr == NULL){
        printf("pilha vazia");
    }else{
        while(ptr != NULL){
            printf("%d ", ptr->dado);
            ptr = ptr->prox;
        }
        printf("\n");
    }
}

int main(){
    pilha *p1 = ()
}