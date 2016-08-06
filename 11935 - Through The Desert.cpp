#include <bits/stdc++.h>
using namespace std;

#define MAX 10000000
double remaining;

struct event {
  int distance;
  char text[50];
  int consumption;
};

typedef struct event Event;

Event textToEvent(char input[50]){
	Event result;
	sscanf(input,"%d %s %*s %d",&result.distance, result.text, &result.consumption);
	return result;
}

bool checkTank(Event events[50], int n){
	int i = 0;
	bool control = false;
	double consumption = 0;
	double currentDistance = 0;
	double capacity = n;
	double leak = 0;

	remaining = n;
	for(i=0; control == false; i++){
		if(events[i].text[0] == 'G' && events[i].text[1] == 'o' ){
			control = true;
		}
			
		if(i==0){
			currentDistance = 0;
		}else{
			currentDistance = events[i].distance - events[i-1].distance; 
		}
		
		capacity -= (currentDistance/100) * consumption; 
		capacity -= currentDistance*leak;
		
		if(capacity < 0.0){
			return false;
		}
		if(capacity < remaining){
			remaining = capacity;
		}
		
		if(events[i].text[0] == 'F'){
			consumption = events[i].consumption;
		}else if(events[i].text[0] == 'L'){
			leak++;
		}else if(events[i].text[0] == 'G' && events[i].text[1] == 'a'){
			capacity=n;
		}else if(events[i].text[0] == 'M'){
			leak=0;
		}
		
	}

	if(capacity >= 0){
		return true;
	}else{
		return false;
	}
}

double searchBestValue(Event events[50], int begin, int end){
	int middle = (begin+end)/2;
	
	if(begin == end){
		checkTank(events, begin);
		return begin-remaining;
	}else if(checkTank(events, middle)){
		searchBestValue(events, begin, middle);
	}else{
		searchBestValue(events, middle+1, end);
	}
}

int main(){
	int i = 0;
	Event current;
	Event events[50];
	char input[50];
		
	while(strcmp(input, "0 Fuel consumption 0") != 0){ 	
		scanf(" %[^\n]s", input);		 				 
		events[i++] = textToEvent(input);
		
		if(events[i-1].text[0] == 'G' && events[i-1].text[1] == 'o'){
			i=0;
			printf("%.3f\n", searchBestValue(events, 0, MAX));
		}
		
	}
	
	return 0;
}
