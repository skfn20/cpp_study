#include<iostream>
#include<vector>
#include<queue>

using namespace std;
typedef pair<int, pair<int, int> > Point;
int N, M, ans=0;
vector<vector<int> > map;
vector<vector<bool> > isCleaned;
Point vacuum;

bool allSide(int r, int c)
{
	if((map[r+1][c]==1 || isCleaned[r+1][c]) && (map[r-1][c]==1 || isCleaned[r-1][c]) &&
		(map[r][c+1]==1 || isCleaned[r][c+1]) && (map[r][c-1]==1 || isCleaned[r][c-1])) return true;
	else return false;
}

Point turnLeftMoveForward(int d, int r, int c)
{
	Point dest;
	switch(d){
		case 0:
			dest.first=3, dest.second.first=r, dest.second.second=c-1;
			break;
		case 1:
			dest.first=0, dest.second.first=r-1, dest.second.second=c;
			break;
		case 2:
			dest.first=1, dest.second.first=r, dest.second.second=c+1;
			break;
		case 3:
			dest.first=2, dest.second.first=r+1, dest.second.second=c;
			break;
	}
	return dest;
}

Point moveBackward(int d, int r, int c)
{
	Point dest;
	dest.first=d;
	switch(d){
		case 0:
			dest.second.first=r+1, dest.second.second=c;
			break;
		case 1:
			dest.second.first=r, dest.second.second=c-1;
			break;
		case 2:
			dest.second.first=r-1, dest.second.second=c;
			break;
		case 3:
			dest.second.first=r, dest.second.second=c+1;
			break;
	}
	return dest;
}

int main()
{
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &vacuum.second.first, &vacuum.second.second, &vacuum.first);
	map.resize(N, vector<int>(M, 0));
	isCleaned.resize(N, vector<bool>(M, false));
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++) scanf("%d", &map[i][j]);
	}

	while(true){
		int d= vacuum.first, r=vacuum.second.first, c=vacuum.second.second;
		if(!isCleaned[r][c]){
			isCleaned[r][c]=true;	
			ans++;
		}
		Point backward = moveBackward(d, r, c);
		if(isCleaned[r][c] && allSide(r, c) && map[backward.second.first][backward.second.second]==1) break;
		if(isCleaned[r][c] && allSide(r, c)){
			vacuum = backward;
			continue;	
		}
		Point forward = turnLeftMoveForward(d, r, c);
		int rf=forward.second.first, cf=forward.second.second;
		if(map[rf][cf]==1 || isCleaned[rf][cf]){
			vacuum.first=forward.first;
			continue;
		}
		vacuum = forward;
	}
	
	printf("%d\n", ans);
	return 0;
}
