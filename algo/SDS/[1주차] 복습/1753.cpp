#include<iostream>
#include<vector>
#include<queue>
#define INF 0x3fffffff

using namespace std;

vector<int> Dijkstra(vector<vector<pair<int, int> > >  &adj, int s, int V)
{
	vector<int> dis(V+1, INF);
	
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	dis[s]=0;
	pq.push(make_pair(0, s));
	
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		vector<pair<int, int> >::iterator i;
		for(i=adj[u].begin(); i!=adj[u].end(); i++){
			int v = (*i).first;
			int w = (*i).second;
			if(dis[u]!=INF && dis[v] > dis[u]+w) dis[v]=dis[u]+w;
			pq.push(make_pair(dis[v], 0));
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
	
	
	vector<vector<pair<int, int> > >  adj(V+1);
	
	for(int i=0; i<E; i++){
		int u, v, w;
		cin>> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
	}
	
	vector<int> dis = Dijkstra(adj, s, V);
	
	for(int i=1; i<=V; i++){
		if(dis[i]==INF) cout << "INF" << endl;
		else cout << dis[i] << endl;
	}
	
	return 0;
}
