#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int N, M;
vector<pair<int, int> > house, chicken, remains;
int ans = 0x3fffffff;
int size_chicken, size_house;
int map[55][18];

int calDis()
{
	int temp_min =0;
	for(int i=0; i<size_house; i++){
		int _min = 0x3fffffff;
		for(int j=0; j<M; j++){
			int dis = abs(house[i].first-remains[j].first)+
					  abs(house[i].second-remains[j].second);
			_min = min(_min, dis);
		}
		temp_min+= _min;
	}
	return temp_min;
}

void dfs(int idx, int k)
{
	if(k==M){
		ans = min(ans, calDis());
		return;
	}
	
	for(int i=idx; i<size_chicken; i++){
		remains.push_back(chicken[i]);
		dfs(idx+1, k+1);
		remains.pop_back(); 
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	int temp;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j]==1) house.push_back({i, j});
			else if(map[i][j]==2) chicken.push_back({i, j});
		}
	}
	size_chicken= chicken.size();
	size_house= house.size();
	dfs(0, 0);
	
	printf("%d\n", ans);
	
	return 0;
}
