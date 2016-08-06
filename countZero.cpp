#include<bits/stdc++.h>
using namespace std;

int arraySize;
int searchNumberOfZero(int *array, int begin, int end){
	int middle = (begin+end)/2;
	if(begin == end){
		
		if(array[begin] == 0){
			return arraySize;
		}else{
			return 0;
		}
		
	}else{
		if(array[middle] == 1){
			return searchNumberOfZero(array, middle+1, end);
		}else{
			if(array[middle - 1] == 1){
				return arraySize-middle;
			}else{
				return searchNumberOfZero(array, begin, middle);
			}
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
		cout << searchNumberOfZero(array, 0 , arraySize) << endl;
		number--;
	}
	return 0;
}