#include<iostream>
#define INF 0x3fffffff
using namespace std;

vector<int> Dijkstra(vector<vector<pair<int, int> > > &adj, int s, int v)
{
	vector<int> dis(V+1, INF);
	
	
}

int main()
{
	int V, E;
	cin >> V >> E;
	
	vector<vector<pair<int, int> > > adj(V+1);
	
	int s;
	cin >> s;
	
	for(int i=0; i<E; i++){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
	} 
	
	
	return 0;
}
