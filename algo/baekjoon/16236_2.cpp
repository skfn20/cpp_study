#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

typedef pair<int, int> Point;
typedef pair<int, Point> Fish;

struct Shark{
	int x, y, time, size, eat_num;
	Shark(){
		this->time=0;
		this->size=2;
		this->eat_num=0;	
	}
	Shark(int x, int y, int time, int size, int eat_num) :
		x(x), y(y), time(time), size(size), eat_num(eat_num){}
};

int N;
int map[20][20];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

inline bool inRange(int x, int y)
{
	return (x<N && x>=0) && (y<N && y>=0);
}

Fish bfs(Shark temp)
{
	vector<Fish > fishes;
	int curX = temp.x;
	int curY = temp.y;
	int curSize = temp.size;
	int curNum = temp.eat_num;
	int curTime = temp.time;
	vector<vector<int> > dis(N, vector<int>(N, 0));
	
	queue<Point> q;
	q.push(make_pair(curX, curY));
	
	while(!q.empty()){
		curX = q.front().first;
		curY = q.front().second;
		q.pop();
		
		for(int idx=0; idx<4; idx++){
			int nextX = curX + dx[idx];
			int nextY = curY + dy[idx];
			
			if(!inRange(nextX, nextY) || map[nextX][nextY] > curSize ||
					dis[nextX][nextY] || (nextX==temp.x && nextY==temp.y)) continue;
			
			dis[nextX][nextY] = dis[curX][curY]+1;
			
			if(map[nextX][nextY] && map[nextX][nextY] < curSize)
				fishes.push_back({dis[nextX][nextY], {nextX, nextY}});	
			
			q.push({nextX, nextY});
		}		
	}
	
	Fish valid;
	valid.first=-1, valid.second.first=-1, valid.second.second=-1;
	if(fishes.empty()) return valid;
	
	sort(fishes.begin(), fishes.end());
	
	return fishes[0];
}

int main()
{
	Shark shark;
	
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j]==9){
				shark.x=i, shark.y=j;
				map[i][j]=0;
			}
		}
	}
	
	while(true){
		Fish food = bfs(shark);
		if(food.first== -1) break;
		
		shark.time += food.first;
		shark.eat_num++;
		if(shark.eat_num>= shark.size){
			shark.size++;
			shark.eat_num=0;
		}
		map[food.second.first][food.second.second]=0;
		shark.x= food.second.first;
		shark.y= food.second.second;
	}
	
	printf("%d\n", shark.time);
	
	return 0;
}
