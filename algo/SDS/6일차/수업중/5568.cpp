#include<iostream>
#include<vector>
#include<string>
#include<set>

using namespace std;

int main()
{
	int n, k;
	
	cin >> n >> k;
	
	vector<string> nums(n);
	
	for(int i=0; i<n; i++){
		cin >> nums[i];
	}
	
	set<string> s;
	string temp="";
	
	if(k==2){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(i!=j){
					temp = nums[i] + nums[j];
					s.insert(temp);
					temp="";
				}
			}
		}
	}else if(k==3){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				for(int x=0; x<n; x++){
					if(i!=x && j!=x && i!=j){
						temp= nums[i]+nums[j]+nums[x];
						s.insert(temp);
						temp="";
					}
				}
			}
		}
	}else if(k==4){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				for(int x=0; x<n; x++){
					for(int y=0; y<n; y++){
						if(i!=j && i !=x && i!=y && j!=x && j!=y && x!=y){
							temp=nums[i]+nums[j]+nums[x]+nums[y];
							s.insert(temp);
							temp="";
						}
					}
				}
			}
		}
	}

	cout << s.size() << endl;
	
	return 0;
}
