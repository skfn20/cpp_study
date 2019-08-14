#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<int> path;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
		
	int N, M;
	cin >> N >> M;
	
	vector<vector<int> > adj(N+1);
	vector<bool> visited(N+1, false);
	vector<int> indegree(N+1, 0);
	
	for(int i=0; i<M; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		indegree[v]++;
	}
	
	queue<int> q;
	
	for(int i=1; i<=N; i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}
	
	while(!q.empty()){
		int s=q.front();
		visited[s]=true;
		q.pop();
		path.push_back(s);
		
		vector<int>::iterator i;
		for(i=adj[s].begin(); i!=adj[s].end(); i++){
			if(!visited[*i]){
				if(--indegree[*i]==0){
					q.push(*i);
				}
			}
		}
	}
	
	int path_size= path.size();
	for(int i=0; i<path_size; i++){
		cout << path[i] << " ";
	}
	cout << endl;
	
	return 0;
}
