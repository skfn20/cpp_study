#include<iostream>
#include<vector>

using namespace std;

int main()
{
	const int INF = 100001;
	
	int size;
	int key;
	
	cin >> size >> key;
	vector<int> num_container(size);
	for(int i=0; i<size; i++) cin >> num_container[i];
	
	int min = INF;
	
	int left=0;
	int right=0;
	
	int sum=0;

	while(right < size){
		sum += num_container[right++];
		while(sum >= key){
			if(right- left < min) {
				min = right-left;
			}
			sum -= num_container[left++];
		}
	}
	
	if(min==INF) printf("0\n");
	else printf("%d\n", min);
	
	return 0;
}

