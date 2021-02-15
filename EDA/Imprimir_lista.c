#include <stdlib.h>
#include <stdio.h>


typedef struct no {
    int dado;
    struct no *prox;
} no;

no *cria_lista () {
    no *p;
    p = NULL;
    return p;
}

void inserir_inicio (no **p, int x) {
    no *novo = malloc (sizeof (no));
    if (novo == NULL) exit (1);
    novo -> dado = x;
    novo->prox = *p;
    *p = novo;
   
}

int remover_inicio (no **p) {
    no *lixo = *p;
    int dado = lixo->dado;
    *p = lixo->prox;
    free(lixo);
    return dado;
}

void imprimir (no *p) {
    printf("p -> ");
    for (no *ptr = p; ptr != NULL; ptr = ptr->prox)
        printf("%d -> ", ptr->dado);
    printf("NULL\n");
}

void remove_todos_elementos (no *le, int x){
    no *p, *q;
    p = le;
    q = le->prox;
    while (q != NULL){
        if(q->dado == x){
            p = q -> prox;
            free(q);
            q = p -> prox;
        }else{
            p = q;
            q = q->prox;
        }

    }
}

int main () {
    char op;
    int dado;
    no *p = cria_lista();

    printf("\n\nO que deseja fazer? (I)nserir, Im(P)rimir, (R)emover ou (S)air: \n");
    scanf(" %c", &op);
    
    while (op != 'S') {
        
        switch(op) {
            case 'I':
                printf("Digite um elemento: ");
                scanf ("%d", &dado);
                inserir_inicio(&p, dado);
                break;
            
            case 'R':
                printf("Elemento removido : %d\n", remover_inicio(&p));
                break;
                
            case 'P':
                imprimir (p);
                break;
                
            default:
                printf ("Digite uma operacao valida.\n");
        }

        printf("O que deseja fazer? (I)nserir, Im(P)rimir, (R)emover ou (S)air: \n");
        scanf(" %c", &op);
    }
        return 0;
}
