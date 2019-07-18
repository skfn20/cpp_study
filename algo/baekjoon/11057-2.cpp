#include<iostream>

using namespace std;

typedef long long ll;

ll d[10001][10];
ll mod = 10007;

int main()
{
    int n; 
    cin >> n;

    for(int i = 0; i <=9; i++) d[1][i] = 1;

    for(int i = 2; i <=n; i++){
        for(int j = 0; j <=9; j++){
            for(int k = 0; k <=j; k++){
                d[i][j] += d[i-1][k];
                d[i][j] %= mod;
            }
        }
    }

    for(int i =1; i <=n; i++){
        for(int j = 0; j <=9; j++){
            cout << d[i][j] <<" ";
        }
        cout << endl;
    }
    ll ans = 0;
    for(int i = 0; i <10; i++){
        ans += d[n][i];
    }

    ans %= mod;

    cout << ans <<endl;

    return 0;
}