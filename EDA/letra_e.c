#include <stdio.h>

int somaDig(int n){
    if(n == 0)
    return 0;
    else{
        return somaDig (n/10) + n%10;
    }
}
int grau9(int n){
    if(n == 9)
    return 1;
    else{
        return grau9(somaDig(n)) + 1;
    }
}

int main(){
    char strN[1001];
    int n;

    scanf("%s", strN);
    while (strN[0] != '0' || strN[1] != '\0'){
        n = 0;
        for( int i = 0; strN[i] != '\0'; i++)
            n += strN[i] - '0';
        
        if(n % 9 == 0){
            printf("%s is a multiple of 9 and has 9-degree %d.\n", strN, grau9(n));
        }else{
            printf("%s is not a multiple of 9.\n", strN);
        } 

        scanf("%s", strN);
        
    }
}