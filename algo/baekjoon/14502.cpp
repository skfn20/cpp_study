#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, M;
vector<vector<int> > map;
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

/*
	백트래킹 방식으로 벽을 놓을 수도 있다.
	void BuildWall(int cnt)
	{
		if(cnt==3){
			virus 퍼트리고 개수 세기
			return;
		}
		
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(temp_map[i][j]==0){
					temp_map[i][j]=1;
					BuildWall(cnt+1);
					temp_map[i][j]==0;
				}
			}
		}
	}


*/

int main()
{
	scanf("%d %d", &N, &M);
	map.resize(N, vector<int>(M));
	
	vector<pair<int, int> > pwall;
	vector<pair<int, int> > virus;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j]==0){
				pwall.push_back({i, j});
			}else if(map[i][j]==2){
				virus.push_back({i, j});
			}
		}
	}
	
	int _max = 0;
	int size=pwall.size();
	for(int i=0; i<size; i++){
		int fx=pwall[i].first, fy=pwall[i].second;
		map[fx][fy]=1;
		for(int j=i+1; j<size; j++){
			map[pwall[j].first][pwall[j].second]=1;
			for(int k=i+2; k<size; k++){
				map[pwall[k].first][pwall[k].second]=1;	
				vector<vector<int> > temp_map=map;
				queue<pair<int, int> > q;
				for(int i=0; i<virus.size(); i++){
					q.push({virus[i].first, virus[i].second});
				}
				int cnt=0;
				
				while(!q.empty()){
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					if(temp_map[x][y]==0){
						temp_map[x][y]=2;
						cnt++;
					}
					for(int idx=0; idx<4; idx++){
						int tempX=x+dx[idx];
						int tempY=y+dy[idx];
						if(tempX<0 || tempX>=N || tempY <0 || tempY >=M ) continue;
						if(temp_map[tempX][tempY]!=0) continue;
						q.push({tempX, tempY});
					}
				}
				if(_max < size-cnt-3) _max = size-cnt-3;
				
				map[pwall[k].first][pwall[k].second]=0;	
			}
			map[pwall[j].first][pwall[j].second]=0;
		}
		map[fx][fy]=0;
	}
	
	printf("%d\n", _max);
	
	return 0;
}
