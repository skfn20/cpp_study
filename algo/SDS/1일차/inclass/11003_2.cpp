#include<iostream>
#include<deque>
#include<vector>

using namespace std;

struct Item
{
	int index;
	int value;
};

int main()
{
	int size, space;
	scanf("%d %d", &size, space);
	
	deque<Item> dq;

	Item temp;
	temp.index=0;
	scanf("%d", &temp.value);
	
	dq.push_back(temp);
	for(int i=1; i<size; i++){
		Item temp;
		temp.index=i;
		scanf("%d", &temp.value);
		
		while(!dq.empty()  && temp.value < dq.back().value){
			dq.pop_back();
		}
		
		if(temp.index - space + 1 > temp.)
		
		
	}	
	
	
	return 0;
}
