#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int gcd(int a, int b)
{
	while(b!=0){
		int t= a;
		a= b;
		b= t % b;
	}
	
	return a;
}

/*
int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}
*/

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int a1, b1, a2, b2;
	cin >> a1 >> b1 >> a2 >> b2;
	
	int below = b1 * b2;
	a1 *= b2;
	a2 *= b1;
	
	int upper = a1 + a2;
	
	if(upper > below){
		int mod = gcd(upper, below);
		cout << upper/mod << " " << below / mod << endl;
	}else{
		int mod = gcd(below, upper);
		cout << upper / mod << " " << below / mod << endl;
	}
	/*
	��Һ񱳸� ���� �����൵ �ȴ�.  
	int mod = gcd(uppper, below);
	cout << upper/mod << " " << below/mod << endl;
	*/
	
	return 0;
}
