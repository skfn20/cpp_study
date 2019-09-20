#include<vector>
#include<iostream>
#include<cmath>

using namespace std;

int N, ans= 0x3fffffff;
vector<vector<int> > power;

void DFS(int prev, int k)
{
	static vector<bool> visited(N, false);
	int size = N/2;
	if(k==size){
		vector<int> start;
		vector<int> link;
		
		for(int i=0; i<N; i++){
			if(visited[i]) start.push_back(i);
			else		   link.push_back(i);
		}
		
		int left=0, right=0;
		
		for(int i=0; i<size; i++){
			for(int j=i+1; j<size; j++){
				left += power[start[i]][start[j]] + power[start[j]][start[i]];
				right += power[link[i]][link[j]] + power[link[j]][link[i]];
			}
		}
		ans = min(ans, abs(left-right));
		
		return;
	}
	
	for(int i=prev; i<N; i++){
		if(visited[i]) continue;
		visited[i]= true;
		DFS(i, k+1);
		visited[i] = false;
	}
	
}


int main()
{
	scanf("%d", &N);
	power.resize(N, vector<int>(N, 0));
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) scanf("%d", &power[i][j]);
	
	DFS(0, 0);
	printf("%d\n", ans);
	return 0;
}
