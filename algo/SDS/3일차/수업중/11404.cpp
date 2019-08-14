#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	
	const int INF = 100100;
	vector<vector<int> > cost(N+1, vector<int>(N+1, INF));
	for(int i=1; i<=N; i++) cost[i][i]=0;
	
	for(int i=0; i<M; i++){
		int u, v, w;
		cin >> u >> v >> w;
		cost[u][v] = min(cost[u][v], w);
	}
	
	for(int k=1; k<=N; k++){
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				cost[i][j]=min(cost[i][j], cost[i][k]+cost[k][j]);
			}
		}
	}
	
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if(cost[i][j]>=INF) printf("0 ");
			else printf("%d ", cost[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
