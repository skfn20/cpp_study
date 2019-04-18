#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void countSort(vector<int>&arr)
{
	int max = *max_element(arr.begin(), arr.end());
	int min = *min_element(arr.begin(), arr.end());

	int range = max - min + 1;
	int arr_size = arr.size();

	vector<int> count(range), output(arr_size);

	for(int i = 0; i < arr_size; i++)
		count[arr[i] - min]++;

	for(int i = 1; i < count.size(); i++)
		count[i] += count[i-1];

	for(int i = arr_size-1; i>=0; i--)
	{
		output[count[arr[i] - min]-1]=arr[i];
		count[arr[i]-min]--;
	}

	for(int i = 0; i < arr_size; i++)
		arr[i] = output[i];

}

void printArray(vector<int> &arr)
{
	for(int i = 0; i<arr.size(); i++)
		cout<< arr[i] << " ";

	cout << endl;
}

int main()
{
	vector<int> arr = {-5, -10, 0, -3, 8, 5, -1, 10};

	countSort(arr);
	printArray(arr);

	return 0;
}
