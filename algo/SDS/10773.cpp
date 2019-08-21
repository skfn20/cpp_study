#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	
	vector<long long> arr;
	long long temp;
	for(int i=0; i<N; i++){
		scanf("%lld", &temp);
		if(temp==0 && arr.size()!=0) arr.pop_back();
		else arr.push_back(temp);
	}
	
	long long sum=0;
	for(int i=0; i<arr.size(); i++){
		sum+=arr[i];
	}
	
	printf("%lld\n", sum);
	
	return 0;
}
