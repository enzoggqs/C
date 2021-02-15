#include <stdio.h>
#include <stdlib.h>

int potencia(int base, int expoente){
    if(expoente == 0)
        return 1;
     else
        return (base * potencia(base, expoente-1));
}
int main(){
    int b, e;
    float resultado;
    scanf("%d", &b);
    scanf("%d", &e);
    if(b == 0 && e <= 0)
        printf("indefinido\n");
    else{  
        if(e > 0){
            resultado = potencia(b, e);
        }else{
            resultado = potencia (b, abs(e));
            resultado = 1/resultado;
        }
        printf("%f\n", resultado);
    }
    
    return 0;
}