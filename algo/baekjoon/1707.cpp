#include<iostream>
#include<list>
#include<queue>

using namespace std;

class Graph{
public:
    int V;
    list<int>* adj;
    bool* visited;
    int* color;
    Graph(int n);
    void addEdge(int u, int v);
    bool BFS(int s);
    bool findBipartite();
};

Graph::Graph(int n)
{
    this->V = n+1;
    adj = new list<int>[n+1];
    visited = new bool[n+1]{false};
    color = new int[n+1]{-1};
}

void Graph::addEdge(int u , int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bool Graph::BFS(int s)
{
    visited[s] = true;
    color[s] = 1;
    queue<int> que;
    que.push(s);

    while(!que.empty()){
        int v = que.front();
        que.pop();

        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); i++){
            printf("v, *i : %d %d\n", v, (*i));
            if(!visited[*i]){
                visited[*i] = true;
                que.push(*i);
                if(color[v] ==0 ){
                    color[*i] = 1;
                }else if(color[v] == 1){
                    color[*i] = 0;
                }
            }else{
                if(color[*i] != -1 && color[*i] == color[v]){
                    return false;
                }
            }
        }
    }
    return true;
}
int notVisitedIndex(bool* visited, int n)
{
    for(int i=1; i < n; i++){
        if(visited[i]==false) return i;
    }

    return -1;
}

bool Graph::findBipartite()
{
    int idx = 1;
    while(idx != -1){
        // idx > -1 case exception
        bool flag = BFS(idx);
        if(flag == false){
            return false;
        }
        idx = notVisitedIndex(visited, V);
    }
    return true;
}

int main()
{
    int T;
    cin >>  T;

    for(int i = 0; i < T; i++){
        int n, numE;
        cin >> n >> numE;
        Graph graph(n);

        for(int j = 0; j < numE; j++){
            int u , v;
            cin >> u >> v;
            graph.addEdge(u, v);
        }

        if(graph.findBipartite()){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}