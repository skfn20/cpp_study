#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Dust{
	int x, y, amount;
};

int r, c, t;
vector<pair<int, int> > con;
int map[50][50], copyMap[50][50];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int dir[2][4]={{3,0,2,1},{3,1,2,0}};

inline bool inRange(int x, int y)
{
	return (x>=0 && x<r) && (y>=0 && y<c);
}

void Init()
{
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			copyMap[i][j]=map[i][j];
}

void spreadDust()
{
	queue<Dust> q;
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			if(map[i][j]>4) q.push({i, j, map[i][j]});
	
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int spread = q.front().amount/5;
		int cnt=0;
		q.pop();
		for(int idx=0; idx<4; idx++){
			int nx = x+dx[idx];
			int ny = y+dy[idx];
			if(!inRange(nx, ny) || map[nx][ny]==-1) continue;
			cnt+= spread;
			map[nx][ny]+=spread;
		}
		map[x][y]-=cnt;
	}
}

void blowDust(int k)
{
	int x=con[k].first;
	int y=con[k].second+1;
	Init();
	map[x][y]=0;
	
	for(int idx=0; idx<4;idx++){
		while(true){
			int nx=x+dx[dir[k][idx]];
			int ny=y+dy[dir[k][idx]];
			if(!inRange(nx, ny) || map[nx][ny]==-1) break;
			map[nx][ny]=copyMap[x][y];
			x=nx, y=ny;	
		}
	}
}

int solve()
{
	while(t--){
		spreadDust();
		for(int i=0; i<2; i++)
			blowDust(i);
	}
	int ans=0;
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			if(map[i][j]>0) ans+=map[i][j];
			
	return ans;
}


int main()
{
	scanf("%d %d %d", &r, &c, &t);
	
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j]==-1)
				con.push_back({i, j});
		}
	}
	printf("%d\n", solve());
	
	return 0;
}
