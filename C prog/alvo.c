#include <stdio.h>
#include <stdlib.h>

int busca(long int vet[], int n, long int x){
	int i=1;
	int f=n;
	if(x>vet[n])	
        return 0;
	
	while(i<f){
		int m=(i+f)/2;
		
		if(vet[m]>=x)
			f=m;
		else
			i=m+1;
	}
	return n+1-f;
}

int main(){
    int circ,tiros;
    long int r[100010];
    long int pontos = 0;

    scanf("%d %d", &circ, &tiros);

    for(int i=1; i<=circ; i++){
		scanf("%ld",&r[i]);
		r[i]=r[i]*r[i];
	}

    for(int i=1; i<=tiros; i++){	
		long int x,y;
		scanf("%ld %ld",&x,&y);
		pontos+=busca(r, circ, x*x+y*y);
	}

    printf("%ld\n", pontos);

    return 0;
}

/* 3 10
1
2
5
0 0
-2 0
0 -2
3 -4
-4 -3
3 1
6 2
-1 2
-5 -2
1 -1 */

/* 3 6
1
2
5
1 0
0 3
-5 0
0 0
-3 -3
1 1 */