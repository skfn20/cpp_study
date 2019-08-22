#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct pair<long long, long long> Point;
typedef struct pair<pair<long long, long long>, pair<long long, long long> > Line;

long long CCW(Point p1, Point p2, Point p3)
{
	long long res=(p1.first*p2.second+p2.first*p3.second+p3.first*p1.second)
		-(p1.second*p2.first+p2.second*p3.first+p3.second*p1.first);
	
	return res;
}

bool isIntersect(Line x, Line y) {
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

int main()
{
	int T;
	scanf("%d", &T);
	
	vector<Line> Rect;
	
	for(int t=0; t<T; t++){
		Rect.clear();
		Point p[4];
		Line l, temp;
		scanf("%lld %lld %lld %lld", &l.first.first, &l.first.second, &l.second.first, &l.second.second);
		scanf("%lld %lld %lld %lld", &p[0].first, &p[0].second, &p[1].first, &p[1].second);
		p[2].first=p[0].first, p[2].second=p[1].second; 
		p[3].first=p[1].first; p[3].second=p[0].second;
		
		for(int idx=0; idx<2; idx++){
			temp.first=p[idx], temp.second=p[2];
			Rect.push_back(temp);
			temp.first=p[idx], temp.second=p[3];
			Rect.push_back(temp);
		}
		
		Point a=l.first, b=l.second;
		if(a>b) swap(a, b);
		if(p[0]>p[1]) swap(p[0], p[1]);
		
		long long minX=min(p[0].first, p[1].first);
		long long minY=min(p[0].second, p[1].second);
		long long maxX=max(p[0].first, p[1].first);
		long long maxY=max(p[0].second, p[1].second);
				
		// 직사각형 안에 포함되는지 확인  
		if(a.first>=minX && a.first <=maxX && b.first>=minX && b.first<=maxX &&
		   a.second>=minY && a.second<=maxY && b.second>=minY && b.second<=maxY){
			printf("T\n");
			continue;   	
		}
		// 교차되는지 확인  
		bool flag=true;
		for(int i=0; i<4; i++){
			if(isIntersect(l, Rect[i])){
				flag=false;
				break;
			}
		}
		
		if(!flag) printf("T\n");
		else	 printf("F\n");
	}
	
	return 0;
}
