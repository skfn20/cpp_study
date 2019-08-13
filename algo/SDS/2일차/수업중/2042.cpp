#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

typedef long long ll;

ll init(vector<ll>& arr, vector<ll>& tree, int node, int start, int end)
{
	if(start==end) return tree[node]=arr[start];
	
	int mid = (start+end)/2;
	
	return tree[node] = init(arr, tree, node*2, start, mid) +  init(arr, tree, node*2+1, mid+1, end);
}

void update(vector<ll>& tree, int node, int start, int end, int index, ll diff)
{
	if(!(start<=index && index<=end)) return;
	
	tree[node] += diff;
	
	if(start!=end){
		int mid= (start+end)/2;
		update(tree, node*2, start, mid, index, diff);
		update(tree, node*2+1, mid+1, end, index, diff);
	}
}

ll sum(vector<ll>& tree, int node, int start, int end, int left, int right)
{
	// 범위에 포함되지 않는 경우 
	if(left > end || right <start) return 0;
	
	//완전히 포함된 경우 
	if(left<=start && end<=right) return tree[node];
	
	int mid = (start+end)/2;
	
	return sum(tree, node*2, start, mid, left, right) + sum(tree, node*2+1, mid+1, end, left, right);
}

int main()
{
	int n, M, K;
	scanf("%d %d %d", &n, &M, &K);
	
	ll h = (ll)ceil(log2(n)); 
	ll tree_size=(1 << (h+1));
	
	vector<ll> num(n);
	
	vector<ll> tree(tree_size);
	
	for(int i=0; i<n; i++) scanf("%lld", &num[i]);
	init(num, tree, 1, 0, n-1);
	
	
	int num_it = M+K;
	for(int i=0; i<num_it; i++){
		long long a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		if(a==1){
			update(tree, 1, 0, n-1, b-1, c-num[b-1]);
		}else if(a==2){
			printf("%lld\n", sum(tree, 1, 0, n-1, b-1, c-1));
		}
	}
	
	return 0;
}
