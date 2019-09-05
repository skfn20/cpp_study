#include<iostream>
#include<vector>

using namespace std;

int n, order[10], pos[10], Max=-1;
bool visited[10]={false, };
int res[52][10];

void play()
{
	int hitter=1, score=0;
	for(int i=1; i<=n; i++){
		int out_count=0;
		while(true){
			if(res[i][order[hitter]]==0){
				hitter = (hitter+1)>=10 ? 1 : hitter+1;
				out_count++;
				if(out_count==3){
					for(int j=1; j<=9; j++) pos[j]=0;
					break;
				}
			}else{
				for(int j=1; j<=9; j++){
					if(pos[j]>0 || j==order[hitter]){
						pos[j]+=res[i][order[hitter]];
						if(pos[j]>=4){
							pos[j]=0; score++;
						}
					}
				}
				hitter = (hitter+1)>=10 ? 1 : hitter+1;
			}
		}
	}
	if(Max<score) Max=score;
}

void Permutation(int k)
{
	if(k>9){
		play();
		return;
	}
	for(int i=2; i<=9; i++){
		if(!visited[i]){
			order[k]=i;
			visited[i]=true;
			if(k==3) Permutation(k+2);
			else 	 Permutation(k+1);
			visited[i]=false;
		}
	}
}

int main()
{
	scanf("%d", &n);
	visited[1]=true;
	order[4]=1;
	
	for(int i=1; i<=n; i++)
		for(int j=1; j<=9; j++)
			scanf("%d", &res[i][j]);
			
	Permutation(1);
	printf("%d\n", Max);
	
	return 0;
}
