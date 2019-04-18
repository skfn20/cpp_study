#include<iostream>

using namespace std;

void InsertionSort_withoutSwap(int* ary, int n)
{
	for(int i = 1; i < n; i++){
		int temp = ary[i];
		for(int j = i; j > 0; j--){
			if(ary[j-1] > temp){
				ary[j] = ary[j-1];
			}
			else{
				ary[j] = temp;
				break;
			}
		}
		if(ary[0] > temp)
			ary[0] = temp;
	}
}

int main()
{
	int ary[5] = {4, 2, 1, 5, 3};
	InsertionSort_withoutSwap(ary, 5);

	for(int i = 0 ; i< 5; i++){
		cout << ary[i] << " ";
	}

	cout << endl;

	return 0;
}
