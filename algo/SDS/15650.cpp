#include<iostream>
#include<vector>

using namespace std;

int N, M;

void DFS(int start, int cnt)
{
	static vector<int> v;
	static vector<bool> visited(N+1, false);
	
	if(cnt==M){
		int size=v.size();
		for(int i=0; i<size; i++){
			printf("%d ", v[i]);
		}
		printf("\n");
		return;
	}
	
	for(int i=start; i<N; i++){
		if(visited[i]) continue;
		visited[i]=true;
		v.push_back(i+1);
		DFS(i, cnt+1);
		v.pop_back();
		visited[i]=false;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	
	DFS(0, 0);
	
	return 0;
}
