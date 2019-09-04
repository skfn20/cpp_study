#include<iostream>
#include<vector>
#include<queue>

using namespace std;
typedef pair<int, pair<int, int> > Point;

int N, M, H;
int to[100][100][100]={0, };
int dh[6]={-1, 1, 0, 0, 0, 0};
int dx[6]={0, 0, -1, 1, 0, 0};
int dy[6]={0, 0, 0, 0, -1 ,1};

bool inRange(int h, int x, int y)
{
	if(h<0 || h>=H || x <0 || x>=M || y <0 || y>=N) return false;
	else return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>> N >> M >> H;
	
	bool isAll = true;
	queue<Point> q;
	for(int i=0; i<H; i++){
		for(int j=0; j<M; j++){
			for(int k=0; k<N; k++){
				cin >> to[i][j][k];
				if(to[i][j][k]==0) isAll=false;
				if(to[i][j][k]==1){
					q.push({i, {j, k}});	
				} 
			}
		}
	}
	
	if(isAll){
		cout << "0\n";
		return 0;
	}
	
	int max=0;
	while(!q.empty()){
		int h= q.front().first;
		int x= q.front().second.first;
		int y= q.front().second.second;
		q.pop();
		
		for(int idx=0; idx<6; idx++){
			int tempH= h+dh[idx];
			int tempX= x+dx[idx];
			int tempY= y+dy[idx];
			if(!inRange(tempH, tempX, tempY)) continue;
			if(to[tempH][tempX][tempY]==0){
				to[tempH][tempX][tempY]=to[h][x][y]+1;
				if(max < to[tempH][tempX][tempY]) max=to[tempH][tempX][tempY];
				q.push({tempH, {tempX, tempY}});
			}
		}
	}
	
	isAll=true;
	for(int i=0; i<H; i++){
		for(int j=0; j<M; j++){
			for(int k=0; k<N; k++){
				if(to[i][j][k]==0) isAll=false;
			}
		}
	}
	if(max==0 || !isAll) cout << "-1\n";
	else cout << max-1 << "\n";
	
	return 0;
}
