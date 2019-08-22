#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct pair<int, int> Point;
typedef struct pair<pair<int, int>, pair<int, int> > Line;

long long CCW(Point p1, Point p2, Point p3)
{
	long long res=(p1.first*p2.second+p2.first*p3.second+p3.first*p1.second)
		-(p1.second*p2.first+p2.second*p3.first+p3.second*p1.first);
	
	return res;
}

int isIntersect(Line x, Line y) {
    Point a = x.first; Point b = x.second;
    Point c = y.first; Point d = y.second;
    long long ab = CCW(a, b, c)*CCW(a, b, d);
    long long cd = CCW(c, d, a)*CCW(c, d, b);
    if (ab == 0 && cd == 0) {
        if (a > b)swap(a, b);
        if (c > d)swap(c, d);
        return c <= b&&a <= d;
    }
    return ab <= 0 && cd <= 0;
}

vector<int> parent;
vector<int> num_parent;

int find(int x)
{
	while(x!=parent[x]) x=parent[x];
	
	return parent[x];
}

void union_set(int x, int y)
{
	x=find(x); y=find(y);
	if(x!=y){
		parent[x]=y;
		num_parent[y] += num_parent[x];
		num_parent[x]=0;
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	vector<Line> L(N);
	parent.resize(N);
	num_parent.resize(N, 1);
	
	for(int i=0; i<N; i++){
		scanf("%d %d %d %d", &L[i].first.first, &L[i].first.second,
							 &L[i].second.first, &L[i].second.second);
		parent[i]=i;
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(i==j) continue;
			if(isIntersect(L[i], L[j])) union_set(i, j);
		}
	}
	
	int cnt=0, max=0;
	for(int i=0; i<N; i++){
		if(num_parent[i]!=0) cnt++;
		if(max < num_parent[i]) max=num_parent[i];
	}
	
	printf("%d\n%d\n", cnt, max);
	
	return 0;
}
