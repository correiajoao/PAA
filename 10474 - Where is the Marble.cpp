#João Lucas Marques Correia
#include <bits/stdc++.h>
using namespace std;

int sort(int *marble, int begin, int end){
	int ctr = begin;
	int pivot = marble[end];
	 
	for(int i=begin;i<=end;i++){
		if(marble[i] < pivot){	
			swap(marble[i], marble[ctr]);
			ctr++;
		}
	}
	swap(marble[ctr], marble[end]);
	return ctr;
}

void quick_sort(int *marble, int begin, int end){
	int position;
	if(begin < end){
		position = sort(marble, begin, end);
		quick_sort(marble,begin, position-1);
		quick_sort(marble,position+1,end);
	}	
}

int checkFirstPoint(int *marble, int begin, int end, int q){
	int middle = (begin+end)/2;
	
	if(begin > end){
		return -1;
	}else if(begin == end){
		if(marble[begin] == q){
			return begin;
		}else{
			return -1;
		}
	}else{
		if(marble[middle] >= q){
			//cout << "Left" << endl;
			return checkFirstPoint(marble,begin,middle,q);
		}else if(marble[middle] < q){
			//cout << "Right" << endl;
			return checkFirstPoint(marble,middle+1,end,q);
		}
	}	
}


int main(){
	int count = 1;
	int n;
	int q;
	
	cin >> n;
	cin >> q;
	
	while(n != 0 && q != 0){
		int marble[n];
		int query[q];
		
		for(int i=0; i<n;i++){
			cin >> marble[i];
		}
		
		quick_sort(marble, 0, n);
		cout << "CASE# " << count << ":" << endl;
		count++;
		for(int i=1; i<=q;i++){
			cin >> query[i];
			int result = checkFirstPoint(marble,0,n-1,query[i]); 
			if(result != -1){
				cout << query[i] << " found at " << result+1 << endl;
			}else{
				cout << query[i] << " not found" << endl;
			}
		}
		
		cin >> n;
		cin >> q;	
	}
	
	
	return 0;
}