#include<iostream>

using namespace std;

void BucketSort_counter(int arr[], int n)
{
	int counter[n] = {0};
	int k = 0;
	for(int i = 0; i < n; i++)
		counter[arr[i]]++;
	
	int sum = 0;

	for(int i = 0; i < n; i++){
		sum += counter[i];
		if(counter[i] <= 0) continue;
		for(int j = k; j < sum; j++)
			arr[k++] = i;	
	}
}

int main()
{
	int arr[] = {0, 3, 2, 8, 5, 3, 7, 5, 3, 2, 8, 2, 3, 5, 1, 3, 2, 8,
			5, 3, 4, 9, 2, 3, 5, 1, 0, 9, 3, 5, 2, 3, 5, 4, 2, 1, 1};

	int n = sizeof(arr)/sizeof(arr[0]);

	BucketSort_counter(arr, n);

	for(int i = 0 ; i< n; i++){
		cout<<arr[i] << " ";
	}
	cout << endl;

	return 0;
}
