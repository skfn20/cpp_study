#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long binary_search(vector<long long> trees, long long prev_height, long long height)
{
	for(int i=prev_height+1; i<height; i++){
		
	}
}

int main()
{
	int size;
	long long min_size;
	cin >> size >> min_size;
	
	vector<long long> trees(size);
	
	for(int i=0; i<size; i++) cin >> trees[i];
	
	sort(trees.begin(), trees.end());
	
	long long height = trees[0];
	long long cutting_length=0;
	for(int i=0; i<size; i++) cutting_length = cutting_length + trees[i] - height;
	
	if(cutting_length==min_size) {// 잘린 나무들의 높이가 같다면 반환해준다.  
		cout << height << endl;
		return 0;
	} else{
		// heights의 배열 만들기 
		vector<long long> length(size);
		length[0] = height;
		for(int i=1; i<size; i++){
			length[i]= length[i-1] - (size-i)*(trees[i]-trees[i-1]);
		} 
		if(cutting_length > min_size){
			long long prev_height=0;
			for(int i=1; i<size; i++){
				if(length[i]==min_size){
					height=trees[i];
					break;
				}else if(length[i]<min_size){
					prev_height=trees[i-1];
					height=trees[i];
					long long curr_length = length[i];
					
					while(curr_length < min_size){
						curr_length -= 
					}
					
					break;
				}
			}
			cout<<height << endl;
			return 0;
		}
	} 
	//for(int i=0; i<size; i++) cout << trees[i] << " ";
	//cout << endl;
	return 0;
}
