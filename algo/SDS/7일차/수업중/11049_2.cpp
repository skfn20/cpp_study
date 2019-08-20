#include<cstdio>

using namespace std;

int arr[501][2]={0};
int dp[501][501]={0};
int n;

int main()
{
	scanf("%d", &n);
	
	for(int i=1; i<=n; i++){
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}
	
	for(int i=1; i<n; i++){
		dp[i][i+1]= arr[i][0]*arr[i][1]*arr[i+1][1];
	}
	
	for(int diff=2; diff<n; diff++){
		for(int i=1; i<=n-diff; i++){
			int j=i+diff;
			for(int k=i; k<=j; k++){
				int temp = 	dp[i][k] + dp[k+1][j] + arr[i][0]*arr[k][1]*arr[j][1];
				if(dp[i][j]==0 || dp[i][j]>temp){
					dp[i][j]=temp;
				}
			}		 
		}
	}
	
	printf("%d\n", dp[1][n]);
	
	return 0;
}
