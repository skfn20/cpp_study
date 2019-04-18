#include<iostream>
#include<climits>

using namespace std;

void swap(int *x, int * y);

class MinHeap
{
	int *harr;
	int capacity;
	int heap_size;
public:
	MinHeap(int capacity);

	void MinHeapify(int cap);

	int parent(int i){return (i-1)/2;}
	int left(int i){return (2*i+1);}
	int right(int i){return (2*i + 2);}

	int pop();
	void decreaseKey(int i , int new_val);
	int getMin(){return harr[0];}

	void deleteKey(int i);
	void push(int k);
};

MinHeap::MinHeap(int cap)
{
	heap_size = 0;
	capacity = cap;
	harr = new int[cap];
}

void MinHeap::push(int k)
{
	if(heap_size == capacity){
		cout << " Could not insertkey\n";
		return;
	}

	heap_size++;
	int i = heap_size - 1;
	harr[i] = k;

	while(i != 0 && harr[parent(i)] > harr[i])
	{
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}

void MinHeap::decreaseKey(int i, int new_val)
{
	if(i>=0 && i < heap_size){
		harr[i] = new_val;
		while(i != 0 && harr[parent(i)] > harr[i]){
			swap(&harr[i], &harr[parent(i)]);
		}
	}
	else{
		cout << "Array_index is over or less than 0" << endl;
		return;
	}
}

int MinHeap::pop()
{
	if(heap_size <= 0)
		return -1;
	if(heap_size ==1 ){
		heap_size--;
		return harr[0];
	}

	int min = harr[0];
	harr[0] = harr[heap_size -1];
	heap_size--;
	MinHeapify(0);

	return min;
}

void MinHeap::deleteKey(int i)
{
	decreaseKey(i, INT_MIN);
	pop();
}

void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if(l < heap_size && harr[l] < harr[i])
		smallest = l;
	if(r < heap_size && harr[r] < harr[smallest])
		smallest = r;
	if(smallest != i){
		swap(&harr[i], &harr[smallest]);
		MinHeapify(smallest);
	}
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	MinHeap h(11);
	h.push(3);
	h.push(2);
	h.deleteKey(1);
	h.push(15);
	h.push(5);
	h.push(4);
	h.push(45);

	cout << h.pop() << " ";
	cout << h.getMin() << " ";
	h.decreaseKey(2, 1);
	cout << h.getMin();

	return 0;
}
