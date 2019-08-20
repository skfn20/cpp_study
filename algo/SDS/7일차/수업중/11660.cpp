#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	
	vector<vector<int> > map(N+1, vector<int>(N+1, 0));
	vector<vector<int> > dp(N+1, vector<int>(N+1, 0));
	
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			scanf("%d", &map[i][j]);
		}
	}
	
	dp[1][1]=map[1][1];
	for(int i=2; i<=N; i++){
		dp[1][i] = map[1][i] + dp[1][i-1];
		dp[i][1] = dp[i-1][1] + map[i][1];
	}
	
	for(int i=2; i<=N; i++){
		for(int j=2; j<=N; j++){
			dp[i][j] = dp[i-1][j]+dp[i][j-1]+map[i][j] -dp[i-1][j-1];
		}
	}
	
	int x1, y1, x2, y2;
	for(int i=0; i<M; i++){
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int ans= dp[x2][y2]-dp[x1-1][y2] -dp[x2][y1-1] + dp[x1-1][y1-1];
		printf("%d\n", ans);
	}
	
	
	return 0;
}
