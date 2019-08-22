#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

struct Point{
	long long x, y;
};

long long CCW(Point p1, Point p2, Point p3)
{
	long long res=(p1.x*p2.y+p2.x*p3.y+p3.x*p1.y)-(p1.y*p2.x+p2.y*p3.x+p3.y*p1.x);
	
	return res;
}

int main()
{
	int N;
	scanf("%d", &N);
	
	vector<Point> P(N); 
	
	for(int i=0; i<N; i++){
		scanf("%lld %lld", &P[i].x, &P[i].y);
	}
	
	int size=P.size();
	long long sum=0;
	for(int i=1; i<size-1; i++){
		sum+= CCW(P[0], P[i], P[i+1]);
	}
	
	if(sum<0) sum = -sum;
	
	if(sum%2==0) printf("%lld.0\n", sum/2);
	else		 printf("%lld.5\n", sum/2); 
	
	return 0;
}

