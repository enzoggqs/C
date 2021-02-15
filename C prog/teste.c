#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct pilha{
    char dado[1000];
    int topo;
}s;

void empilha(char c){
    if (s.topo == (999))
        printf ("Pilha cheia\n");
    else{
        s.topo = s.topo + 1;
        s.dado[s.topo] = c;
    }
}

void desempilha(){
    if (s.topo == - 1){
        printf ("Pilha  vazia\n");
    }else{
        s.topo = s.topo - 1;
    }
}

int main(){
    char exp[1000];
    int i = 0;
    s.topo = -1;
    printf("\nINPUT THE EXPRESSION : ");
    scanf("%s", exp);
    for(i = 0;i < strlen(exp);i++){
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{'){
            empilha(exp[i]);
            continue;
        }else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}'){
            if(exp[i] == ')'){
                if(s.dado[s.topo] == '('){
                    desempilha();
                }else{
                    printf("nao\n");
                    break;
                }
            }
            if(exp[i] == ']'){
                if(s.dado[s.topo] == '['){
                    desempilha();
                }else{
                    printf("\nUNBALANCED EXPRESSION\n");
                    break;
                }
            }
            if(exp[i] == '}'){
                if(s.dado[s.topo] == '{'){
                    desempilha();
                }else{
                    printf("\nUNBALANCED EXPRESSION\n");
                    break;
                }
            }
        }
    }
    if(s.topo == -1){
        printf("\nBALANCED EXPRESSION\n");
    }
}