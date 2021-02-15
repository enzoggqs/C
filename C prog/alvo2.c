#include <stdio.h>

int bbin(int v[], int n, long long int x){
	int ini=1;
	int fim=n;
	if(x>v[n])	return 0;
	
	while(ini<fim)
	{
		int meio=(ini+fim)/2;
		
		if(v[meio]>=x){
			fim=meio;
		}else{
			ini=meio+1;
		}
	}
	return n+1-fim;
}
int main(){
    int n,m;
    int r[100010];
    long long int resp=0;

    scanf("%d %d",&n, &m);

	for(int i=1;i<=n;i++){
		scanf("%lld",&r[i]);
		r[i]=r[i]*r[i];
	}

	for(int i=1;i<=m;i++){	
		long long int x,y;
		scanf("%lld %lld",&x,&y);
		resp+=bbin(r, n, (x*x+y*y));
	}

	printf("%lld\n",resp);

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