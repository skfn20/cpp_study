#include<iostream>

using namespace std;

template<typename Type>
Type Find_Pivot(Type *_array, int _first, int _last)
{
	int _middle = (_first + _last-1)/2;

	Type first = _array[_first];
	Type mid = _array[_middle];
	Type last = _array[_last-1];

	return first^mid^last^max(max(first, mid),last)^min((first,mid),last);
}

template<typename Type>
void QuickSort(Type *_array, int _first, int _last)
{
	Type pivot = Find_Pivot<Type>(_array, _first, _last);
	
	int low = _first;
	int high = _last-1;

	while(_array[low] < pivot){low++;}
	while(_array[high] > pivot){high--;}

	while(low<high){
		swap(_array[low], _array[high]);
		low++; high--;
		while(_array[low] < pivot){low++;}
		while(_array[high] > pivot){high--;}
	}

	_array[_last-1] = _array[low];
	_array[low] = pivot;
	QuickSort(_array, _first, low);
	QuickSort(_array, high, _last);
}

int main()
{
	int arr[5] = {13, 2, 1, 12, 7};

	QuickSort(arr, 0, 5);

	for(int i = 0; i < 5; i++){
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}
