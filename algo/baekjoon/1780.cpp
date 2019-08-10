#include<iostream>

using namespace std;

int numPosOne = 0;
int numNegOne = 0;
int numZero = 0;

void findNum(int** paper, int x, int y, int size)
{
	int temp_num = paper[x][y]; 
	
	bool flag = true;
	
	for(int i=0; i<size; i++){
		for(int j=1; j<size; j++){
			if(temp_num != paper[x+i][y+j]){
				flag = false;
				break;
			}
		}
	}
	
	if(flag){
		switch(temp_num){
			case 0:
				numZero++;
				break;
			case 1:
				numPosOne++;
				break;
			case -1:
				numNegOne++;
				break;
		}
		return;
	}else{
		int temp_size= size /3;
		for(int i=0; i<size; i+=temp_size){
			for(int j=0; j<size; j+= temp_size){
				findNum(paper, i+x, j+y, temp_size);
			}
		}
		return;
	}
} 

int main()
{
	int n;
	
	
	if(scanf("%d", &n)==1){
		int** paper = new int*[n];
		for(int i=0; i<n; i++){
			paper[i]=new int[n];
		}
		
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(scanf("%d", &paper[i][j])==1){
					
				}
			}
		}
		findNum(paper, 0, 0, n);
		
		printf("%d\n%d\n%d\n", numNegOne, numZero, numPosOne);
		
		//for(int i=0; i<n; i++){
		//	delete[] paper[i];
		//	paper[i]=nullptr;	
		//} 
		//delete[] paper;
		//paper=nullptr;
		
	}
	
	return 0;
}
