#include<iostream>
#define INF 0x3fffffff
using namespace std;

int N, H, M;
bool line[12][31]={false, };
int result[11]={0, };

bool setResult()
{
	for(int i=1; i<=N; i++){
		int t=i;
		for(int j=1; j<=H; j++){
			if(line[t][j]) t++;
			else if(line[t-1][j]) t--;
		}
		result[i]=t;
		if(result[i]!=i) return false;
	}
	return true;
}

int ans = INF;
void dfs(int k, int idx)
{
	if(k>=4)
		return;	
		
	if(setResult()){
		ans = min(ans, k);
		return;	
	}
	
	for(int i=idx; i<=H; i++){
		for(int j=1; j<N; j++){
			if(line[j][i] || line[j-1][i] || line[j+1][i]) continue;
			line[j][i] = true;
			dfs(k+1, i);
			line[j][i]=false;
		}
	}
	
}

int main()
{
	scanf("%d %d %d", &N, &M, &H);
	
	int a, b;
	for(int i=0; i<M; i++){
		scanf("%d %d", &a, &b);
		line[b][a]=true;
	}
	
	if(setResult()){
		printf("0\n");
		return 0;
	}
	
	dfs(0, 1);
	if(ans==INF) printf("-1\n");
	else		printf("%d\n", ans);
	
	return 0;
}
