#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct TreeNode{
	vector<TreeNode*> children;
};

int n, y[100], x[100], radius[100];
int longest;


int sqr(int x);
int sqrdist(int a, int b);
bool encloses(int a, int b);
bool isChild(int parent, int child);
TreeNode* getTree(int root);
int height(TreeNode* root);
int solve(TreeNode* root);

 
int main()
{
	int numTest;
	cin >> numTest;
	
	for(int T=0; T<numTest; T++){
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> x[i] >> y[i] >> radius[i];
		}
		
		TreeNode* root = getTree(0);
		
		int ans = solve(root);
		
		cout << ans << endl;
	}
	
	
	return 0;
}


int sqr(int x){
	return x*x;
}
int sqrdist(int a, int b)
{
	return sqr(y[a]-y[b]) + sqr(x[a]-x[b]);
}

bool encloses(int a, int b)
{
	return radius[a] > radius[b] && 
		sqrdist(a, b) < sqr(radius[a] - radius[b]);
}

bool isChild(int parent, int child)
{
	if(!encloses(parent, child)) {
		return false;
	}
	
	for(int i=0; i<n; i++){
		if(i!=parent && i!=child && encloses(parent, i) && encloses(i, child)){
			return false;
		}
			
	}
	
	return true;
}

TreeNode* getTree(int root){
	TreeNode* ret = new TreeNode();
	for(int ch=0; ch<n; ch++){
		printf("isChild value : %d\n", isChild(root, ch));
		if(isChild(root, ch)){
			ret->children.push_back(getTree(ch));
		}
	}
	return ret;
}

int height(TreeNode* root){
	vector<int> heights;
	int size = root->children.size();
	printf("size : %d\n", size);
	for(int i=0; i<size; i++){
		heights.push_back(height(root->children[i]));
	}
	
	if(heights.empty()){
		return 0;
	}
	
	sort(heights.begin(), heights.end());
	
	if(heights.size()>=2){
		longest = max(longest, 2+heights[heights[heights.size()-1]] + 
								heights[heights[heights.size()-2]]);
	}
	
	return heights.back() + 1;
}

int solve(TreeNode* root){
	longest=0;
	int h=height(root);
	
	return max(h, longest);
}

