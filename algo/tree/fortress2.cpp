#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct TreeNode{
    vector<TreeNode*> children;
};

int longest;

int height(TreeNode* root){
    vector<int> heights;
    int size = root->children.size();

    for(int i=0; i< size; i++) heights.push_back(height(root->children[i]));

    if(heights.empty()) return 0;
    sort(heights.begin(), heights.end());

    if(heights.size() >=2){
        longest = max(longest, 2+ heights[heights.size()-2]+heights[heights.size()-1]);
        printf("%d\n", longest);
    }
    return heights.back() +1;
}

int solve(TreeNode* root){
    longest =0;

    int h= height(root);

    return max(longest, h);
}

int n, y[100], x[100], radius[100];
int sqr(int x){
    return x * x;
}

int sqrdist(int a, int b)
{
    return sqr(y[a]- y[b]) + sqr(x[a] -x[b]);
}

bool encloses(int a, int b)
{
    return radius[a] > radius[b] &&
            sqrdist(a, b) < sqrdist(radius[a], radius[b]);
}

bool isChild(int parent, int child)
{
    if(!encloses(parent, child)) return false;

    for(int i=0; i<n; i++){
        if(i != parent && i != child && encloses(parent, i) && encloses(i, child) ) return false;
    }

    return true;
}

TreeNode* getTree(int root){
    TreeNode* ret = new TreeNode();

    for(int ch=0; ch<n; ch++){
        if(isChild(root, ch)) ret->children.push_back(getTree(ch));
    }

    return ret;
}

int main()
{
    int numTest;
    cin >> numTest;

    for(int T=1; T<=numTest; T++){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> x[i] >> y[i] >> radius[i];
        }
        //printf("%d %d %d\n", x[0], y[0], radius[0]);
        TreeNode* tree = getTree(0);

        int ans = solve(tree);
        printf("%d\n", ans);
    }
}