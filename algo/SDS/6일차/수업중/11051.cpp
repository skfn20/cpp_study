#include<iostream>

using namespace std;

long long pascal[1001][1001];

int main()
{
	const long long mod = 10007;
	long long N, K;
	scanf("%lld %lld", &N, &K);
	
	for(int i=1; i<=N; i++){
		pascal[i][0]=1;
		pascal[i][1]=i;
	}
	
	for(int i=2; i<=N; i++){
		for(int j=2; j<=i; j++){
			pascal[i][j] = (pascal[i-1][j-1] + pascal[i-1][j])%mod;
		}
	}
		
	long long ans= pascal[N][K];
	
	printf("%lld\n", ans);
	 
	return 0;
}
