#include<iostream>
#include<vector>

using namespace std;

struct Point{
	long long x, y;
	Point(long long _x, long long _y){x=_x, y=_y;}
	bool operator < (const Point& p) const{
		if(x!=p.x){
			if(x<p.x) return true;
			else false;
		}else{
			if(y<p.y) return true;
			else false;
		}
	}
};

Point Max(Point p1, Point p2)
{
	if(p1<p2) return p2;
	else return p1;
}

Point Min(Point p1, Point p2)
{
	if(p1<p2) return p1;
	else return p2;
}

struct Line{
	Point p1, p2;
	Line(Point _p1, Point _p2){p1=_p1, p2=_p2};
};

long long CCW(Point p1, Point p2, Point p3)
{
	long long res=(p1.x*p2.y+p2.x*p3.y+p3.x*p1.y)-(p1.y*p2.x+p2.y*p3.x+p3.y*p1.x);
	
	return res;
}

bool isCross(Line l1, Line l2)
{
	long long res= CCW(l1.p1, l1.p2, l2.p1)*CCW(l1.p1, l1.p2, l2.p2);
	if(res>0) return false;
	else{
		if(Max(l1.p1, l1.p2) < Min(l2.p1, l2.p2)) return false;
	}
	
	return true;
}

int main()
{
	int N;
	scanf("%d", &N);
	
	vector<Line> L;
	
	long long x1, y1, x2, y2;
	for(int i=0; i<N; i++){
		scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
		Point p1(x1, y1), p2(x2, y2);
		Line temp(p1, p2);
		L.push_back(temp);
	}
	
	if(isCross(L[0], L[1])) printf("Cross\n");
	
	Point p1(0, 3);
	Point p2(1, 2);
	if(p1<p2) printf("small");
	
	return 0;
}
