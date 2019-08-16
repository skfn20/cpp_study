#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<vector<pair<int, int> > > adj(n+1);
	vector<priority_queue<int> > dis(n+1);
	
	for(int i=0; i<m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
	}
	
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push(make_pair(0, 1));
	dis[1].push(0);
	
	while(!pq.empty()){
		int u = pq.top().second;
		int dis_u = pq.top().first;
		pq.pop();
		
		
		vector<pair<int, int> >::iterator i;
		for(i=adj[u].begin(); i!=adj[u].end(); i++){
			int v = (*i).first;
			int w = (*i).second;
			if(dis[v].size() < k){
				// dis[v].top()이 아닌 현재 갱신되는 거리의 정보를 넣어주어야 한다. 
				dis[v].push(dis_u+w);
				pq.push(make_pair(dis_u+w, v));
			}else{
				if(dis[v].top() > dis_u+w){
					dis[v].pop();
					dis[v].push(dis_u+w);
					pq.push(make_pair(dis_u+w, v));
				}
			}
			/*
			더 간략하게 쓸 수 있다. 
			int new_dist = dis_u+w;
			if(dis[v].size() < k || new_dist < dis[v].top()){
				dist[v].push(new_dist);
				if(dis[v].size() > k) dis[v].pop();
				pq.push(make_pair(new_dist, v);
			}
			*/
		}
	}
	
	for(int i=1; i <=n; i++){
		if(dis[i].size()<k) cout << -1 << endl;
		else cout << dis[i].top() << endl;
	}
	
	return 0;
}
