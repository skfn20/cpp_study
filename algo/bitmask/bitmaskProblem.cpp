#include<iostream>

using namespace std;

bool isBitSet(unsigned long long a, int b){
    return (a &(1 << b));
}

int main()
{
    bool flag;
    unsigned long long a = 15321;
    flag = isBitSet(a, 33);

    cout << flag << "\n";

    return 0;
}