#include<iostream>
#include<deque>
#include<vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int size, L;
	cin >> size >> L;
	
	vector<int> num(size);
	
	for(int i=0; i<size; i++) cin >> num[i];
	
	deque<pair<int, int> > dq;
	
	for(int i=0; i<size; i++){
		if(!dq.empty() && dq.front().second <= i-L) dq.pop_front();
		
		while(!dq.empty() && dq.back().first> num[i]){
			dq.pop_back();
		}
		
		dq.push_back(make_pair(num[i], i));
		cout << dq.front().first << " ";
	}
	cout << "\n";	
	return 0;  
}
