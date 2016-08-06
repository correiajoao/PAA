#include <bits/stdc++.h>
#define DIM 100

using namespace std;

bool checkPoint(int li, int lf, int ci, int cf, int x,int y){
	if(li<=x && x<lf && ci<=y && y<cf){
		return true;
	}else{
		return false;
	}
}

void processMatrix(int li, int lf, int ci, int cf, int x, int y){
	int x1,x2,x3,x4;
	int y1,y2,y3,y4;
	x1=x2=x3=x4=x;
	y1=y2=y3=y4=y;
	
	if(lf - li == 1 || cf - ci == 1){
			return;
	}else{	
		int lMiddle = (li+lf)/2;
		int cMiddle = (ci+cf)/2;

		cout << "Tiling" << endl;
		if(!checkPoint( li, lMiddle, cMiddle, cf, x, y)){
			x1 = lMiddle-1;
			y1 = cMiddle;
			cout << lMiddle-1 << " - " << cMiddle << endl;
		}if(!checkPoint( li, lMiddle, ci, cMiddle, x, y)){
			x2 = lMiddle-1;
			y2 = cMiddle-1;
			cout << lMiddle-1 << " - "  << cMiddle-1 << endl;
		}if(!checkPoint( lMiddle, lf, ci, cMiddle, x, y)){
			x3 = lMiddle;
			y3 = cMiddle-1;
			cout << lMiddle << " - "  << cMiddle-1 << endl;
		}if(!checkPoint( lMiddle, lf, cMiddle, cf, x, y)){
			x4 = lMiddle;
			y4 = cMiddle;
			cout << lMiddle << " - "  << cMiddle << endl;
		}
		
		processMatrix( li, lMiddle, cMiddle, cf, x1, y1);
		processMatrix( li, lMiddle, ci, cMiddle, x2, y2);
		processMatrix( lMiddle, lf, ci, cMiddle, x3, y3);
		processMatrix( lMiddle, lf, cMiddle, cf, x4, y4);
	}
	
}

int main(){
	int n;
	int x, y;
	
	cin >> n;
	cin >> x;
	cin >> y;
	
	processMatrix(0,n,0,n,x,y);
	return 0;	
}