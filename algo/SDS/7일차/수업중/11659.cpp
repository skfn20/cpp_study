#include<iostream>
#include<vector>

using namespace std;

int serialSum(vector<int> &partial_sum, int a, int b)
{
	if(a==1) return partial_sum[b];
	else return partial_sum[b]-partial_sum[a-1];
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	
	vector<int> nums(N);
	
	for(int i=0; i<N; i++){
		scanf("%d", &nums[i]);
	}
	
	vector<int> partial_sum(N+1, 0);
	partial_sum[1]=nums[0];
	
	for(int i=2; i<=N; i++){
		partial_sum[i]=partial_sum[i-1]+nums[i-1];
	}
	
	int a, b;
	for(int i=0; i<M; i++){
		scanf("%d %d", &a, &b);
		int ans = serialSum(partial_sum, a, b);
		printf("%d\n", ans);
	}

	return 0;
}
