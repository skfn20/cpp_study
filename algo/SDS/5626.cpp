#include<cstdio>
#include<vector>

using namespace std;

const int MOD = 1000000007;

int main()
{
	int N;
	scanf("%d", &N);
	
	vector<long long> height(N+1, 0);
	long long D[2][5001]={0, };
	
	for(int i=1; i<=N; i++){
		scanf("%lld", &height[i]);
	}
	
	D[0][0]=1;
	
	int ans_idx = 0;
	for(int i=1; i<=N-1; i++){
		int next = i%2;
		int curr = 1-next;
		for(int j=0; j<=5000; j++){
			if(j+1<=5000 && (height[i+1]==-1 || height[i+1]==j+1)){
				D[next][j+1] += D[curr][j];
				D[next][j+1] %= MOD;
			}
			if(height[i+1]==-1 || height[i+1]==j){
				D[next][j] += D[curr][j];
				D[next][j] %= MOD;
			}
			if(j-1>=0 && (height[i+1]==-1 || height[i+1]==j-1)){
				D[next][j-1] += D[curr][j];
				D[next][j-1] %= MOD;
			}
		}
		ans_idx=next;
	}
	
	printf("%lld\n", D[ans_idx][0]);
	
	return 0;
}
