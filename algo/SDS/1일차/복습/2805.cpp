#include<iostream>
#include<vector>

using namespace std;

int main()
{
	long long size, key;
	scanf("%lld %lld", &size, &key);
	vector<long long> trees(size);
	
	long long max=0;
	for(int i=0; i<size; i++){
		scanf("%lld", &trees[i]);
		if(max<trees[i]) max=trees[i];	
	}
	
	long long left=0, right=max;
	
	long long ans=-1;
	
	while(left<=right){
		long long mid= (left+right)/2;
		long long total=0;
		for(int i=0; i<size; i++){
			if(mid<trees[i]) total+= trees[i]-mid;
		} 
		
		if(total>=key){
			if(ans < mid) ans =mid;
			left=mid+1;
		}else{
			right=mid-1;
		}
	}
	
	if(ans==-1) printf("0\n");
	else printf("%lld\n", ans);
	
	return 0;	
}
