#include <stdio.h>

int main(){
    int tmp;
    int cont = 0;
    while (scanf("%d", &tmp) == 1)
    {
        cont++;
    }
    printf("%d\n", cont);
}