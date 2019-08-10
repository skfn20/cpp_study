#include<iostream>
#include<vector>

using namespace std;

vector<vector<int> > adj;

void getEulerCircuit(int s, vector<int>& circuit)
{
	for(int v=0; v<adj.size(); v++){
		while(adj[s][v]>0){
			adj[s][v]--;
			adj[v][s]--;
			getEulerCircuit(v, circuit);
		}
	}
	circuit.push_back(s);
}

vector<vector<int> > adj;

void makeGraph(const vector<string>& words)
{
	int n = words.size();
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i!=j){
				int i_size = words[i].size();
				int j_size = words[j].size();
				if(words[i][0]==words[j][j_size-1]) adj[i][j]=1;
				else if(words[i][i_size-1]==words[j][0]) adj[j][i]=1;
			}
		}
	}
}


int main()
{
	int numTest;
	cin >> numTest;
	
	for(int T=0; T<numTest; T++){
		int n;
		cin >> n;
		vector<string> words(n);
		
		for(int i=0; i<n; i++){
			cin >> words[i];
		}
		
	}
	
	return 0;
}
