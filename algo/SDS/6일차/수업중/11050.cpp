#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	
	int upper=1, lower=1;
	
	for(int i=0; i<K; i++){
		upper*=(N-i);
		lower*=(i+1);
	}
	
	int ans= upper/lower;
	
	printf("%d\n", ans);
	 
	return 0;
}
