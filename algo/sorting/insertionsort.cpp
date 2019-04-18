#include<iostream>

using namespace std;

void InsertionSort(int* ary, int n)
{
	for(int i =1; i <n; i++){
		for(int j =i; j >0; j--){
			if(ary[j-1] > ary[j]){
				std::swap(ary[j-1], ary[j]);
			}
			else{
				break;
			}
		}
	}
}

int main()
{
	int ary[5] = {3, 1, 4, 2, 5};

	InsertionSort(ary, 5);

	for(int i = 0; i < 5; i++){
		cout << ary[i] << " ";
	}

	cout << endl;

	return 0;
}

