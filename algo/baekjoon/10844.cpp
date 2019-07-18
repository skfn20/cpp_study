#include<iostream>

using namespace std;

int main()
{
    int num;
    cin >> num;

    long long** num_digit = new long long*[num];
    long long mod = 1000000000;

    for(int i = 0; i < num; i++){
        if(i==0) num_digit[i] = new long long[10]{0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        else num_digit[i] = new long long[10]{0};
    }

    for(int i = 1; i< num; i++){
        for(int digit=0; digit<10; digit++){
            if(digit==0) num_digit[i][digit] = num_digit[i-1][1];
            else if(digit==9) num_digit[i][digit] = num_digit[i-1][8];
            else{
                num_digit[i][digit]=num_digit[i-1][digit+1] + num_digit[i-1][digit-1];
            }

            num_digit[i][digit] %= mod;
        }
    }

    for(int i =0 ; i <num; i++){
        for(int digit =0; digit <10; digit++){
            cout << num_digit[i][digit] << " ";
        }
        printf("\n");
    }

    int sum = 0;
    for(int i=0; i < 10; i++){
        sum += num_digit[num-1][i];
    }

    cout << sum % mod << endl;

    return 0;
}