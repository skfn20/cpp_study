#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int size;
	cin >> size;
	
	vector<vector<int> > num(size, vector<int>(size));
	
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			cin >> num[i][j];
		}
	}
	
	vector<vector<int> > max(size, vector<int>(3));
	vector<vector<int> > min(size, vector<int>(3));
	
	max[0][0]=min[0][0]=num[0][0], max[0][1]=min[0][1]=num[0][1], max[0][2]=min[0][2]=num[0][2];
	
	int move_dir[3] = {-1, 1, 0};
	
	for(int i=1; i<size; i++){
		for(int idx=0; idx<3; idx++){
			int temp_idx=move_dir[idx];
			int temp_max = 0;
			int temp_min = 100001;
			if(temp_idx <3 && temp_idx >=0){
				int temp_val_max = max[i-1][idx] + num[i][temp_idx];
				int temp_val_min = min[i-1][idx] + num[i][temp_idx];
				if(temp_max < temp_val_max) temp_max = temp_val_max; 
				if(temp_min > temp_val_min) temp_min = temp_val_min;
			}
			max[i][idx] = temp_max;
			min[i][idx] = temp_min;
		}
	}
	
	int ans_max = max[size-1][0];
	int ans_min = min[size-1][0];
	
	for(int i=1; i<=2; i++){
		if(ans_max < max[size-1][i]) ans_max = max[size-1][i];
		if(ans_min > min[size-1][i]) ans_min = min[size-1][i];
	}
	
	printf("%d\n%d\n", ans_max, ans_min);
	
	return 0;
}
