#include<iostream>
#include<queue>

using namespace std;

int main()
{
    int x, k;
    cin >> x >> k;

    if(x > k){
        printf("%d\n", abs(x-k));
        return 0;
    }else if(x==k){
        printf("%d\n", 0);
        return 0;
    }

    int* visit_count = new int[100001]{0};

    queue<int> que;
    que.push(x);
    visit_count[x] = 1;

    while(!que.empty()){
        int temp = que.front();
        que.pop();
        printf("%d %d\n", temp, visit_count[temp]);
        if(temp==k){
            printf("%d\n", visit_count[temp]);
            break;
        }
        int dir[3] = { -1, 1, temp};
        for(int i =0 ; i< 3; i++){
            int temp_idx = temp + dir[i];
            if(visit_count[temp_idx]==0 && temp_idx <= 100000 && temp_idx>=0){
                que.push(temp_idx);
                visit_count[temp_idx] = visit_count[temp_idx]+1;
            }
        }
    }

    delete[] visit_count;
    visit_count = nullptr;

    return 0;
}