#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef vector<pair<int, pair<int, int> > > wfs;

vector<int> parent;
wfs edges;

bool compare(pair<int, pair<int, int> >  a, pair<int, pair<int, int> >  b)
{
	return a.first < b.first;
}

int find(int x)
{
	if(parent[x]==x) return x;
	else return parent[x]=find(parent[x]);
}

void union_set(int x, int y)
{
	x=find(x);
	y=find(y);
	if(x!=y){
		parent[x]=y;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;
	cin >> N >> M;
	
	for(int i=0; i<=N; i++) parent.push_back(i);
	
	for(int i=0; i<M; i++){
		int u, v, w;
		cin >> u >> v >> w;
		
		edges.push_back(make_pair(w, make_pair(u, v)));
	}
	
	sort(edges.begin(), edges.end(), compare);
		
	int count=0;
	int weight=0;
	
	wfs::iterator it;
	for(it=edges.begin(); it!=edges.end(); it++){
		if(count==N-1) break;
		int w = (*it).first;
		int u = (*it).second.first;
		int v = (*it).second.second;
		if(find(u) != find(v)){
			union_set(u, v);
			count++;
			weight += w;
		} 
	}
	
	cout << weight << endl;
	
	
	return 0;
}
