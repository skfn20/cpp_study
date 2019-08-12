#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int get3Min(int a, int b, int c)
{
	return min(a, min(b, c));
}

int get3Max(int a, int b, int c)
{
	return max(a, max(b, c));
}

int main()
{
	int size;
	scanf("%d", &size);
	
	vector<vector<int> > ans_max(2, vector<int>(3, 0));
	vector<vector<int> > ans_min(2, vector<int>(3, 0));
	
	vector<int> num(3);
	
	scanf("%d %d %d", &num[0], &num[1], &num[2]);

	ans_max[0][0]= ans_min[0][0]=num[0]; 
	ans_max[0][1]=ans_min[0][1]=num[1]; 
	ans_max[0][2]=ans_min[0][2]=num[2];
	

	
	for(int i=1; i<size; i++){
		scanf("%d %d %d", &num[0], &num[1], &num[2]);
		int curr_idx = i%2;
		int prev_idx = 1-curr_idx;
			
		ans_max[curr_idx][0] = max(ans_max[prev_idx][0], ans_max[prev_idx][1]) + num[0];
		ans_max[curr_idx][1] = get3Max(ans_max[prev_idx][0], ans_max[prev_idx][1], ans_max[prev_idx][2]) + num[1];
		ans_max[curr_idx][2] = max(ans_max[prev_idx][1], ans_max[prev_idx][2])+num[2];
		ans_min[curr_idx][0] = min(ans_min[prev_idx][0], ans_min[prev_idx][1]) + num[0];
		ans_min[curr_idx][1] = get3Min(ans_min[prev_idx][0], ans_min[prev_idx][1], ans_min[prev_idx][2]) + num[1];
		ans_min[curr_idx][2] = min(ans_min[prev_idx][1], ans_min[prev_idx][2])+num[2];
		
	}
	
	int idx= (size-1)%2;
	printf("%d\n%d\n",
			get3Max(ans_max[idx][0], ans_max[idx][1], ans_max[idx][2]),
			get3Min(ans_min[idx][0], ans_min[idx][1], ans_min[idx][2]));
			
	return 0;
}
