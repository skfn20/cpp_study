#include<iostream>
#include<vector>

using namespace std;

int N;
vector<int> num;

int _max=0xbfffffff;
int _min= 0x3fffffff;

int cal(int a, int b, int k)
{
	switch(k){
		case 0:
			return a+b;
		case 1:
			return a-b;
		case 2:
			return a * b;
		case 3:
			return a / b;
	}
}

void DFS(int k, int sum, vector<int>& op)
{
	if(k>= N){
		if(sum > _max) _max = sum;
		if(sum < _min) _min = sum;
		return;
	}
	
	for(int i=0; i<4; i++){
		if(op[i]==0) continue;
		op[i]--;
		DFS(k+1, cal(sum , num[k], i), op);
		op[i]++;
	}
	
}

int main()
{
	scanf("%d", &N);
	num = vector<int>(N, 0);
	vector<int> op(4, 0);
	for(int i=0; i<N; i++) scanf("%d", &num[i]);
	for(int i=0; i<4; i++) scanf("%d", &op[i]);
	
	DFS(1, num[0], op);
	
	printf("%d\n%d\n", _max, _min);

	return 0;
}
