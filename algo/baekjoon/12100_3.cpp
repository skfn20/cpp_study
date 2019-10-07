#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, mat[20][20];
int ans=0;

void solve(int k)
{
	if(k==5){
		int ret=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++) ret=max(ret, mat[i][j]);
		}
		ans = max(ans, ret);
		return;
	}
	
	for(int idx=0; idx<4; idx++){
		int restore[20][20];
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++) restore[i][j]=mat[i][j];
		}
		
		for(int i=0; i<n; i++){
			vector<int> nonZeros;
			for(int j=0; j<n; j++){
				int temp = idx<2 ? mat[i][j] : mat[j][i];
				if(temp!=0) nonZeros.push_back(temp);
			}
			if(idx==1 || idx==3) reverse(nonZeros.begin(), nonZeros.end());
			
			int size=nonZeros.size();
			vector<int> aftermoving;
			for(int j=0; j<size; j++){
				if(j+1<size && nonZeros[j]==nonZeros[j+1]) {
					aftermoving.push_back(nonZeros[j++]<<1);	
				}
				else aftermoving.push_back(nonZeros[j]);
			}
			for(int j=aftermoving.size(); j<n; j++) aftermoving.push_back(0);
			if(idx==1 || idx==3) reverse(aftermoving.begin(), aftermoving.end());
			
			for(int j=0; j<n; j++) (idx<2 ? mat[i][j] : mat[j][i])=aftermoving[j];	
		}
		solve(k+1);

		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++) mat[i][j]=restore[i][j];
		}
	}
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++) 
		for(int j=0; j<n; j++) scanf("%d", &mat[i][j]);
				
	solve(0);
	printf("%d\n", ans);
	
	return 0;
}
