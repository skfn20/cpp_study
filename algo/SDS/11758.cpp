#include<iostream>

using namespace std;

int CCW(int ax, int ay, int bx, int by, int cx, int cy)
{
	int res=(ax*by+bx*cy+cx*ay)-(ay*bx+by*cx+cy*ax);
	if(res<0) return -1;
	else if(res>0) return 1;
	else return 0;
}

int main()
{
	int ax, ay, bx, by, cx, cy;
	cin >> ax >> ay >> bx >> by >> cx >> cy;	
	
	cout << CCW(ax, ay, bx, by, cx, cy) << "\n";
	
	return 0;
}

