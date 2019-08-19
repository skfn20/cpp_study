#include<iostream>

using namespace std;

long long pascal[31][31];

int main()
{
	for(int i=1; i<=30; i++){
		pascal[i][0]=1;
		pascal[i][1]=i;
	}
	
	for(int i=2; i<=30; i++){
		for(int j=2; j<=i; j++){
			pascal[i][j] = (pascal[i-1][j-1] + pascal[i-1][j]);
		}
	}
	
	int T;
	scanf("%d", &T);
	int u, v;
	while(T--){
		scanf("%d %d", &u, &v);
		printf("%lld\n", pascal[v][u]);
	}
	return 0;
}
