#include<iostream>
#include<vector>

using namespace std;

vector<int> parent;

int find(int x)
{
	if(parent[x]==x) return x;
	else return parent[x]=find(parent[x]);
}

void union_set(int x, int y)
{
	int par_x = find(x);
	int par_y = find(y);
	
	parent[par_x]=par_y;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	for(int i=0; i<=n; i++){
		parent.push_back(0);
	}
	
	for(int i=0; i<m; i++){
		int a, b, c;
		cin >> a>> b>> c;
		if(a==0){
			union_set(b, c);
		}else if(a==1){
			if(find(b)==find(c)){
				cout << "YES" << endl;
			}else{
				cout << "NO" << endl;
			}
		}
	}
	
	return 0;
}

