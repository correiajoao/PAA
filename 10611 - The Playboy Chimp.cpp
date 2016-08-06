#include<bits/stdc++.h>
using namespace std;

void macacoSearch(int* lady, int begin, int end, int h){
	int middle = (begin+end)/2;

	if(begin == end){
		if(lady[begin] < h){
			cout << lady[begin] << " X" << std::endl;	
		}else if(lady[begin]>h){
			cout  << "X " << lady[begin] << std::endl;			
		}
	}
	 
	else if(lady[middle] == h || lady[middle+1] == h){
		int ctr = 0;
		for(int i=middle; i>=0;i--){
			if(lady[i] != h){
				cout << lady[i];
				ctr = 1;
				break;
			}
		}
		
		if(ctr == 0){
			cout << "X";
		}
		
		cout << " ";
		ctr = 0;
		for(int i=middle+1; i<=end; i++){
			if(lady[i] != h){
				cout << lady[i] << std::endl;
				ctr = 1;
				break;
			}
		}
		
		if(ctr == 0){
			cout << "X" << std::endl;
		}
	}
	
	//condição de parada
	else if(lady[middle] < h && lady[middle+1] > h)
		cout << lady[middle] << " " << lady[middle+1] << std::endl;
	
	else if (lady[middle-1] < h && lady[middle+1] > h)
		cout << lady[middle-1] << " " << lady[middle] << std::endl;
			
	//está à esquerda
	else if (lady[middle] > h)
		macacoSearch(lady, begin, middle, h);

	//está à direita
	else if (lady[middle+1] < h)
		macacoSearch(lady, middle+1, end, h);
}

int main(){
		
	int i,n,q;
	cin >>n;
	int lady[n];
	for(i=0;i<n;i++){
		cin >> lady[i];
	}	
	
	cin >> q;
	int height[q];
	for(i=0;i<q;i++){
		cin >> height[i];
		macacoSearch(lady,0,n-1,height[i]);
	}
		
	return 0;
}
