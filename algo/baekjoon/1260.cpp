#include<iostream>
#include<list>
#include<queue>
#include<algorithm>

using namespace std;

class Graph{
public:
    int V;
    list<int>* adj;
    Graph(int n);
    void addEdge(int u, int v);
    void DFS(int s);
    void BFS(int s);
};

Graph::Graph(int n)
{
    this->V = n+1;
    adj = new list<int>[n+1];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::DFS(int s)
{
    static bool* visited = new bool[V]{false};

    visited[s] = true;

    printf("%d ", s);

    list<int>::iterator i;
    for(i = adj[s].begin(); i != adj[s].end(); i++){
        if(!visited[*i]) DFS(*i);
    }
}

void Graph::BFS(int s)
{
    bool* visited = new bool[V]{false};

    visited[s] = true;

    queue<int> q;
    q.push(s);

    while(!q.empty()){
        int v = q.front();
        q.pop();

        printf("%d ", v);

        list<int>::iterator i;

        for(i = adj[v].begin(); i != adj[v].end(); i++){
            if(!visited[*i]){
                visited[*i] = true;
                q.push(*i);
            }
        }
    }

    delete[] visited;
    visited = nullptr;
}

int main()
{
    int N, M, s;
    if(scanf("%d %d %d", &N, &M, &s)== 3){

        Graph graph(N);
        for(int i = 0 ; i < M; i++){
            int u, v;
            if(scanf("%d %d", &u, &v)==2){
                graph.addEdge(u, v);
            }
        }
        for(int i =1; i < graph.V; i++){
            graph.adj[i].sort();
        }
        printf("run\n");
        graph.DFS(s);
        printf("run\n");
        printf("\n");
        graph.BFS(s);
        printf("run\n");
        printf("\n");
    }
    return 0;
}