#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Node{
	int x, y, w;
	Node(int _x, int _y, int _w){x=_x; y=_y; w=_w;}
};

char map[1000][1000]={'0', };
int dis[1000][1000][2]={0, };
int dx[4]={-1, 1, 0, 0};
int dy[4]={0,0,-1,1};
int N, M;

inline bool inRange(int h, int w, int x, int y)
{
	if(x<h && x>=0 && y<w && y>=0) return true;
	else return false;
}

int BFS()
{
	queue<Node> q;
	q.push({0, 0, 0});
	
	while(!q.empty()){
		int x= q.front().x, y=q.front().y, w=q.front().w;
		q.pop();
		if(x==N-1 && y==M-1) return dis[x][y][w];
		
		for(int idx=0; idx<4; idx++){
			int currX = x+ dx[idx];
			int currY = y+ dy[idx];
			if(!inRange(N, M, currX, currY)) continue;
			if(dis[currX][currY][w]) continue;
			
			if(map[currX][currY]=='0'){
				dis[currX][currY][w]=dis[x][y][w]+1;
				q.push({currX, currY, w});
			}else if(map[currX][currY]=='1' && w==0){
				dis[currX][currY][1]=dis[x][y][w]+1;
				q.push({currX, currY, 1});
			}
		}
	}
	
	return -1;
}

int main()
{
	scanf("%d %d", &N, &M);
	
	for(int i=0; i<N; i++){
		scanf("%s", map[i]);
	}
	
	dis[0][0][0]=1;
		
	printf("%d\n", BFS());
	 
	return 0;
}
