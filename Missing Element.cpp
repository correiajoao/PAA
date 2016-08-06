#include<bits/stdc++.h>
using namespace std;

int arraySize;

int searchMissingElement(int *array, int begin, int end){
	int middle = (begin+end)/2;
	int rate = (array[arraySize-1]-array[0])/arraySize;
	int rightValuePosition = array[0] + (middle)*rate;
	
	if(end - begin <= 1){
		if(rightValuePosition == array[middle]){
			return array[middle]+rate;
		}else{
			return array[middle]-rate;
		}
	}else{
		if(rightValuePosition == array[middle]){
			return searchMissingElement(array, middle+1, end);
		}else{
				return searchMissingElement(array, begin, middle);
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
		cout << searchMissingElement(array, 0, arraySize) << endl;
		number--;
	}
	
	return 0;
}