#include <stdio.h>

typedef int item;

#define key(A)(A)



//#define key(A) (A.chave)

#define less(A,B) (key(A) < key(B))

#define lesseq(A,B) (key(A) <= key(B))

#define exch(A,B) {item t=A; A=B; B=t}

#define cmpexch {if(less(B,A) exch(A,B))}

int main(void){

    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d %d", a, b);
    //printf("%d", less(5,1));

    return 0;
}