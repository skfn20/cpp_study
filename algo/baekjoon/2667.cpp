#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>

using namespace std;

class Graph{
public:
    int V;
    int** house;
    bool** visited;
    int count;
    int move_dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
    vector<int> group_num;
    Graph(const int n);
    bool canMove(const int x, const int y);
    void DFS(const int x, const int y);
};

Graph::Graph(const int n)
{
    this->V = n;
    house = new int*[n];
    visited = new bool*[n];
    count =0;
    for(int i = 0; i < n; i++){
        house[i] = new int[n];
        visited[i] = new bool[n]{false};
    }
}

bool Graph::canMove(const int x, const int y)
{
    bool flag = false;
    
    if((x >=0 && x < V) && (y >=0 && y < V)) flag = true;
    
    return flag;
}

void Graph::DFS(const int x, const int y)
{
    visited[x][y] = true;
    count++;
    
    for(int idx=0; idx<4; idx++){
        int temp_x = x + move_dir[idx][0];
        int temp_y = y + move_dir[idx][1];
        
        if(canMove(temp_x, temp_y)){
            if(house[temp_x][temp_y] ==1 && !visited[temp_x][temp_y]){
                DFS(temp_x, temp_y);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    Graph graph(n);
    
    for(int i=0; i<n; i++){
        for(int j=0; j <n; j++){
            if(scanf("%1d", &graph.house[i][j])==1){

            }
        }
    }
    
    for(int i =0; i <n; i++){
        for(int j=0; j < n; j++){
            if(graph.house[i][j] ==1 && !graph.visited[i][j]){
                graph.count=0;
                graph.DFS(i, j);
                graph.group_num.push_back(graph.count);
            }
        }
    }
    
    sort(graph.group_num.begin(), graph.group_num.end());
    
    cout << graph.group_num.size() << "\n";
    vector<int>::iterator i;
    for(i = graph.group_num.begin(); i != graph.group_num.end(); i++){
        cout << (*i) << "\n";
    }
    
    return 0;
}
