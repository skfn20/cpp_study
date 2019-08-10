#include<iostream>

using namespace std;

int largestMod(int* moneys, int remains, int size)
{
	for(int i=0; i<size-1; i++){
		if(moneys[i+1]>remains) return moneys[i];
	}
	return moneys[size-1];
}

int main()
{
	int n, remains;
	cin >> n >> remains;
	
	int* moneys = new int[n];
	for(int i=0; i<n; i++){
		cin >> moneys[i];
	}
	
	int ans =0;
	
	while(remains){
		int largest_change = largestMod(moneys, remains, n);
		ans += remains / largest_change;
		remains = remains % largest_change;
	}
	
	cout << ans << endl;
	
	delete[] moneys;
	moneys = nullptr;
	return 0;
}
