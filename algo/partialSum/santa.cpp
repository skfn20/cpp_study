#include<iostream>
#include<vector>

using namespace std;

vector<int> partialSum(const vector<int>& a)
{
    vector<int> partial(a.size());
    partial[0] = a[0];
    for(int i=1; i < a.size(); i++){
        partial[i] = partial[i-1] + a[i];
    }
    return partial;
}

int rangeSum(const vector<int>& partial, int a, int b)
{
    if(a==0) return partial[b];
    else return partial[b] - partial[a-1];
}

int main()
{
    int numTest;
    cin >> numTest;

    for(int T=1; T<=numTest; T++){
        int numBox, numChild;
        cin >> numBox >> numChild;

        vector<int> doll_box;
        for(int i =0; i < numBox; i++){
            int temp;
            cin >> temp;
            doll_box.push_back(temp);
        }
        vector<int> partial = partialSum(doll_box);

        int count =0;
        for(int i=0; i<numBox; i++){
            for(int j=0; j<= i; j++){
                int num_doll = rangeSum(partial, j, i);
                if(num_doll % numChild ==0) count++;
            }
        }

        cout << "#" << T << " " << count << "\n";
    }

    return 0;
}