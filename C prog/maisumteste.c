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
    int d, f;

    for(int j=0; j<a; j++){
        if(scanf("%d", &arr[j]) == EOF)
            break;
        f = j;
    }
    int v[f];
    for(int k = 0; k < f; k++){
       v[k] = arr[k];
    }
    /* for(int j=0; scanf("%d", &d) != EOF; j++){
        arr[j] = d;
        f = j;
    } */
    bubble(arr, ); 
    for(int i =0; i < j; i++){
        if(i != j-1)
            printf("%d ", &v[i]);
        else
            printf("%d\n", &v[i]);
    }
    return 0; 
} 