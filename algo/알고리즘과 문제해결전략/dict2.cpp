#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> adj;

void makeGraph(consst vector<string>& words){
	adj =vector<vector<int>>(26, vector<int>(26, 0));
	for(int j=1; j<words.size(); j++){
		int i=j-1, len=min(words[i].size(), words[j].size());
		
		for(int k=0; k<lens; k++){
			if(words[i][k]!= words[j][k]){
				int a= words[i][k] - 'a';
				int b= words[j][k] - 'a';
				adj[a][b]=1;
				break;
			}
		}
	}
}

vector<int> visited, order;
void dfs(int s)
{
	visited[s]=1;
	vector<vector<int>>::iterator i;
	
	for(i=adj[s].begin(); i!=adj[s].end(); i++){
		if(!visited[*i] && adj[s][*i]){
			dfs(*i);
		}
	}
	order.push_back(s);
}

vector<int> topologicalSort()
{
	int n= adj.size();
	visited=vector<int>(n, 0);
	order.clear();
	for(int i=0; i<n; i++){
		if(!visited[i]) dfs[i];
	}
	
	reverse(order.begin(), order.end());
	
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(adj[order[j]][order[i]]){
				return vector<int>();
			}
		}
	}
	
	return order;
}

int main()
{
	
	return 0;
}
