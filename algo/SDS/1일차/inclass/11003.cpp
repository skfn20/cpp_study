#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int size, space;
	cin >> size >> space;
	
	int* num = new int[size];
	for(int i=0; i<size; i++) cin >> num[i];
	
	vector<int> min_num(size);
	min_num[0] = num[0];
	
	for(int i=1; i<space; i++){
		min_num[i]= min(min_num[i-1], num[i]);
	}
	
	for(int i=space; i<size; i++){
		priority_queue<int, vector<int>, greater<int> > que(num+i-space+1, num+i+1);
		min_num[i]= que.top();
	}
	
	for(int i=0; i<size; i++){
		cout << min_num[i] << " ";
	}
	cout << endl;
	
	return 0;
}
