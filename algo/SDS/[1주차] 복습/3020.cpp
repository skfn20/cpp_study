#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int binarySearch(vector<int> &arr, int key, bool flag=false)
{
	int count=0;
	int size = arr.size();
	
	int left =0;
	int right= size-1;
	int mid;
	
	while(left<=right){
		mid = (left+right)/2;
		if(arr[mid] > key){
			count += right-mid+1;
			right=mid-1; 
		}else{
			left=mid+1;
		}
	}
	return count;
}

#define INF 0x3fffffff
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	
	int N, H;
	
	vector<int> low;
	vector<int> high;
	
	cin >> N >> H;
	
	for(int i=0; i<N/2; i++){
		int temp_low, temp_high;
		cin >> temp_low;
		cin >> temp_high;
		low.push_back(temp_low);
		high.push_back(temp_high);
	}
	
	sort(low.begin(), low.end());
	sort(high.begin(), high.end());
	
	int min = INF;
	int count=0;
	  
	
	for(int i=0; i<H; i++){
		int num_break= binarySearch(low, i, true) + binarySearch(high, H-i-1);
		if(min > num_break){
			min = num_break;
			count=1;
		}else if(min==num_break) count++;
	}
	
	cout << min << " " << count << endl;
	
	return 0;
}
