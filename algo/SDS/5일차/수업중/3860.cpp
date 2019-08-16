#include<iostream>
#include<vector>
#define INF 0x3fffffff

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int w, h;
	cin >> w >> h;
	
	vector<pair<int, pair<int, int> >  > edges;
	
	int x_dir[4]={-1, 1, 0, 0};
	int y_dir[4]={0, 0, -1, 1};
	
	do{
		edges.clear();
		int map[31][31];
		for(int i=0; i<31; i++)
			for(int j=0; j<31; j++)
				map[i][j]=0;
		
		int num_cave;
		cin >> num_cave;
		for(int i=0; i<num_cave; i++){
			int u, v;
			cin >> u >> v;
			map[u][v]=-1; 
		}
		int num_warp;
		cin >> num_warp;
		for(int i=0; i<num_warp; i++){
			int x1, y1, x2, y2, cost;
			cin >> x1 >> y1 >> x2 >> y2 >> cost;
			edges.push_back(make_pair(cost, make_pair(x1*h+y1, x2*h+y2)));
			map[x1][y1]=2;
		}
		
		map[w-1][h-1]=2;
		
		// 마지막 도착 위치에서 edge를 추가하지 않도록 바꿔보기 
		for(int i=0; i<w; i++){
			for(int j=0; j<h; j++){
				if(map[i][j] ==0){
					for(int idx=0; idx<4; idx++){
						int temp_x = i + x_dir[idx];
						int temp_y = j + y_dir[idx];
						if(!(temp_x>=0 && temp_x<w && temp_y>=0 && temp_y < h)) continue;
						if(map[temp_x][temp_y]!=0) continue;
					
						edges.push_back(make_pair(1, make_pair(i*h+j, temp_x*h + temp_y)));
					}
				}
			}
		}
		
		int size = edges.size();
	
		vector<int> dis(w*h, INF);
		dis[0]=0;
		
		bool updated = false; 
		int V = w*h - num_cave;
		for(int i=0; i<V; i++){
			updated=false;
			for(int j=0; j<size; j++){
				int cost = edges[j].first;
				int u = edges[j].second.first;
				int v = edges[j].second.second;
				if(dis[u]!=INF && dis[v] > dis[u] + cost){
					dis[v] = dis[u] + cost;
					updated=true;
				}
			}
		}
		
		if(updated) cout << "Never" << endl;
		else if(dis[w*h-1]==INF) cout << "Impossible" << endl;
		else cout << dis[w*h-1] << endl;
		
		cin >> w >> h;
		
	}while(w || h);
	
	return 0;
}
