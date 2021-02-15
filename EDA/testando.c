#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int dado;
  struct no *esq, *dir;
} no;

typedef struct pilha{
    int dado[50];
    int topoo;
}pilha;

void cria_pilha(pilha *p){
    p->topoo = -1;
}

int eh_vazia(pilha *p){
    if(p->topoo == -1){
        return 1;
    }else{
        return 0;
    }
}

int esta_cheia(pilha *p){
    if(p-> topoo == 49){
        return 1;
    } else {
        return 0;
    }
}

void push(pilha *p, int x){
    if(esta_cheia(p) == 1){
        printf("Pilha cheia!!");
    }else{
        p->topoo++;
        p->dado[p->topoo] = x;
    }
}

int pop(pilha *p){
    int aux;
    if(eh_vazia(p) == 1){
        printf("Pilha vazia!!\n");
    }else{
        aux = p->dado[p->topoo];
        p->topoo--;
        return aux;
    }
}

int main(){
    pilha *p = (pilha*)malloc(sizeof(pilha));
    int aux;
    cria_pilha(p);

    push(p, 1);
    push(p, 5);

    aux = pop(p);

    printf("%d\n", aux);

    return 0;
}