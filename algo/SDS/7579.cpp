#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int d[10000]={0,};

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	
	vector<int> mem(N+1, 0);
	vector<int> cost(N+1, 0);
	int sum=0;
	
	for(int i=1; i<=N; i++) scanf("%d", &mem[i]);
	for(int i=1; i<=N; i++){
		scanf("%d", &cost[i]);
		sum+=cost[i];	
	}
	
	for(int i=1; i<=N; i++){
		for(int j=sum; j>=cost[i]; j--){
			d[j]=max(d[j], d[j-cost[i]]+mem[i]);
		}
	}
	
	int i;
	for(i=0; i<=sum; i++)
		if(d[i]>=M) break;
		
	printf("%d\n", i);
	

	return 0;
}
