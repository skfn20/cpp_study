#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int, pair<int, int> > > edges;
int V, E;

int find(vector<int>& parent, int x)
{
	if(parent[x]==x) return x;
	else			 return parent[x]=find(parent, parent[x]);
}

void merge(vector<int>& parent, int x, int y)
{
	x = find(parent, x);
	y = find(parent, y);
	if(x!=y) parent[y] = x;
}

int main()
{
	scanf("%d %d", &V, &E);
	int u, v, w;
	for(int i=0; i<E; i++){
		scanf("%d %d %d", &u, &v, &w);
		edges.push_back({w, {u, v}});
	}
	vector<int> parent(V+1, 0);
	for(int i=1; i<=V; i++) parent[i] = i;
	
	sort(edges.begin(), edges.end());
	
	int ans =0;
	int cnt =0;
	for(int i=0; i<E; i++){
		int w = edges[i].first;
		int u = edges[i].second.first;
		int v = edges[i].second.second;
		u = find(parent, u), v = find(parent, v);
		if(u!=v){
			merge(parent, u, v); 
			ans+= w;
			cnt++;
			if(cnt >= V-1) break;
		}
	}
	printf("%d\n", ans);
		
	return 0;
}
