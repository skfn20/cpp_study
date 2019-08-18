#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int LCA(vector<vector<int> >& parent, vector<int>& depth, int u, int v)
{
	if(depth[u] > depth[v]) swap(u, v);
	
	for(int i=16; i>=0; i--){
		if(depth[v]-depth[u]>= (1<<i)) v=parent[i][v];
	}
	//cout << depth[u] << " " << depth[v] << endl;
	
	if(u==v) return u;
	
	for(int i=16; i>=0; i--){
		if(parent[i][u]!=parent[i][v]){
			u=parent[i][u];
			v=parent[i][v];
		}
	}
	
	return parent[0][u];
}

void DFS(vector<vector<int> > &adj, vector<vector<int> >& parent, vector<int>& depth, int here, int d)
{
	int size = depth.size();
	static vector<bool> visited(size, false);
	
	visited[here]=true;
	depth[here]=d;
	
	for(auto there : adj[here]){
		if(visited[there]) continue;
		parent[0][there]=here;
		DFS(parent, depth, there, d+1);
	}
}

int main()
{
	int N;
	cin >> N;
	
	vector<vector<int> > adj(N+1);
	
	for(int i=0; i<N-1; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);	
	}
	
	vector<pair<int, int> > nodes;
	vector<int> depth(N+1, 0);
	vector<vector<int> > parent(17, vector<int>(N+1));
	for(int i=1; i<=N; i++) parent[0][i]= i;
	
	DFS(adj, parent, depth, 1, 0);
	
	for(int i=1; i<17; i++){
		for(int j=1; j<=N; j++){
			parent[i][j] = parent[i-1][parent[i-1][j]];
		}
	}
	
	int M;
	cin >> M;
	for(int i=0; i<M; i++){
		int u, v;
		cin >> u >> v;
		nodes.push_back(make_pair(u,v));
	}
	
	for(int i=0; i<M; i++){
		int u = nodes[i].first;
		int v = nodes[i].second;
		int ans = LCA(parent, depth, u, v);
		cout << ans << endl;
	}
	
	return 0;
}
