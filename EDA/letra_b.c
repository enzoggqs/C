#include <stdio.h>

int soma(long int numero){
    if (numero == 0){
        return 0;
    }
    return ((numero % 10) + soma(numero / 10));
}

int main() {
    long int n;
    scanf("%ld", &n);
    long int resultado = soma(n);
    printf("%ld\n", resultado);
    return 0;
}