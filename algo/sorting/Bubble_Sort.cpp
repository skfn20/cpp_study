#include<iostream>

using namespace std;

void Bubble_Sort(int *ary, int n)
{
	for(int i = n-1; i >0; i--){
		for(int j = 0; j < i; j++){
			if(ary[j] > ary[j+1])
				swap(ary[j], ary[j+1]);
		}
	}
}

int main()
{
	int ary[10] = {4, 1, 3, 5, 2, 3, 5, 25, 21, 17};

	int n = sizeof(ary)/ sizeof(ary[0]);

	Bubble_Sort(ary, n);

	for(int i = 0; i < n; i++){
		cout << ary[i] << " ";
	}
	cout << endl;

	return 0;
}
