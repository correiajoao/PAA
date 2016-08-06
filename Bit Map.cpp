#include <bits/stdc++.h>
#define DIM 1000 
using namespace std;

int l,c;
int total;
int processBitMap(char matrix[][DIM], int li, int lf, int ci, int cf){
	bool controlZero = true;
	bool controlOne = true;
	if(total == 50){
		printf("\n");
		total=0;
	}
	
	if(lf-1 < li || cf-1 < ci){
		return 0;
	}
	
	for(int i=li;i<lf;i++){				
		for(int j=ci;j<cf;j++){				
			if(matrix[i][j] == '0'){
				controlOne = false;				
			}else{
				controlZero = false;
			}
		}
		
	}
	
	if(controlZero){
		printf("0");
		total++;
	}else if(controlOne){
		printf("1");
		total++;
	}else{
		printf("D");
		total++;
		if((lf-li)%2 == 0 && (cf-ci)%2 == 0){
			processBitMap(matrix,li,(li+lf)/2,ci,(ci+cf)/2);
			processBitMap(matrix,li,(li+lf)/2,(ci+cf)/2,cf);
			processBitMap(matrix,(li+lf)/2,lf,ci,(ci+cf)/2);
			processBitMap(matrix,(li+lf)/2,lf,(ci+cf)/2,cf);
		}else if((lf-li)%2 == 1 && (cf-ci)%2 == 1){
			processBitMap(matrix,li,((li+lf)/2)+1,ci,((ci+cf)/2)+1);
			processBitMap(matrix,li,((li+lf)/2)+1,((ci+cf)/2)+1,cf);
			processBitMap(matrix,((li+lf)/2)+1,lf,ci,((ci+cf)/2)+1);
			processBitMap(matrix,((li+lf)/2)+1,lf,((ci+cf)/2)+1,cf);
		}else if(((cf-ci)%2) == 1){
			processBitMap(matrix,li,(li+lf)/2,ci,((ci+cf)/2)+1);
			processBitMap(matrix,li,(li+lf)/2,((ci+cf)/2)+1,cf);
			processBitMap(matrix,(li+lf)/2,lf,ci,((ci+cf)/2)+1);
			processBitMap(matrix,(li+lf)/2,lf,((ci+cf)/2)+1,cf);
		}else if(((lf-li)%2) == 1){
			processBitMap(matrix,li,((li+lf)/2)+1,ci,(ci+cf)/2);
			processBitMap(matrix,li,((li+lf)/2)+1,(ci+cf)/2,cf);
			processBitMap(matrix,((li+lf)/2)+1,lf,ci,(ci+cf)/2);
			processBitMap(matrix,((li+lf)/2)+1,lf,(ci+cf)/2,cf);
		}

	}
	return 0;
}

int main(){
	int i,n;
	
	scanf("%d", &n);
	while(n>0){
		scanf("%d", &l);
		scanf("%d", &c); 
		char matrix[l+1][DIM];
		
		for(i=0;i<l;i++){
			scanf(" %s",matrix[i]);
		}
		total=0;
		processBitMap(matrix,0,l,0,c);
		printf("\n");
		n--;
	}

	
	return 0;
}
