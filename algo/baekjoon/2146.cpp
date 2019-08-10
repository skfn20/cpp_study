#include<iostream>
#include<vector>
#include<list>

using namespace std;

class Graph{
public:
    int V;
    int* parent;
    Graph(int n);
    int find_set(int x);
    void union_set(int x, int y);
};

Graph::Graph(int n)
{
    this->V = n;
    parent = new int[n];
    for(int i=0; i < n; i++) parent[i] = i;
}

int Graph::find_set(int x)
{
    while(x != parent[x]) x = parent[x];
    
    return x;
}

void Graph::union_set(int x, int y)
{
    x = find_set(x);
    y = find_set(y);
    
    if(x!=y){
        parent[y] = x;
    }
}

int main()
{
    int n;
    cin >> n;
    
    int** isLands = new int*[n];
    for(int i=0; i < n; i++){
        isLands[i] = new int[n]{0};
    }
    
    for(int i =0; i < n; i++){
        for(int j=0; j < n; j++){
            cin >> isLands[i][j];
        }
    }
    
    // set으로 같은 섬끼리 묶어주고 만약에 같은 set이 아니고 둘 다 1인 경우에 다리를 연결하는 방법을 cout
    // set 1 -> set 2 (1,2) -> (3, 4) : (2,2)
    
    int x_dir[4] = {-1, 1, 0, 0};
    int y_dir[4] = {0, 0, -1 ,1};
    
    Graph graph(n*n);
    vector<pair<int, int>> nodeList;
    
    for(int i =0; i < n; i++){
        for(int j =0; j < n; j++){
            if(isLands[i][j]==1){
                nodeList.push_back(make_pair(i, j));
                for(int idx=0; idx<4; idx++){
                    int tempX = i + x_dir[idx];
                    int tempY = j + y_dir[idx];
                    if((tempX >=0 && tempX <n) && (tempY>=0 && tempY < n)){
                        if(isLands[tempX][tempY]==1){
                            graph.union_set(i*n + j, tempX * n + tempY);
                        }
                    }
                }
            }
        }
    }
    int min = 1000;
    vector<pair<int, int>>::iterator i;
    vector<pair<int, int>>::iterator j;
    for(i= nodeList.begin(); i != nodeList.end(); i++){
        int x = (*i).first;
        int y = (*i).second;
        for(j=nodeList.begin(); j!=nodeList.end(); j++){
            int tempX = (*j).first;
            int tempY = (*j).second;
            if(!(tempX==x && tempY==y) && 
               graph.parent[tempX * n + tempY] != graph.parent[x*n + y]){
               int dis = abs(tempX-x) + abs(tempY-y) -1;
               if(dis < min) min = dis;
            }
        }
    }
    
    cout << min << "\n";
    
    return 0;
}