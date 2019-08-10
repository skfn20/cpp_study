#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void push_heap(vector<int>& heap, int newValue)
{
	heap.push_back(newValue);
	
	int idx= heap.size()-1;
	
	while(idx>0 && heap[(idx-1)/2] < heap[idx]){
		swap(heap[idx], heap[(idx-1)/2]);
		idx= (idx-1)/2;
	}
}

void pop_heap(vector<int> heap)
{
	heap[0] = heap.back();
	heap.pop_back();
	
	int here =0;
	while(true){
		int left=here*2+1, right=here*2+2;
		if(left>=heap.size()) break;
		int next=here;
		if(heap[next]<heap[left]) next=left;
		
		if(right<heap.size() && heap[next] < heap[right]) next = right;
		
		if(next==here) break;
		swap(heap[here], heap[next]);
		here=next;
	}
}

int* makeInput(int size, int a, int b)
{
	int* input = new int[size];
	
	input[0]=1983;
	for(int i=1; i<size; i++){
		input[i]=(input[i-1]*a+b) % 20090711;
	}
	
	return input;
}

struct RNG{
	int seed, a, b;
	RNG(int _a, int _b) : a(_a), b(_b), seed(1983){}
	int next(){
		int ret=seed;
		seed=((seed * (long long)a)+b) % 20090711;
		return ret;
	}
};

int runningMedian(int n, RNG rng)
{
	priority_queue<int, vector<int>, less<int> > maxHeap;
	priority_queue<int, vector<int>, greater<int> > minHeap;
	int ret=0;
	
	for(int cnt=1; cnt<=n; cnt++){
		if(maxHeap.size()==minHeap.size()) maxHeap.push(rng.next());
		else{
			minHeap.push(rng.next());
			if(!minHeap.empty() && !maxHeap.empty() &&
				minHeap.top() < maxHeap.top()){
				int a = maxHeap.top(), b = minHeap.top();
				maxHeap.pop(); minHeap.pop();
				maxHeap.push(a);
				minHeap.push(b);		
			}
		}
		ret = (ret + maxHeap.top()) % 20090711;
	}
	return ret;
}

int main()
{
	int numTest;
	cin >> numTest;
	
	for(int T=0; T<numTest; T++){
		int size, a, b;
		cin >> size >> a>> b;
		RNG rng(a, b);
		int ans = runningMedian(size, rng);
		
		cout << ans << endl;
	}
	return 0;
}
