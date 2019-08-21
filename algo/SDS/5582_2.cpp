#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	
	int size1 = s1.size();
	int size2 = s2.size();
	
	vector<vector<int> > dp(size1, vector<int>(size2, 0));

	int max =0;
	for(int i=0; i<size1; i++){
		if(s2[0]==s1[i]) {
			dp[i][0]=1;
			if(max < dp[i][0]) max=dp[i][0];	
		}
	}
	for(int i=0; i<size2; i++){
		if(s1[0]==s2[i]){
			dp[0][i]=1;	
			if(max < dp[0][i]) max=dp[0][i];	
		}
	}
	
	for(int i=1; i<size1; i++){
		for(int j=1; j<size2; j++){
			if(s1[i]==s2[j]){
				dp[i][j]=dp[i-1][j-1]+1;
				if(max < dp[i][j]) max=dp[i][j];
			}
		}
	}
	
	cout << max << "\n";
	
	return 0;
}
