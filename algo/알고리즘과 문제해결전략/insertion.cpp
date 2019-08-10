#include<iostream>
#include<queue>

using namespace std;

int* findOriginForm(int* numbers, int size)
{
	int* ans = new int[size];
	queue<int> q;
	
	
	for(int i=size; i>=1; i--) {
		q.push(i);	
	} 
	
	for(int i=0; i<size; i++){
		int moveLeft = numbers[size-1-i];
		
		while(moveLeft){
			int temp = q.front();
			q.pop();
			q.push(temp);
			moveLeft--;
		}
		ans[size-1-i] = q.front();
		
		q.pop();
		
		while(q.front()!=size && !q.empty()){
			int temp = q.front();
			q.pop();
			q.push(temp);
		}
	}
	
	return ans;
}

int main()
{
	int numTest;
	cin >> numTest;
	
	for(int T=1; T<=numTest; T++){
		int n;
		cin >> n;
		
		int* numbers = new int[n];
		
		for(int i=0; i<n; i++){
			cin >> numbers[i];	
		}
		
		int* ans = findOriginForm(numbers, n);
		
		for(int i=0; i<n; i++){
			cout << ans[i] << " ";
		}
		cout << endl;
	
	}
}
