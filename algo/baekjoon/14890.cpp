#include<iostream>

int N, L, ans=0;
int a[200][100];

int main()
{
	scanf("%d %d", &N, &L);
	for(int i=0; i<N; i++) 
		for(int j=0; j<N; j++) 
			scanf("%d", &a[i][j]);
	
	for(int i=0; i<N; i++) 
		for(int j=0; j<N; j++)
			a[i+N][j] = a[j][i];
	
	int cnt=1, i, j;	
	for(i=0; i< (N<<1); i++){
		cnt=1;
		for(j=0; j<N-1; j++){
			if(a[i][j]==a[i][j+1]) cnt++;
			else if(a[i][j]+1 == a[i][j+1] && cnt>=L) cnt=1;
			else if(a[i][j]-1 == a[i][j+1] && cnt>=0) cnt=-L+1;
			else break;
		}
		if(j==N-1 && cnt>=0) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
