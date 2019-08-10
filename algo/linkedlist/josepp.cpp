#include<iostream>
#include<queue>
#include<list>

using namespace std;

void josephus(int n, int k)
{
    list<int> survivors;
    for(int i =1; i<=n; i++){
        survivors.push_back(i);
    }

    list<int>::iterator kill = survivors.begin();
    while(n>2){
        kill = survivors.erase(kill);
        if(kill==survivors.end()) kill = survivors.begin();

        n--;

        for(int i=0; i<k-1; i++){
            kill++;
            if(kill==survivors.end()) kill =survivors.begin();
        }
    }
    cout << survivors.front() << " " << survivors.back() <<endl;
}

int main()
{
    int numTest;
    cin >> numTest;

    for(int T=1; T<=numTest; T++){
        int n, k;
        cin >> n >> k;
        queue<int> q;
        for(int i=1; i<=n; i++){
            q.push(i);
        }
        int count =0;
        while(q.size() >2){
            if(count%k==0) q.pop();
            else{
                q.push(q.front());
                q.pop();
            }
            count++;
        }

        while(!q.empty()){
            cout << q.front() << " ";
            q.pop();
        }
        cout<<"\n";

    }

    return 0;
}