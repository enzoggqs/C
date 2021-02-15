#include <stdio.h> 
#include <stdlib.h> 
  
typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;
  
typedef struct pilha {  
    int topo; 
    int tam;
    no** vet; 
}pilha; 
  
no* criaNo(int dado) { 
    no* novo = (no*)malloc(sizeof(no)); 
    novo->dado = dado; 
    novo->esq = novo->dir = NULL; 
    return novo; 
} 

pilha* criaPilha(int tam) { 

    pilha* p = (pilha*)malloc(sizeof(pilha)); 
    p->topo = -1;
    p->tam = tam; 
    p->vet = (no**)malloc(p->tam * sizeof(no*)); 
    return p; 
} 

int ehCheia(pilha* pilha) { 
    return pilha->topo - 1 == pilha->tam; 
} 
  
int ehVazia(pilha* pilha) { 
    return pilha->topo == -1; 
} 
  
void empilha(pilha* pilha, no* no) { 
    if (ehCheia(pilha)){
        return; 
    }
    pilha->vet[++pilha->topo] = no; 
} 
  
no* desempilha(pilha* pilha) { 
    if (ehVazia(pilha)){
        return NULL; 
    }
    return pilha->vet[pilha->topo--]; 

} 
 
void pos_ordem(no* raiz) { 
    if (raiz == NULL){
        return; 
    }

    pilha* s1 = criaPilha(1000); 
    pilha* s2 = criaPilha(1000);
    empilha(s1, raiz); 
    no* arv;  
    while (!ehVazia(s1)) { 

        arv = desempilha(s1); 
        empilha(s2, arv); 

        if (arv->esq){
            empilha(s1, arv->esq); 
        }
        if (arv->dir){
            empilha(s1, arv->dir); 
        }
    } 
    while (!ehVazia(s2)) { 
        arv = desempilha(s2); 
        printf("%d ", arv->dado); 
    } 

    printf("\n");
} 