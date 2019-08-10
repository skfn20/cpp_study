#include<iostream>
#include<map>

using namespace std;

map<int, int> coords;

bool isDominated(int x, int y)
{
	map<int, int>::iterator it = coords.lower_bound(x);
	
	if(it==coords.end()) return false;
	
	return y < it->second;
}


void removeDominated(int x, int y)
{
	map<int, int>::iterator it = coords.lower_bound(x);
	if(it==coords.end()) return;
	
	--it;
	while(true){
		if(it->second > y) break;
		
		if(it==coords.begin()){
			coords.erase(it);
			break;
		}else{
			map<int, int>::iterator jt = it;
			--jt;
			coords.erase(jt);
			it = jt;
		}
	}	
}

int registered(int x, int y)
{
	if(isDominated(x, y)) return coords.size();
	
	removeDominated(x, y);
	coords[x] = y;
	return coords.size();
}2

int main()
{
	int numTest;
	cin >> numTest;
	
	for(int T=1; T<=numTest; T++){
		int num_nerd;
		cin >> num_nerd;
		int ans=0;
		for(int i=0; i <num_nerd; i++){
			int x, y;
			cin >> x >> y;
			ans = registered(x, y);
		}
		cout << ans << endl;
		
	}
}
