#include<iostream>

typedef long long ll;

int main()
{
    ll num;
    std::cin >> num;

    ll num_digit[91][2];

    num_digit[1][0]=0;
    num_digit[1][1] = 1;

    for(int i = 2; i <=num; i++){
        num_digit[i][0] = num_digit[i-1][0] + num_digit[i-1][1];
        num_digit[i][1] = num_digit[i-1][0];
    }

    ll ans = num_digit[num][0] + num_digit[num][1];
    std::cout << ans << std::endl;

    return 0;
}