#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int checkFortress(const vector<pair<int, int>>& fortress, const vector<int>& radian, int a, int b)
{
    int x1 = fortress[a].first; int y1 = fortress[a].second;
    int x2 = fortress[b].first; int y2 = fortress[b].second;
    int r1 = radian[a]; int r2 = radian[b];

    int dis = sqrt(pow((x1-x2), 2) + pow((y1-y2), 2));
    if(r1 > dis + r2) return 1;
    if(r2 > dis + r1) return 2;

    return 0;
}

int find_set(const vector<int>& parent, int x)
{
    if(x>=parent.size()) return -1;

    while(parent[x] != x){
        x = parent[x];
    }

    return x;
}

void union_set(vector<int>& parent, int x, int y)
{
    int x_set = find_set(parent, x);
    int y_set = find_set(parent, y);

    if(x_set!=y_set){
        parent[y_set] = x;
    }
}

int main()
{
    int numTest;
    cin >> numTest;

    for(int T=1; T<=numTest; T++){
        int n;
        cin >> n;
        vector<int> radian(n);
        vector<pair<int, int> > fortress(n);
        vector<int> parent(n);

        for(int i=0; i<n; i++){
            cin >> fortress[i].first >> fortress[i].second >> radian[i];
            parent[i] = i;
        }

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int checkValue = checkFortress(fortress, radian, i, j);
                if(checkValue==1) union_set(parent, i, j);
                else if(checkValue==2) union_set(parent, j, i);
            }
        }

        for(int i=0; i<n; i++) printf("%d ", parent[i]);
        printf("\n");

        
    }

    return 0;
}