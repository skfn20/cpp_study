#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<bool> isPrime(4000001, false);
	
	isPrime[2]=isPrime[3]=isPrime[5]=isPrime[7]=isPrime[11]=isPrime[13]=true;
	
	bool canDiv = false;
	for(int i=15; i<4000001; i+=2){
		canDiv=false;
		for(int j=2; j<sqrt(i); i++){
			if(isPrime[j]){
				if(i%j==0){
					canDiv=true;
					break;
				}
			}
		}
		if(!canDiv) isPrime[i]=true; 
	}
	
	for(int i=2; i<4000001; i++){
		if(isPrime[i]) cout << i << endl;
	}
	
	return 0;
}
