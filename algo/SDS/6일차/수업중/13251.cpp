#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int M, N, K;
	scanf("%d", &M);
	if(M==1){
		scanf("%d %d", &M, &K);
		printf("1.0\n");
		return 0;
	}
	
	vector<int> colors;
	
	int size=0;
	for(int i=0; i<M; i++){
		scanf("%d", &N);
		colors.push_back(N);
		size+=N;
	}
	
	scanf("%d", &K);
	
	double upper_sum =0;
	double p=0;
	vector<int>::iterator i;
	for(i=colors.begin(); i!=colors.end(); i++){
		//printf("%d %d %d\n", size, *i, K);
		if((*i)>=K){
			double upper = 1;
			for(int j=(*i); j>=(*i)-K+1; j--){
				upper *= j;
			}
			upper_sum += upper;
		} 
	}
	double lower=1;
	for(int i=size; i>=size-K+1; i--) lower *=i;
	p = upper_sum / lower;
	
	printf("%.11lf\n", p);
	
	return 0;
}
