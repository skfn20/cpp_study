#include<iostream>
#include<vector>

using namespace std;

int N, M;

void DFS(int cnt)
{
	static vector<int> s;
	static vector<bool> visited(N+1, false);
	if(cnt==M){
		for(int i=0; i<s.size(); i++){
			printf("%d ", s[i]);
		}
		printf("\n");
	}
	
	for(int i=1; i<=N; i++){
		if(!visited[i]){
			visited[i]=true;
			s.push_back(i);
			DFS(cnt+1);
			visited[i]=false;
			s.pop_back();
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	
	DFS(0);
	
	
	return 0;
}
