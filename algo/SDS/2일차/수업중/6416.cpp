#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main()
{
	int x=1, y=1;
	
	int T=1;
	
	vector<pair<int, int> > edges;
	set<int> nodes;
	set<int> in_degree;
	while(true){	
		scanf("%d %d", &x, &y);
		if((x==-1 && y==-1)) break;
		if(x==0 && y==0){
			printf("%d %d %d\n",in_degree.size(), nodes.size(), edges.size());
			if(in_degree.size()== edges.size() && nodes.size() == edges.size()+1) printf("Case %d is a tree\n", T);
			else printf("Case %d is not a tree\n", T);
			//if(!edges.empty()) edges.clear();
			//if(!visited.empty()) visited.clear();
			//if(!in_degree.empty()) in_degree.clear();
			edges.clear();
			nodes.clear();
			in_degree.clear();
			T++;
			continue;
		}
		
		edges.push_back(make_pair(x, y));
		nodes.insert(x);
		nodes.insert(y);
		in_degree.insert(y);
	
	
	}
	
	
	return 0;
}
