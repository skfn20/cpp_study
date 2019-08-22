#include<iostream>
#include<vector>
#include<set>
using namespace std;
typedef struct pair<long long, long long> Point;

int main()
{
	int N;
	scanf("%d", &N);
	
	vector<Point> P(4);
	set<long long> s;
	
	for(int T=0; T<N; T++){
		s.clear();
		for(int i=0; i<4; i++){
			scanf("%lld %lld", &P[i].first, &P[i].second);	
		}
		for(int i=0; i<=2; i++){
			for(int j=i+1; j<4; j++){
				long long dis= (P[i].first-P[j].first)*(P[i].first-P[j].first)+
								(P[i].second-P[j].second)*(P[i].second-P[j].second);
				s.insert(dis);
			}
		}
		if(s.size()==2) printf("1\n");
		else printf("0\n");
	}
	return 0;	
} 
