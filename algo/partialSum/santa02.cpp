#include<iostream>
#include<vector>

using namespace std;

int waysToBuy(const vector<int>& psum, int k)
{
    const int MOD = 20091101;

    int ret = 0;

    vector<long long> count(k,0);

    for(int i=0; i<k; i++){
        if(count[i]>=2) ret = (ret + ((count[i] * (count[i]-1))/2))%MOD;
    }

    return ret;
}

int maxBuys(const vector<int>& psum, int k)
{
    vector<int> ret(psum.size(), 0);

    vector<int> prev(k, -1);

    for(int i=0; i<psum.size(); i++){
        if(i>0) ret[i] = ret[i-1];
        else ret[i]=0;

        int loc = prev[psum[i]];
        if(loc !=-1) ret[i] = max(ret[i], ret[loc]+1);

        prev[psum[i]] = i;
    }
    return ret.back();
}