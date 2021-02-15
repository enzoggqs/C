#include <stdio.h>

typedef int item;

#define key(A)(A)



//#define key(A) (A.chave)

#define less(A,B) (key(A) < key(B))

#define lesseq(A,B) (key(A) <= key(B))

#define exch(A,B) {item t=A; A=B; B=t;}

#define cmpexch(A,B){if(less(B,A)) exch(A,B);}

void bubblesort(item *v, int l, int r){
    for(int i = l; i<r; i++){
        for(int j=l+1; j<=r; j++){
            cmpexch(v[j-1], v[j]);
        }
    }
}

void selectionsort(item *v, int l, int r){
    for(int i = l; i<r; i++){
        int min = i;
        for(int j=i+1; j<=r; j++){
            if(less(v[j],v[min])){
                min = j;
            }
        }
        exch(v[i], v[min]);
    }
}

void insertionsortslow(item *v, int l, int r){
    for(int i =l+1; i<=r; i++){
        for(int j = i; j>l; j--){
            cmpexch(v[j-1],v[i]]);
        }
    }
}

void insertionsort(item *v, int l, int r){
    for(int i = r; i>l; i--)
        cmpexch(v[i-1], v[i]);
    for(int i=l+2; i<=r; i++){
        int j = i; item tmp = v[j];
        while(less(tmp, v[j-1])){
            v[j] = v[j-1];
            j--
        }
        v[j] = tmp;
    }
}

int main(void){

    /* int a, b;
    scanf("%d %d", &a, &b);
    cmpexch(a,b);
    printf("%d %d\n", a, b); */
    
    //printf("%d\n", less(a,b));

    int arr[9] = {5, 8, 2, 7, 4, 1, 1324, 6, 3};
    /* bubblesort(arr, 0, 9);
    for(int i =0; i < 9; i++){
        printf("%d\n", arr[i]);
    } */

    insertionsortslow(arr, 0, 9);
    for(int i =0; i < 9; i++){
        printf("%d\n", arr[i]);
    }

    return 0;
}