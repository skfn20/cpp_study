#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

const int INF = 1000001;

vector<int> dijkstra(int s, int V, vector<vector<pair<int, int> > >& adj)
{
	vector<int> dis(V+1, INF);
	
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	dis[s]=0;
	pq.push(make_pair(0, s));
	
	while(!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		//printf("run %d\n", u);
		vector<pair<int, int> >::iterator i;
		for(i=adj[u].begin(); i!=adj[u].end(); i++){
			int v=(*i).first;
			//printf("in loop %d\n", v);
			int w=(*i).second;
			if(dis[v] > dis[u]+w) dis[v]=dis[u]+w;
			pq.push(make_pair(dis[v], v)); 
		}
	}
	
	return dis;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int V, E;
	cin >> V >> E;
	
	int s;
	cin >> s;
	
	vector<vector<pair<int, int> > > adj(V+1);
	
	for(int i=0; i<E; i++){
		int u, v, w;
		cin >> u >> v >> w;
		//printf("u, v: %d %d\n", u, v);
		adj[u].push_back(make_pair(v, w));
	}
	
	vector<int> dis = dijkstra(s, V, adj);
	
	for(int i=1; i<=V; i++){
		if(i==s) printf("0\n");
		else if(dis[i]>=INF) printf("INF\n");
		else printf("%d\n", dis[i]);
	}
	
	return 0;
}
