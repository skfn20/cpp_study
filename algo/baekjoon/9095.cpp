#include<iostream>

int d[11];
using namespace std;

int main()
{
    int numTest;
    cin >> numTest;

    d[0] = 1;
    d[1] = 1;
    d[2] = 2;

    int n ;
    cin >> n;

    for(int i = 3; i <= n; i++){
        d[i] = d[i-1] + d[i-2] +d[i-3];
        printf("d[%d]: %d\n", i, d[i]);
    }

    return 0;
}