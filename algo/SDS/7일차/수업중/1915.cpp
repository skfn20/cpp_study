#include<cstdio>
#include<vector>

using namespace std;

vector<vector<int> > map;
int n, m;

int main()
{
	scanf("%d %d", &n, &m);
	map.resize(n+1, vector<int>(m+1, 0));
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			scanf("%1d", &map[i][j]);
		}
	}
	
	int temp=0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(!map[i][j]) continue;
			map[i][j]=min(map[i-1][j], min(map[i-1][j-1], map[i][j-1]))+1;
			if(temp < map[i][j]) temp=map[i][j];
		}
	}
	
	printf("%d\n", temp*temp);
		
	return 0;
}
