#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<pair<int, int> > edges;
vector<pair<int, int> > nodes;
vector<vector<int > > adj;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;
	cin >> N;
	
	for(int i=1; i<N; i++){
		int u, v;
		cin >> u >> v;
		edges.push_back(make_pair(u, v));
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vector<bool> visited(N+1, false);
	vector<vector<int> > parent(15, vector<int>(N+1, -1));
	vector<int> depth(N+1, 0);
	
	queue<int> q;
	parent[0][1]=1;
	depth[1]=0;
	
	q.push(1);
	
	while(!q.empty()){
		int s = q.front();
		q.pop();
		visited[s]=true;
		
		vector<int>::iterator i;
		for(i=adj[s].begin(); i!=adj[s].end(); i++){
			if(!visited[*i]){
				parent[0][*i]=s;
				depth[*i] = depth[s] + 1;
			}
		}
	}
	
	for(int i=1; i<=N; i++){
		cout << "previous : " << parent[0][i] << "depth : " << depth[i] << endl;
	}
	
	for(int i=1; i<15; i++){
		for(int j=1; j<=N; j++){
			parent[i][j]=parent[i-1][parent[i-1][j]];
		}
	}
	
	cin >> M;
	for(int i=0; i<M; i++){
		int u, v;
		cin >> u >> v;
		nodes.push_back(make_pair(u, v));
	}
	
	
	return 0;
}
