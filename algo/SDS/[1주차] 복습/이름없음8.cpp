#include<iostream>
#include<vector>
#define INF 0x3fffffff

using namespace std;

struct Edge{
	int x1, x2, y1, y2, weight;
	Edge(int _x1, int _x2, int _y1, int _y2, int _weight)
	{
		x1=_x1, x2=_x2, y1=_y1, y2=_y2, weight=_weight;		
	}
};

int main()
{
	int W, H;
	
	vector<Edge> edges;
	
	while(true){
		edges.clear();
		cin >> W >> H;
		if(!(W||H)) break;
		int G, T;
		cin >> G;
		int map[30][30];
		for(int i=0; i<G; i++){
			int x, y;
			cin >> x >> y;
			map[y][x]=-1;
		}
		cin >> T;
		for(int i=0; i<T; i++){
			int x1, y1, x2, y2, weight;
			cin >> x1 >> y1 >> x2 >> y2 >> weight;
			map[y1][x1]=2;
			Edge temp(x1, x2, y1, y2, weight);
			edges.push_back(temp);
		}
		
		map[H-1][W-1]=2;
		
		vector<vector<int> > dis(30, vector<int>(30, INF));
		
		bool updated=false;
		int size = edges.size();
		int V=W*H - G;
		
		dis[0][0]=0;
		for(int i=0; i<V; i++){
			updated=false;
			for(int j=0; j<size; j++){
				int x1 = edges[j].x1; int x2=edges[j].x2;
				int y1 = edges[j].y1; int y2=edges[j].y2;
				int weight=edges[j].weight;
				if(dis[y1][x1]!=INF && dis[y2][x2]>dis[y1][x1]+weight){
					dis[y2][x2]=dis[y1][x1] + weight;
					updated=true;
				}
			}
		}	
	}
	
	
	return 0;
}
