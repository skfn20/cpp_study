#include<iostream>
using namespace std;

int dp[16]={0, }, cost[16], take[16], N, _max=0;

int main()
{
	scanf("%d", &N);
	for(int i=1; i<=N; i++) scanf("%d %d", &take[i], &cost[i]), dp[i]=cost[i];

	for(int i=2; i<=N; i++){
		for(int j=1; j<i; j++){
			if(j+take[j] <= i) dp[i] = max(dp[i],dp[j]+cost[i]);
		}
	}

	for(int i=1; i<=N; i++)
		if(i+take[i]<=N+1 && _max < dp[i]) _max=dp[i];
	
	printf("%d\n", _max);
	return 0;
}
