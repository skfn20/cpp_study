#include<iostream>

using namespace std;

int main()
{
    int num;
    cin >> num;

    int** num_digit = new int*[num];
    for(int i = 0; i < num; i++){
        num_digit[i] = new int[10]{0};
    }

    for(int i =0; i < num; i++){
        num_digit[0][i] = 1;
    }

    for(int i = 1; i < num; i++){
        for(int digit = 0; digit <=9; digit++){
            for(int k = 0; k <= digit; k++){
                num_digit[i][digit] += num_digit[i-1][k];
                num_digit[i][digit] %= 10007;
            }
        }
    }
    for(int i = 0; i < num; i++){
        for(int j = 0 ; j < 10; j++){
            printf("%d ", num_digit[i][j]);
        }
        printf("\n");
    }

    int sum = 0;
    for(int i = 0; i < 10; i++){
        sum += num_digit[num-1][i];
    }

    sum %= 10007; 

    printf("%d\n", sum);
    return 0;
}