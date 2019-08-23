#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 1000000

using namespace std;

int N, E, t1, t2;
vector<vector<pair<int, int> > > adj;

vector<int> Dijkstra(int s, bool isRoot=true)
{
	vector<int> dis(N+1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	
	dis[s]=0;
	pq.push({0, s});
	
	while(!pq.empty()){
		int currDis=pq.top().first;
		int u=pq.top().second;
		pq.pop();
		if(dis[u]<currDis) continue;
		vector<pair<int, int> >::iterator i;
		for(i=adj[u].begin(); i!=adj[u].end(); i++){
			int v=(*i).first, cost=(*i).second;
			if(dis[v]>currDis+cost){
				dis[v]=currDis+cost;
				pq.push({currDis+cost, v});
			}
		}
	}
	return dis;
}

int main()
{
	scanf("%d %d", &N, &E);
	
	adj.resize(N+1);
	int u, v, c;
	for(int i=0; i<E; i++){
		scanf("%d %d %d", &u, &v, &c);
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}
	scanf("%d %d", &t1, &t2);
	
	vector<int> From_1 = Dijkstra(1);
	vector<int> From_t1= Dijkstra(t1, false);
	vector<int> From_t2= Dijkstra(t2, false);
	
	int min_dis=min(From_1[t1]+From_t1[t2]+From_t2[N], From_1[t2]+From_t2[t1]+From_t1[N]);
	if(min_dis>=INF) printf("-1\n");
	else printf("%d\n", min_dis);
	
	return 0;
}
