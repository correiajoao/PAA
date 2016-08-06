#include <bits/stdc++.h>

using namespace std;

int n;
int searchDuplicatedNumber(int *value, int begin, int end){
	int middle = (begin+end)/2;
	
	if(value[0] != value[1]){
		return value[0];
	}else if(value[n-1] != value[n-2]){
		return value[n-1];	
	} else if(end - begin == 2){
		return value[begin+1];
	}else{
		if(middle % 2 == 1){
			if(value[middle] == value[middle-1]){
				return searchDuplicatedNumber(value, middle+1, end);			
			}else{
				return searchDuplicatedNumber(value, begin, middle);
			}
		}else{
			if(value[middle] == value[middle+1]){
				return searchDuplicatedNumber(value, middle+1, end);			
			}else{
				return searchDuplicatedNumber(value, begin, middle);			
			}
		}
	}
}

int main(){
	cin >> n;
	int value[n];
	
	for(int i=0; i<n;i++){
		cin >> value[i];
	}
	
	//Begin - inclusive
	//End - Exclusive
	cout << searchDuplicatedNumber(value, 0, n);
	return 0;
}