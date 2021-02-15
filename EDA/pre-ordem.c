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
 
void pre_ordem (no *raiz){ 
    if (raiz == NULL){
        return; 
    }

    pilha* s1 = criaPilha(1000); 
    empilha(s1, raiz); 
    no* arv;
    while (!ehVazia(s1)) { 

        arv = desempilha(s1);
        printf("%d ", arv->dado);

        if (arv->dir){
            empilha(s1, arv->dir); 
        }
        
        if (arv->esq){
            empilha(s1, arv->esq); 
        }
        
    } 

    printf("\n");
} 

int main() { 
    no* raiz = NULL; 
    raiz = criaNo(1); 
    raiz->esq = criaNo(3); 
    raiz->dir = criaNo(2); 
    raiz->esq->esq = criaNo(5); 
    raiz->esq->dir = criaNo(8); 
    raiz->esq->esq->esq = criaNo(9);
    raiz->dir->esq = criaNo(0); 
    raiz->dir->dir = criaNo(4); 
    raiz->dir->dir->esq = criaNo(7);
  
    pre_ordem(raiz); 
  
    return 0; 
}