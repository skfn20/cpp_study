#include<iostream>
#include<vector>
#include<algorithm>
#define INF 0x3fffffff

using namespace std;

typedef struct{
	int x, y;
}Dir;

Dir d[4]={{0,1}, {-1,0}, {0,-1}, {1,0}};

int N, M;
int result = INF;
int map[8][8], restore[8][8];
vector<pair<int, int> > camera;
vector<int> angle;
bool visited[8][8][4];

inline bool inRange(int x, int y)
{
	return (x>=0 && x<N) && (y>=0 && y<M);
}

void restoreMap()
{
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			restore[i][j]=map[i][j];
}

int countBlind()
{
	int res=0;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			if(restore[i][j]==0) res++;
	return res;
}

void dfs(int k)
{
	int size= camera.size();
	if(k==size){
		for(int i=0; i<size; i++){
			int x = camera[i].first;
			int y = camera[i].second;
			
			for(int idx=0; idx<4; idx++){
				if(visited[x][y][idx]){
					int nextX = x + d[(angle[i]+idx)&3].x;
					int nextY = y + d[(angle[i]+idx)&3].y;
					
					while(true){
						if(!inRange(nextX, nextY) || restore[nextX][nextY]==6) break;
						
						if(restore[nextX][nextY]==0) restore[nextX][nextY]=-1;
						
						nextX+= d[(angle[i]+idx)&3].x;
						nextY+= d[(angle[i]+idx)&3].y;
					}
				}
			}
		}
		
		result = min(result, countBlind());
		restoreMap();
		return;
	}
	
	for(int i=0; i<4; i++){
		angle.push_back(i);
		dfs(k+1);
		angle.pop_back();
	}
}

void Init_visit(int x, int y, int cameraNum)
{
	switch(cameraNum){
		case 1:
			visited[x][y][0]=true;
			break;
		case 2:
			visited[x][y][0]=true;
			visited[x][y][2]=true;
			break;
		case 3:
			visited[x][y][0]=true;
			visited[x][y][1]=true;
			break;
		case 4:
			for(int i=0; i<3; i++) visited[x][y][i]=true;
			break;
		case 5:
			for(int i=0; i<4; i++) visited[x][y][i]=true;
			break;
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			scanf("%d", &map[i][j]);
			
			if(map[i][j]!=0 && map[i][j]!=6) camera.push_back({i, j});
			Init_visit(i, j, map[i][j]);
		}
	}
	restoreMap();
	dfs(0);
	printf("%d\n", result);
	
	return 0;
}
