#include<iostream>

using namespace std;

int dy[5]={0,1,-1,0,0};
int dx[5]={0,0,0,-1,1};
int dice[6]= {0, };
int map[20][20];
int order[1000];
int N, M, x, y, k;

void rotateDice(int dir)
{
	int temp=dice[0];
	switch(dir){
		case 1:
			dice[0]=dice[3];
			dice[3]=dice[5];
			dice[5]=dice[2];
			dice[2]=temp;
			break;
		case 2:
			dice[0]=dice[2];
			dice[2]=dice[5];
			dice[5]=dice[3];
			dice[3]=temp;
			break;
		case 3:
			dice[0]=dice[1];
			dice[1]=dice[5];
			dice[5]=dice[4];
			dice[4]=temp;
			break;
		case 4:
			dice[0]=dice[4];
			dice[4]=dice[5];
			dice[5]=dice[1];
			dice[1]=temp;
			break;
	}
}

inline bool inRange(int a, int b)
{
	return (a>=0 && a<N) && (b>=0 && b<M);
}

int main()
{
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &k);
	
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			scanf("%d", &map[i][j]);
	
	for(int i=0; i<k; i++)
		scanf("%d", &order[i]);
	
	for(int i=0; i<k; i++){
		int nxtX = x + dx[order[i]];
		int nxtY = y + dy[order[i]];
		if(!inRange(nxtX, nxtY)) continue;
		
		rotateDice(order[i]);
		
		if(map[nxtX][nxtY]==0){
			map[nxtX][nxtY]=dice[5];
		}else{
			dice[5]=map[nxtX][nxtY];
			map[nxtX][nxtY]=0;
		}
		printf("%d\n", dice[0]);
		
		x=nxtX;
		y=nxtY;
	}	
	
	
	return 0;
}
