#include<iostream>
#include<vector>
#define INF 0x3fffffff

using namespace std;

struct Edge{
	int x1, y1, x2, y2;
	int weight;
	Edge(int _x1, int _y1, int _x2, int _y2,  int _weight)
	{
		x1=_x1; x2=_x2; y1=_y1; y2=_y2; weight=_weight;
	}
};

int main()
{
	int W, H;
	
	vector<Edge> edges;
	
	int dx[4]={-1, 1, 0, 0};
	int dy[4]={0, 0, -1, 1};
	
	while(true){
		//edge vectorÀ»ºñ¿öÁØ´Ù. 
		edges.clear();
		
		cin >> W >> H;
		if(!(W|H)) break;
		
		int map[30][30]={0, };
		
		// G : ¹¦ºñÀÇ ¼ö
		// T : ±Í½Å±¼ ¼ö 
		int G, T;
		cin >> G;	
		for(int i=0; i<G; i++){
			int x, y;
			cin >> x >> y;
			map[y][x]=-1;
		}
		cin >> T;
		for(int i=0; i<T; i++){
			int x1, y1, x2, y2, weight;
			cin >> x1 >> y1 >> x2 >> y2 >> weight;
			Edge temp(x1, y1, x2, y2, weight);
			edges.push_back(temp);
			map[y1][x1] = 2; 
		}
		
		for(int i=0; i<H; i++){
			for(int j=0; j<W; j++){
				if(map[i][j]!=0) continue;
				if(i==H-1 && j==W-1) continue;
				for(int idx=0; idx<4; idx++){
					int tempX= j + dx[idx];
					int tempY= i + dy[idx];
					if(!(tempX>=0 && tempX<W && tempY>=0 && tempY<H)) continue;
					if(map[tempY][tempX]==-1)continue;
					Edge temp(j, i, tempX, tempY, 1);
					edges.push_back(temp); 
				}
			}
		}
		
		vector<vector<int> > dis(30, vector<int>(30, INF));
		dis[0][0]=0;
		
		int V=W*H -G;
		bool updated=false;
		for(int	j=0; j<V; j++){
			updated=false;
			vector<Edge>::iterator i;
			for(i=edges.begin(); i!=edges.end(); i++){
				int x1= (*i).x1; int y1= (*i).y1;
				int x2= (*i).x2; int y2= (*i).y2;  
				int weight = (*i).weight;
				int new_dis = dis[y1][x1] + weight; 
				if(dis[y1][x1]!=INF && dis[y2][x2] > new_dis){
					dis[y2][x2]=new_dis;
					updated=true;
				}		
			}
		}
		
		if(updated) cout << "Never" << endl;
		else if(dis[H-1][W-1]==INF) cout << "Impossible" << endl;
		else cout << dis[H-1][W-1] << endl;
	}
	return 0;
}
