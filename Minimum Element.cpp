#include<bits/stdc++.h>
using namespace std;

int arraySize;
int searchMinimumElement(int *array,int begin,int end){
	int middle = (begin+end)/2;
	
	if(end <= begin){
		return array[begin];	
	}else{
		if(array[end] < array[middle]){
			return searchMinimumElement(array, middle+1, end);
		}else{
			return searchMinimumElement(array, begin, middle);
		}	
	}	
}

int main(){
	int number;
	cin >> number;	
	while(number > 0){
		cin >> arraySize;
		int array[arraySize];
		for(int i=0;i<arraySize;i++){
				cin >> array[i];	
		}
		
		//Begin - inclusivo
		//End - Exclusivo
		cout << searchMinimumElement(array, 0, arraySize);
		number--;
	}
	return 0;
}