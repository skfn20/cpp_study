#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	
	vector<int> stairs(N, 0);
	for(int i=0; i<N; i++){
		scanf("%d", &stairs[i]);
	}
	
	vector<int> dp(N, 0);
	dp[0]=stairs[0];
	dp[1]=stairs[0]+stairs[1];
	dp[2]=max(stairs[0]+stairs[2], stairs[1]+stairs[2]);
	
	for(int i=3; i<N; i++){
		dp[i] = max(dp[i-3]+stairs[i-1]+stairs[i], dp[i-2]+stairs[i]);
	}
	
	printf("%d\n", dp[N-1]);
	
	return 0;
}
