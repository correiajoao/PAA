#include <bits/stdc++.h>
using namespace std;

int sort(int *vector, int begin, int end){
	int ctr = begin;
	int pivot = vector[end];
	 
	for(int i=begin;i<=end;i++){
		if(vector[i] < pivot){	
			swap(vector[i], vector[ctr]);
			ctr++;
		}
	}
	
	swap(vector[ctr], vector[end]);
	return ctr;
}

void quick_sort(int *vector, int begin, int end){
	int position;
	if(begin < end){
		position = sort(vector, begin, end);
		quick_sort(vector,begin, position-1);
		quick_sort(vector,position+1,end);
	}	
}

int main(){
	int i;
	int vector[8] = {2,8,7,1,3,5,6,4};
	quick_sort(vector,0 ,7);
	
	for(i=0;i<8;i++){
		printf("%d ",vector[i]);
	}

	return 0;
}



