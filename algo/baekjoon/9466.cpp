#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<int>& _num_vec, vector<int>& _group, int _n)
{
    int group_num = 1;
    bool* visited = new bool[_n+1]{false};
    vector<int> visited_node;

    for(int n_idx =1; n_idx <=_n; n_idx++){
        if(_group[n_idx] || visited[n_idx]) continue;

        visited_node.clear();
        visited[n_idx] = true;
        visited_node.push_back(n_idx);

        int now_node = _num_vec[n_idx];

        while(!visited[now_node] && _group[now_node] ==0){
            visited[now_node] = true;
            visited_node.push_back(now_node);
            now_node = _num_vec[now_node];
        }

        vector<int>::iterator i;
        
        for(i = visited_node.begin(); i!= visited_node.end(); i++){
            if((*i) != now_node) _group[*i] = -1;
            else break;
        }

        for(; i != visited_node.end(); i++){
            _group[*i] = group_num;
        }

        group_num++;
    }
}

int main()
{
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--){
        int n;

        vector<int> num_vec(n+1, 0);
        vector<int> group(n+1, 0);

        for(int i = 1; i <= n; i++){
            cin >> num_vec[i];
        }

        dfs(num_vec, group, n);

        int answer = 0;
        for(int i = 1; i <=n; i++){
            if(group[i] < 0) answer++;
        }

        cout << answer <<"\n";
    }
    return 0;
}