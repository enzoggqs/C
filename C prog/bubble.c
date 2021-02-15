#include <stdlib.h>
#include <stdio.h>

void ordenaBubble(int v[], int n){
    int temp, fim = n;
    do{
        temp = 0;
        for(int i = 0; i<fim-1; i++){
            if(v[i] > v[i+1]){
                int aux;
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                temp = i;
            }
        }
        fim--;
    }while(temp != 0);
}

int main(){ 
    
    int a = 10;
    int arr[a];
    for(int j=0; j<a; j++){
        while(scanf("%d", &arr[j]) != EOF);
    }
    ordenaBubble(arr, a); 
    for(int i =0; i < a; i++){
        if(i != a-1)
            printf("%d ", arr[i]);
        else
            printf("%d\n", arr[i]);
    }
    return 0; 
} 