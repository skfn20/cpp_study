#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<pair<int, int> > edges;
vector<pair<int, int> > nodes;

int LCA(int u, int v, vector<int>& depth, vector<vector<int> >& parent)
{
	if(depth[u] > depth[v]) swap(u, v);
	
	int depth_diff= depth[v]- depth[u];
	
	for(int i=16; i>=0; i--){
		if(depth_diff & (1<<i)) v = parent[i][v];
	}
	
	if(u==v) return u;
	
	while(true){
		if(parent[0][u]==parent[0][v]) return parent[0][u];
		
		for(int i=1; i<17; i++){
			if(parent[i][u]==parent[i][v]){
				u=parent[i-1][u];
				v=parent[i-1][v];
			}
		}
	}
}

int main()
{
	int N, M;
	scanf("%d", &N);
	
	vector<vector<int > > adj(N+1);
	
	for(int i=1; i<N; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		//printf("%d %d\n", u, v);
		edges.push_back(make_pair(u, v));
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vector<bool> visited(N+1, false);
	vector<vector<int> > parent(17, vector<int>(N+1, -1));
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
				q.push(*i);
				//printf("[%d] : %d, [%d] : %d\n", s, depth[s], (*i), depth[*i]);
			}
		}
	}
	
	scanf("%d", &M);
	for(int i=0; i<M; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		nodes.push_back(make_pair(u, v));
	}
	
	for(int i=1; i<17; i++){
		for(int j=1; j<=N; j++){
			parent[i][j]=parent[i-1][parent[i-1][j]];
			//printf("%d ", parent[i][j]);
		}
		//printf("\n");
	}
	
	vector<pair<int, int> >::iterator i;
	
	for(i=nodes.begin(); i!=nodes.end(); i++){
		int u = (*i).first;
		int v = (*i).second;
		
		/*
			1. u와 v의 depth를 확인해서 depth 맞추기
			2. 맞춘 후에 parent가 같은지 확인 
			3. if same -> return
				else => 같이 올려주면서 parent 확인 
		*/
		int ans= LCA(u, v, depth, parent);
		printf("parent : %d\n", ans);
	}
	
	
	
	return 0;
}
