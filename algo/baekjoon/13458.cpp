#include<iostream>
#include<vector>

using namespace std;

long long N, p, sub;
vector<long long> par;
long long dp[1000001]= {0, };

int main()
{
	scanf("%lld", &N);
	par.resize(N);
	long long _max=0;
	for(int i=0; i<N; i++) {
		scanf("%lld", &par[i]);
		if(par[i] > _max ) _max = par[i]; 	
	}
	scanf("%lld %lld", &p, &sub);
	
	for(int i=1; i<=p; i++) dp[i] = 1;
	long long prev = dp[1];
	for(int i=p+1; i<=_max; i+=sub){
		for(int j=0; j<sub; j++){
			if(i+j>=1000001) break;
			dp[i+j] = prev +1;
		}
		prev++;
	}
	long long ans =0;
	for(int i=0; i<N; i++){
		ans += dp[par[i]];
	}
	printf("%lld\n", ans);
	return 0;
}
