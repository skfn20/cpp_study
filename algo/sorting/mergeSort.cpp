#include<iostream>

using namespace std;

template<typenmae Type>
void Merge(Type* array, int first, int midpoint, int last)
{


template<typename Type>
void Merge_Sort(Type *_array, int _first, int _last)
{
	int midpoint = (_first+_last)/2;

	Merge_Sort<Type>(_array, _first, midpoint);
	Merge_Sort<Type>(_array, midpoint, _last);
	Merge(_array, _first, midpoint, _last);
}
