#include <stdio.h>

void bubble(int vet[], int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(vet[j] > vet[j+1]){
                int aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }
}

int main(){
    int v[1000];
    int n;

    for(int i=0; i<10; i++){
        scanf("%d", &n);
        v[i] = n;
    }

    bubble(v, 1000);

    for(int i = 0; i < f; i++){
        if(i < f-1){
            printf("%d ", v[i]);
        }else{
            printf("%d\n", v[i]);
        }
    }
    
    return 0;
}