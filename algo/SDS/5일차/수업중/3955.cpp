#include<iostream>
#include<vector>

using namespace std;

long long gcd(long long a, long long b)
{
	return b ? gcd(b, a%b) : a;
}

long long extend_gcd(long long a, long long b)
{
	
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	for(int i=0; i<T; i++){
		long long a, b;
		cin >> a >> b;
		if(gcd(a, b)!=1){
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		
		if(b==1){
			if(a+1>1e9) cout << "IMPOSSIBLE" << endl;
			else cout << a+1 << endl;
			continue;
		}else if(a==1){
			if(b==2) cout << 1 << endl;
			else cout << "IMPOSSIBLE" << endl;
			continue; 
		}
		
		vector<long long> x(10000, 0);
		vector<long long> y(10000, 0);
		vector<long long> ans(10000, 0);
		
		//cout << "---------------------" << endl; cout << endl;
		
		for(int i=0; i<2; i++){
			x[i] = 1- i;
			y[i] = i | 0;
			ans[i] = a*x[i] + b*y[i];
			//cout << x[i] << " " << y[i] << " " << ans[i] << endl;
		}
		
			
		for(int i=2; ;i++){
			long long mod = ans[i-2] / ans[i-1];
			ans[i] = ans[i-2] - mod*ans[i-1];
			x[i] = x[i-2] - mod*x[i-1];
			y[i] = y[i-2] - mod*y[i-1];
			//cout << x[i] << " " << y[i] << " " << ans[i] << endl;
			if(ans[i]==1){
				if(y[i] < 1000000000){
					// 음수인 경우에 양수가 될 때까지 계속 더해준다. 
					// 음수가 되는 부분을 체크 
					// 위에 c==1인 경우에 예외사항 체크 
					while(y[i]<=0) y[i]+= y[i-1]; 
					cout << y[i] << endl;
				}
				else cout << "IMPOSSIBLE" << endl;
				break;
			}	
		}
		
		
	}
	
	return 0;
}
