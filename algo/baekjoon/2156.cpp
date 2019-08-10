#include<iostream>

using namespace std;

int main()
{
    int n;
    if(scanf("%d", &n)==1){}
    int* wine = new int[n+1];
    int** record = new int*[n+1]{0};
    record[0] = new int[3]{0};
    
    for(int i=1; i<=n; i++){
        if(scanf("%d", &wine[i])==1){}
        record[i] = new int[3]{0};
    }
    
    record[3][0] = wine[1] + wine[2];
    record[3][1] = wine[1] + wine[3];
    record[3][2] = wine[2] + wine[3];
    
    for(int i=4; i <=n; i++){
        int temp0 = record[i-1][0] + wine[i];
        int temp1 = record[i-1][1] + wine[i];
        int temp2 = record[i-1][2] + wine[i];
        
        if(i%3==1){
            record[i][0] = temp0;
            record[i][1] = temp1;
            record[i][2] = record[i-1][2];
        }else if(i%3==2){
            record[i][0] = temp0;
            record[i][1] = record[i-1][1];
            record[i][2] = temp2;
        }else{
            record[i][0] = record[i-1][0];
            record[i][1] = temp1;
            record[i][2] = temp2;
        }
    }
    
    int max = record[n][0];
    
    for(int i=0; i <3; i++){
        if(record[n][i] > max) max = record[n][i];
    }
    printf("%d\n", max);
    
    
    delete[] wine;
    wine= nullptr;
    
    return 0;
}