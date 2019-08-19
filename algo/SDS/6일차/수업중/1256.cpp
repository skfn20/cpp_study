#include<iostream>
#include<vector>

using namespace std;

long long pascal[201][101]={0,};
int N, M, K;

void nextChar(int _N, int _M, int _key, int _size)
{
	static int idx=0;
	int size = _N+_M;
	if(idx>_size-1) return;
	
	idx++;
	if(pascal[size-1][_N-1] >= _key){
		printf("a");
		nextChar(_N-1, _M, _key, _size);
	}else{
		printf("z");
		nextChar(_N, _M-1, _key-pascal[size-1][_N-1], _size);
	}
	return;
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);

	int size= N+M;	
	
	pascal[0][0]=1;
	for(int i=1; i<=size; i++){
		pascal[i][0]=1;
		pascal[i][1]=i;
	}
	
	for(int i=2; i<=size; i++){
		for(int j=2; j<=N; j++){
			long long res = pascal[i-1][j-1] + pascal[i-1][j];
			pascal[i][j] = res > 1e9 ? 1e9+1 : res;
		}
	}
	
	if(pascal[size][N] < K){
		printf("-1\n");
		return 0;
	} 
	
	/*
	int _N=N;
	int _M=M;
	int _K=K;
	
	int idx=1;
	while(idx<=size){
		//printf("%d %d\n", _K, pascal[size-idx][_N-1]);
		if(_K <= pascal[size-idx][_N-1]){
			_N--;
			printf("a");
		}else{
			_K -= pascal[size-idx][_N-1];
			printf("z");
		}
		idx++;
	}
	*/
	
	nextChar(N, M, K, size);
	
	printf("\n");
	
	return 0;
}
