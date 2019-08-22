#include<iostream>
#include<vector>
#include<set>

using namespace std;

typedef struct pair<long long, long long> Point;
typedef struct pair<pair<long long, long long>, pair<long long, long long> > Line;

long long CCW(Point p1, Point p2, Point p3)
{
	long long res=(p1.first*p2.second+p2.first*p3.second+p3.first*p1.second)
		-(p1.second*p2.first+p2.second*p3.first+p3.second*p1.first);
	
	return res;
}

int main()
{
	int N;
	scanf("%d", &N);
	
	vector<Point> P(N);
	vector<Line> L;
	set<long long> s;
	
	for(int T=0; T<N; T++){
		P.clear();
		L.clear();
		s.clear();
		
		for(int i=0; i<4; i++){
			scanf("%lld %lld", &P[i].first, &P[i].second);	
		}
		
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				if(i==j) continue;
				Line temp; temp.first=P[i], temp.second=P[j];
				long long dis=(P[i].first-P[j].first)*(P[i].first-P[j].first)+
								(P[i].second-P[j].second)*(P[i].second-P[j].second);
				s.insert(dis);
				L.push_back(temp);
			}
		}
		if(s.size()==2) printf("1\n");
		else printf("0\n");
		
		printf("run\n");
	}
	return 0;	
} 
