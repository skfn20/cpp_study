#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

vector<int> partialSum(const vector<int>& a)
{
    vector<int> sum(a.size());
    sum[0] = a[0];

    for(int i =1; i < a.size(); i++){
        sum[i] = sum[i-1] + a[i];
    }

    return sum;
}

int rangeSum(const vector<int>& partial, int a,int b)
{
    if(a==0) return partial[b];
    return partial[b] - partial[a];
}

int zeroCloseSum(vector<int>& partial)
{
    sort(partial.begin(), partial.end(), greater<int>());

    int min = partial[0] - partial[1];
    for(int i=1; i < partial.size(); i++){
        int temp = partial[i] - partial[i-1];
        if(abs(temp) < abs(min)) min = temp;
    }

    return min;
}

int main()
{
    vector<int> a{-14, 7, 2, 3, -8, 4, -6, 8, 9, 11};
    vector<int> partial = partialSum(a);
    int zeroClose = zeroCloseSum(partial);

    cout << zeroClose << endl;

    return 0;
}

