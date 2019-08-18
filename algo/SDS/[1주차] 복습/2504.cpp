#include<iostream>
#include<vector>
#include<stack>
#include<string>

using namespace std;

int main()
{
	string input;
	cin >> input;
	
	int size = input.size();
	
	stack<char> s;
	
	int mul=1;
	int result=0;
	
	bool flag = true;
	
	for(int i=0; i<size && flag; i++){
		switch(input[i]){
			case '[':
				mul *= 3;
				s.push('[');
				if(i<size-1 && input[i+1]==']'){
					s.pop();
					mul= mul/3;
					i++;
					result += mul*3;
				}
				break;
			case ']':
				if(s.empty() || s.top()!='['){
					cout << 0 << endl;
					return 0;
				} 
				s.pop();
				mul = mul/3;
				break;
			case '(':
				s.push('(');
				mul*=2;
				if(i<size-1 && input[i+1]==')'){
					s.pop();
					mul=mul/2;
					i++;
					result += mul*2;
				}
				break;
			case ')':
				if(s.empty()||s.top()!='('){
					cout << 0 << endl;
					return 0;
				} 
				s.pop();
				mul=mul/2;
				break;
		}
	}
	
	if(!s.empty()){
		cout << 0 << endl;
		return 0;
	}
	
	cout << result << endl;
	
	return 0;
}
