#include<iostream>
#include<vector>

/*
	에라토스~~  
	for(int i=2; i<n; i++){
		for(int j=i*i; j<n; j+=i){
			isPrime[j]=false;
		}
	}

*/

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<int> q;
	
	vector<bool> isPrime(10000001, false);
	
	int less10PrimeList[6]= {2, 3, 5, 7, 11, 13};
	
	for(int i=0; i<6; i++){
		isPrime[less10PrimeList[i]]= true;
	}
	
	for(int i=2; i<10000001; i++){
		if(isPrime[i]){
			
		}
	}
	
	return 0;
}
