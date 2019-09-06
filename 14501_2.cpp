#include<iostream>
using namespace std;

int runtime[16], cost[16];
int _max, N;

void dfs(int day, int sum){
	if(day>=N+1){
		if(_max < sum) _max = sum;
		return;
	}
	
	if(day+runtime[day]<=N+1) dfs(day+runtime[day], sum+cost[day]);
	
	dfs(day+1, sum);
}

int main()
{
	scanf("%d", &N);
	for(int i=1; i<=N; i++) scanf("%d %d", &runtime[i], &cost[i]);
	
	dfs(1, 0);
	
	printf("%d\n", _max);
	
	return 0;
}
