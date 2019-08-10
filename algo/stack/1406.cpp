#include<iostream>
#include<stack>
#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
    char a[100000];
    printf("string : ");
    if(scanf("%s", a)==1){
        stack<char> left, right;

        int n = strlen(a);

        for(int i = 0; i < n; i++){
            left.push(a[i]);
        }

        int numCase;
        printf("case : ");
        if(scanf("%d", &numCase)==1){

            while(numCase--){
                char op;
                printf("op : ");
                if(scanf(" %c", &op)==1){

                    switch(op){
                        case 'L':
                            if(!left.empty()){
                                right.push(left.top());
                                left.pop();
                            }
                            break;
                        case 'D':
                            if(!right.empty()){
                                left.push(right.top());
                                right.pop();
                            }
                            break;
                        case 'B':
                            if(!left.empty()){
                                left.pop();
                            }
                            break;
                        case 'P':
                            char temp;
                            printf("add string : ");
                            if(scanf(" %c", &temp)==1){
                                left.push(temp);
                            }
                            break;
                    }
                }
            }

            while(!left.empty()){
                right.push(left.top());
                left.pop();
            }

            while(!right.empty()){
                printf("%c", right.top());
                right.pop();
            }

            printf("\n");
        }
    }
    return 0;
}

