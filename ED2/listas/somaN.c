#include <stdio.h>

int main(){
    int a, j, x = 0;
    scanf("%d", &a);
    for(int i = 0; i<a; i++){
        scanf("%d", &j);
        x += j;
    }

    printf("%d\n", x);

    return 0;
}