#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int N, key;
	scanf("%d %d", &N, &key);
	
	vector<int> cards(N, 0);
	for(int i=0; i<N; i++) scanf("%d", &cards[i]);
	
	int max=0;
	
	int sum=0;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			for(int k=0; k<N; k++){
				if(i==j || i==k || j==k) continue;
				sum=cards[i]+cards[j]+cards[k];
				if(sum>key) continue;
				if(max < sum) max=sum;	
			}
		}
	}
	
	printf("%d\n", max);
	
	return 0;
}
