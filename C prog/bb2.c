#include <stdlib.h>
#include <stdio.h>

/* typedef struct pos{

}pos; */

int busca_binaria(int v[], int v2[], int n, int x){
    int e = -1;
    int d = n;
    while(e < d-1){
        int m = (e+d)/2;
        if((v[m]) < x)
            e = m;
        else
            d = m;
    }
    if(v[d] == x)
        return v2[d];
    else
        return -1;
}

void insercao(int v[], int v2[], int tam){
    for(int i =1; i<tam; i++){
        int elem = v[i];
        int elem2 = v2[i];
        int j;
        for(j = i-1; j>=0 && v[j] > elem; j--){
            v[j+1] = v[j];
            v2[j+1] = v2[j];
        }
        v[j+1] = elem;
        v2[j+1] = elem2;
    }
}

int parte(int v[], int i, int f){
    int e, d, pivo, aux;
    e = i;
    d = f;
    pivo = v[i];
    while(e < d){
        while (v[e] <= pivo)
            e++;
        while (v[d] > pivo)
            d--;
        if (e < d)        {
            aux = v[e];
            v[e] = v[d];
            v[d] = aux;
        }    
    }
    v[i] = v[d];
    v[d] = pivo;
    return d;
}

void quick(int vet[], int v[], int i, int f){
    int pivo;
    if(f>i){
        pivo = parte(vet, i, f);
        quick(vet, v, i, pivo-1);
        quick(vet, v, pivo+1, f);
    }
}

int main(){
    int tam, nums;
    scanf("%d %d", &tam, &nums);

    int v[tam];
    int vet[nums];
    int v2[tam];

    for(int i = 0; i < tam; i++){
        v2[i] = i;
    }

    for(int i = 0; i < tam; i++){
        scanf("%d", &v[i]);
        //v2[i] = v[i];
    }
    
    for(int j = 0; j < nums; j++){
        scanf("%d", &vet[j]);
    }

    //quick(v, v2, 0, tam-1);

    insercao(v, v2, tam);

    for(int i = 0; i<nums; i++){
        int x = vet[i];
        int y = busca_binaria(v, v2, tam, x);
        printf("%d\n", y);
    }

    return 0;
}