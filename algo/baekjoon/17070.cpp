#include<iostream>
#include<vector>

using namespace std;

int dp[17][17][3]={0, };
int map[17][17]={0, };
int N;

int main()
{
	scanf("%d", &N);
	
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			scanf("%d", &map[i][j]);
		}
	} 
	dp[1][2][0]=1;
	
	for(int i=1; i<=N; i++){
		for(int j=2; j<=N; j++){
			if(dp[i][j][0] !=0 ){
				if(map[i][j+1]==0 && j+1<=N) dp[i][j+1][0]+=dp[i][j][0];
				if(map[i+1][j]==0 && map[i][j+1]==0 && map[i+1][j+1]==0 &&
					j+1 <=N && i+1<=N) dp[i+1][j+1][2] += dp[i][j][0];
			}
			if(dp[i][j][1]!=0){
				if(map[i+1][j]==0 && i+1<=N) dp[i+1][j][1] += dp[i][j][1];
				if(map[i+1][j]==0 && map[i][j+1]==0 && map[i+1][j+1]==0 &&
					j+1 <=N && i+1<=N ) dp[i+1][j+1][2] += dp[i][j][1];
			}
			if(dp[i][j][2]!=0){
				if(map[i+1][j]==0 && i+1 <=N) dp[i+1][j][1] += dp[i][j][2];
				if(map[i][j+1]==0 && j+1 <=N) dp[i][j+1][0] += dp[i][j][2];
				if(map[i+1][j]==0 && map[i][j+1]==0 && map[i+1][j+1]==0 &&
					j+1 <=N && i+1<=N ) dp[i+1][j+1][2] += dp[i][j][2];
			}
		}
	}
	
	int ans=0;
	for(int i=0; i<3; i++) ans += dp[N][N][i]; 
	printf("%d\n", ans);
	
	return 0;
}
