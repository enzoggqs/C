#include <stdio.h>

typedef struct pilha {
    char elementos[100];
    int topo;
} Pilha;

Pilha create(){
    Pilha *p;
    p->topo = -1;
    p->elementos[100];
}

int isFull(Pilha p){
    if (p->topo == 100-1)
        return 1;
    else
        return 0;
}

char pop(Pilha *p){
    char c = p->elementos[p->topo];
    p->topo--;
    return c;
}

void push(Pilha *p, char c){
    if (isFull(p))
        return 0;
    else{
        p->topo++;
        char p->elementos[p->topo] = c;
        return 1;
    }
}
int isEmpty(Pilha p){
    if (p->topo == -1)
        return 1;
    else
        return 0;

}

int size(Pilha p){
    int tam;
    tam = p->topo; + 1;
    return tam;
}

int main(){
    int QtCar, idx, lvl;
    char charlvl[10];

    printf("Quantidade de caracteres:\n");
    scanf("%d",&QtCar);

    char Fr[QtCar];
    printf("Frase:\n");
    scanf("%s",Fr);

    printf("Verificar caracter no nivel?\n");
    scanf("%d",&idx);

    Pilha lisp = create();

    for(int i=0; i<QtCar;i++){
        if (Fr[i] == '(')
            push(&lisp, Fr[i]);
        if (Fr[i] == ')'){
            if (isEmpty(lisp)){
                printf ("A lista nao esta balanceada");
                break;
            }
            else
                pop(&lisp);
        }
        if (idx == 1){
            lvl = size(lisp);
            charlvl[1] = Fr[i];
        }
        else
            idx--;
    }
    if (isEmpty(lisp))
        printf ("A lista está balanceada! %s está no lvl %d",charlvl[1],lvl);
    else
        printf ("A lista nao esta balanceada");
}