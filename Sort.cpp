#include <bits/stdc++.h>
using namespace std;

void sort(int* vector){
	int i;
	int ctr=0;
	int aux;

	for(i=0;i<10;i++){
		if(vector[i] < 0){	
			aux = vector[i];
			vector[i] = vector[ctr];
			vector[ctr] = aux; 
			ctr++;
		}
	
	}
}

int main(){
	int i;
	int vector[10] = {-3,5,-2,6,8,4,7,-6,9,-11};
	sort(vector);
	
	for(i=0;i<10;i++){
		printf("%d ",vector[i]);
	}

	return 0;
}



