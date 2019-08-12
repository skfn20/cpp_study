#include<iostream>
#include<vector>

using namespace std;

long long Fibonaci(int n)
{
	vector<long long> fibo(n+1);
	fibo[0]=0;
	fibo[1]=1;
	if(n<=1){
		return fibo[n];
	}
	else{
		for(int i=2; i<=n; i++){
			fibo[i] = fibo[i-1] + fibo[i-2];
		}
		return fibo[n];
	}
}

int main()
{
	int n;
	cin >> n;
	
	long long ans = Fibonaci(n);
	cout << ans << endl;
}
