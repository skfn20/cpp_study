#include<iostream>
#include<algorithm>
#include<bitset>

using namespace std;

int getMax(int arr[], int n)
{
	int max = arr[0];

	for(int i = 1; i < n; i++){
		if(arr[i] > max)
		       max = arr[i];
	}

	return max;
}	

void printArray(int arr[], int n)
{
	for(int i =0 ; i< n; i++)
		cout<< bitset<8>(arr[i]) << " ";

	cout << endl;
}

void RadixSort(int arr[], int n)
{
	int output[n];
	int idx_front;
	int idx_last;
	int exp;
	int max = getMax(arr, n);
	cout << max << endl;
	for(exp=2; max*2 > exp; exp*=2){
		idx_front = 0;
		idx_last = n-1;
		for(int i =0; i <n; i++){
			if(arr[i]%exp < exp/2){
				output[idx_front++] = arr[i];
			}
			else{
				output[idx_last--] = arr[i];
			}
		}
		for(int i = 0; i <idx_front; i++){
			arr[i] = output[i];
		}
		for(int i = 1; i <= n-idx_last-1; i++){
			arr[i+idx_last] = output[n-i];
		}
		printArray(arr, n);
	}
}

int main()
{
	int arr[] = {466, 709, 342, 766, 973, 473, 374, 981, 86, 198};
	int n = sizeof(arr)/sizeof(arr[0]);

	RadixSort(arr, n);

	for(int i = 0; i < n; i++){
		cout<<arr[i] << " ";
	}

	cout << endl;
	
	return 0;
}
