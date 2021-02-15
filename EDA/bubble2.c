#include <stdio.h>
#include <stdlib.h>

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
    
    int a = 1000;
    int arr[a];
    int f;

    for(int j=0; j<a; j++){
        f = j;
        if(scanf("%d", &arr[j]) == EOF)
            break;
        setbuf(stdin,NULL);
    }
    
    int v[f];
    for(int k = 0; k < f+1; k++){
       v[k] = arr[k];

    }
    bubble(v, f); 
    for(int i = 0; i < f; i++){
        if(i < f-1){
            printf("%d ", v[i]);
        }else{
            printf("%d\n", v[i]);
        }
    }

    return 0; 
} 