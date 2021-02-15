#include <stdio.h>

int setes(long int n){
    if(n < 7)
        return 0;
    else if((n%10) == 7){
        return(1 + setes(n/10));
    }
    else{
        return(setes(n/10));
    }
}

int main(){
    long int n;
    scanf("%ld", &n);
    printf("%ld\n", setes(n));
    return 0;
}