#include<iostream>

using namespace std;

int circle[6][8];
bool visited[6];

void rotate(int idx, int dir)
{
	if(dir==1){
		int temp= circle[idx][7];
		for(int i=7; i>=1; i--) 
			circle[idx][i]= circle[idx][i-1];
		circle[idx][0]=temp;
	}else{ 
		int temp=circle[idx][0];
		for(int i=0; i<7; i++) 
			circle[idx][i] = circle[idx][i+1];
		circle[idx][7]=temp;
	}
} 

void Solve(int idx, int dir)
{
	visited[idx]=true;
	
	if(idx-1>=1 && !visited[idx-1])
		if(circle[idx-1][2]!=circle[idx][6]) 
			Solve(idx-1, -dir);
			
	if(idx+1<=4 && !visited[idx+1])
		if(circle[idx+1][6]!=circle[idx][2]) 
			Solve(idx+1, -dir);
	
	rotate(idx, dir);
}

int main()
{
	for(int i=1; i<5; i++)
		for(int j=0; j<8; j++) 
			scanf("%1d", &circle[i][j]);
		
	int k;
	scanf("%d", &k);
	for(int i=0; i<k; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		
		for(int i=0; i<6; i++) visited[i]=false;
		Solve(a, b);
	}
	
	int ans=0;
	for(int i=1; i<=4; i++)
		if(circle[i][0]==1) ans += (1<<(i-1));
		
	printf("%d\n", ans);
	return 0;
}
