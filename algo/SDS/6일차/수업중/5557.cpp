#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	long long nums[101]={0};
	
	for(int i=1; i<=N; i++){
		cin >> nums[i];
	}
	
	long long dp[101][21]={0, };
	
	dp[1][nums[1]]++;
	for(int i=2; i<N; i++){
		for(int j=0; j<=20; j++){
			if(j+nums[i] <=20) dp[i][j+nums[i]] += dp[i-1][j];
			if(j-nums[i] >=0) dp[i][j-nums[i]] += dp[i-1][j];
		}
	}
	
	cout << dp[N-1][nums[N]] << endl;
	
	return 0;
}
