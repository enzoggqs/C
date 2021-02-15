#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct pilha{
    char dado[1000];
    int topo;
}pilha;

void empilha(char c){
/*     if(pilha.topo == ){
        printf("Pilha cheia\n");
    }else{ */
        pilha.topo = pilha.topo + 1;
        pilha.dado[pilha.topo] = c;
    //}
}

void desempilha(){
   /*  if(pilha.topo == -1){
        printf("Pilha cheia!\n");
    }else{ */
        pilha.topo = pilha.topo - 1;
    //}
}

int main(){
    char e[1000];
    int i = 0;
    //pilha.topo = -1;
    scanf("%s", e);
    for(i = 0; i<strlen(e); i++){
        if(e[i] == '(' || e[i] == '[' || e[i] == '{'){
            empilha(e[i]);
            continue;
        }else if(e[i] == ')' || e[i] == ']' || e[i] == '}'){
            if(e[i] == ')'){
                if(pilha.dado[pilha.topo] == '('){
                    desempilha();
                }else{
                    printf("nao\n");
                    break;
                }
            }
            if(e[i] == ']'){
                if(pilha.dado[pilha.topo] == '['){
                    desempilha();
                }else{
                    printf("nao\n");
                    break;
                }       
            }
            if(e[i] == '}'){
                if(pilha.dado[pilha.topo] == '{'){
                    desempilha();
                }else{
                    printf("nao\n");
                    break;
                }       
            }
        }
    }
    if(pilha.topo == -1){
        printf("sim\n");
    }
    return 0;
}