#include<iostream>
#include<vector>
#include<algorithm>
#define INF 0x3fffffff

using namespace std;

vector<pair<int, pair<int, int> > > edges;
vector<int> dis;
vector<int> outDegree;

int main()
{
	int T, N, M, W;
	scanf("%d", &T);
	
	while(T--){
		scanf("%d %d %d", &N, &M, &W);
		edges.clear();
		dis.resize(N+1, INF);
		outDegree.resize(N+1, 0);
		int u, v, c;
		for(int i=0; i<M; i++){
			scanf("%d %d %d", &u, &v, &c);
			edges.push_back({c, {u, v}});
			edges.push_back({c, {v, u}});
			outDegree[u]++; outDegree[v]++;
		}
		for(int i=0; i<W; i++){
			scanf("%d %d %d", &u, &v, &c);
			edges.push_back({-c, {u, v}});
			outDegree[u]++;	
		}
		
		int idx=1;
		for(int i=2; i<=N; i++){
			if(outDegree[idx]<outDegree[i]) idx=i;
		}
		
		dis[idx]=0;
		
		bool update=false;
		for(int i=0; i<N; i++){
			update=false;
			vector<pair<int, pair<int, int> > >::iterator it;
			for(it=edges.begin(); it!=edges.end(); it++){
				int w=(*it).first; int u=(*it).second.first; int v=(*it).second.second;
				if(dis[u]!=INF && dis[v]>dis[u]+w){
					dis[v]=dis[u]+w;
					update=true;
				}
			}	
		}
		
		printf("%d\n", )
		
		if(update) printf("YES\n");
		else	   printf("NO\n");
	}
	
	return 0;
}
