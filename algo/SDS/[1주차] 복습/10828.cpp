#include<iostream>
#include<string.h>
#include<stack>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	stack<int> s;
	for(int i=0; i<n; i++){
		string order;
		cin >> order;
		if(order=="push"){
			int a;
			cin >> a;
			s.push(a);
		}else if(order=="top"){
			if(!s.empty())cout << s.top() << endl;
			else cout << -1 << endl;			
		}else if(order=="size"){
			cout << s.size() << endl;
		}else if(order=="pop"){
			if(!s.empty()){
					cout << s.top() << endl;
					s.pop();
				}
			else cout << -1 << endl;
		}else if(order=="empty"){
			if(s.empty()) cout << 1 << endl;
			else cout << 0 << endl;
		}
		
	}
	
	return 0;
}
