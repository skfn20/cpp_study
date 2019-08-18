#include<iostream>
#include<vector>
#include<queue>
#define INF 0x3fffffff

using namespace std;

vector<int> Dijkstra(int s, int V, vector<vector<pair<int, int> > >& adj)
{
	vector<int> dis(V+1, INF);
	dis[s]=0;
	
	priority_queue<pair<int, int> > pq;
	
	pq.push(make_pair(0, s));
	//cout << "s : " << s << endl;
	
	while(!pq.empty()){
		int u= pq.top().second;
		int curr_dis = -pq.top().first;
		
		pq.pop();
		
		if(dis[u] < curr_dis) continue;
		//cout << u << " " << curr_dis <<endl;
		
		int size=adj[u].size();
		for(int i=0; i<size; i++){
			int v = adj[u][i].first;
			int w = adj[u][i].second;
			int next_dis = curr_dis + w;
			//cout << u << "->" << v << endl;
			if(dis[v] > next_dis && dis[u]!=INF){
				dis[v]=next_dis;
				pq.push(make_pair(-next_dis, v));
			}
		}
	}
	
	return dis;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;
	cin >> N >> M;
	
	int s;
	cin >> s;
	vector<vector<pair<int, int> > > adj(N+1);
	
	for(int i=0; i<M; i++){
		int u, v,  w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
	}	
	
	vector<int> dis = Dijkstra(s, N, adj);
	
	for(int i=1; i<=N; i++){
		if(dis[i]==INF) cout << "INF" << endl;
		else cout << dis[i]<< endl;
	}
	
	return 0;
}
