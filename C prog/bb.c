#include <stdlib.h>
#include <stdio.h>

int busca_binaria(int v[], int n, int x){
    int e = -1;
    int d = n;
    while(e < d-1){
        int m = (e+d)/2;
        if((v[m]) < x)
            e = m;
        else
            d = m;
    }

    return d;
}


/* int busca(int v[], int n, int x){
    int i;
    while(i>=0 && v[i] > x){
        i--;
    }
    return i;
} */

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

void quick(int vet[], int i, int f){
    int pivo;
    if(f>i){
        pivo = parte(vet, i, f);
        quick(vet, i, pivo-1);
        quick(vet, pivo+1, f);
    }
}

int main(){
    int tam, nums;
    scanf("%d %d", &tam, &nums);

    int v[tam];
    int vet[nums];
    int v2[tam];

    for(int i = 0; i < tam; i++){
        scanf("%d", &v[i]);
        v2[i] = v[i];
        //setbuf(stdin,NULL);
    }

    printf("\n");
    
    for(int j = 0; j < nums; j++){
        scanf("%d", &vet[j]);
        //setbuf(stdin,NULL);
    }

    quick(v, 0, tam-1);

    for(int i = 0; i<nums; i++){
        int x = vet[i];
        int y = busca_binaria(v, tam, x);
        printf("%d\n", y);
    }

    return 0;
}