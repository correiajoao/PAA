#include <bits/stdc++.h>
using namespace std;

int size;
int checkDistance(int* bamboo, int n){
	int i;
	for(i=0;i<size;i++){
		if((bamboo[i+1] - bamboo[i]) > n){
			return 0;
		}else if((bamboo[i+1] - bamboo[i]) == n){
			n--;
		}
	}
	return 1;
}

int searchEnergy(int* bamboo, int begin, int end){
		int middle = (begin+end)/2;
		
		if(begin <= end){
			if(checkDistance(bamboo, bamboo[begin]) == 1){
				int n = bamboo[begin] - 1;
				while(checkDistance(bamboo, n) == 0){
					n--;
				}
				return n;
			}else{
				int n = bamboo[begin] + 1;
				while(checkDistance(bamboo, n) == 0){
					n++;
				}
				return n;
			}
		}else if((checkDistance(bamboo, bamboo[middle])) == 1){
			return searchEnergy(bamboo, begin, middle-1); 
		}else{
			return searchEnergy(bamboo, middle+1, end);
		}
}

int main(){
	int m,n,i,j; 
	
	scanf("%d", &n);
	for(j=1;j<=n;j++){
		
		scanf("%d",&size);
		int bamboo[size+1];
		
		bamboo[0] = 0;
		for(i=1;i<=size;i++){
			scanf("%d", &bamboo[i]);	
		}
		
		printf("Case %d: %d\n",j,searchEnergy(bamboo,0,size));		
	}
	return 0;
}
