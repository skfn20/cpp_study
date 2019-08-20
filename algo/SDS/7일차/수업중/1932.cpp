#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	
	int nums[501][501]={0, };
	int dp[501][501]={0, };
	
	for(int i=0; i<n; i++){
		for(int j=0; j<i+1; j++){
			scanf("%d", &nums[i][j]);		
		}
	}
	
	dp[0][0]=nums[0][0];
	
	for(int i=1; i<n; i++){
		for(int j=0; j<=i; j++){
			if(j==0) dp[i][j]=dp[i-1][j] + nums[i][j];
			else if(j==i) dp[i][j] = dp[i-1][j-1] + nums[i][j];
			else dp[i][j]=max(dp[i-1][j-1]+nums[i][j], dp[i-1][j]+nums[i][j]);
		}
	}
	
	int max=dp[n-1][0];
	for(int i=1; i<n; i++){
		if(max < dp[n-1][i]) max=dp[n-1][i];
	}
	
	printf("%d\n", max);
	
	return 0;
}
