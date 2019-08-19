#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N, numCase;
	
	long long f[21]={0};
	f[0]=f[1]=1; f[2]=2;
	for(int i=3; i<21; i++) f[i]=f[i-1]*i;
	
	cin >> N >> numCase;
	
	return 0;
}
