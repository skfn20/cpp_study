#include<iostream>
#include<string.h>
#include<queue>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	queue<int> s;
	for(int i=0; i<n; i++){
		string order;
		cin >> order;
		if(order=="push"){
			int a;
			cin >> a;
			s.push(a);
		}else if(order=="front"){
			if(!s.empty())cout << s.front() << endl;
			else cout << -1 << endl;			
		}else if(order=="back"){
			if(!s.empty())cout << s.back() << endl;
			else cout << -1 << endl;			
		}else if(order=="size"){
			cout << s.size() << endl;
		}else if(order=="pop"){
			if(!s.empty()){
					cout << s.front() << endl;
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
