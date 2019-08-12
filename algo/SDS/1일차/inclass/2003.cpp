#include<iostream>
#include<vector>

using namespace std;

int serial_sum(vector<int>& partial_sum, int a, int b)
{
	if(a==0) return partial_sum[b];
	else return partial_sum[b] - partial_sum[a-1];
}

int find_case(vector<int>& num_container, int key)
{
	int count=0;
	int size= num_container.size();
	
	vector<int> partial_sum(size);
	
	partial_sum[0] = num_container[0];
	for(int i=1; i<size; i++){
		partial_sum[i] = partial_sum[i-1] + num_container[i];
	}
	
	for(int i=0; i<size; i++){
		for(int j=i; j<size; j++){
			if(serial_sum(partial_sum, i, j)==key) count++;
		}
	}	
	
	return count;
} 

int main()
{
	int size, key;
	if(scanf("%d %d", &size, &key)==2){
		vector<int> num_container(size);
		
		for(int i=0; i<size; i++) scanf("%d", &num_container[i]);
		
		int ans = find_case(num_container, key);
		printf("%d\n", ans);
	}
	return 0;
}
