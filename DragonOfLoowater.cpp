#include <bits/stdc++.h>

using namespace std;

int main(){
    int input;
    int h, k;

    cin >> h;
    cin >> k;
    while(h!=0 && k!=0){
        vector<int> diameter;
        vector<int> height;
	    vector<int> remain;


            for(int j = 0; j<h; j++){
                cin >> input;
                diameter.push_back(input);
				remain.push_back(input);
            }

            for(int j = 0; j<k; j++){
                cin >> input;
                height.push_back(input);
            }

        if(diameter.size() > height.size()){
            cout << "Loowater is doomed!" << endl;
        }else{

        sort(diameter.rbegin(), diameter.rend());
        sort(height.rbegin(), height.rend());

        int mini = INFINITY;
        int primeiroPar = -1;
        for(int i = 0; i<height.size();i++){
           if(height.at(i) - diameter.at(0) >= 0 && height.at(i) - diameter.at(0) < mini){
               mini = height.at(i) - diameter.at(0);
               primeiroPar = i;
           }
        }
		
		if(primeiroPar == -1){
			cout << "Loowater is doomed!" << endl;
		}else{
			
        int counter = 0;
        int total = 0;
        int size = diameter.size();
        for(int i=0; i<size; i++){
            if(counter != height.size()){
                if(diameter.at(i) <= height.at(primeiroPar)){
                    total += height.at(primeiroPar);
					counter++;
					remain.erase(remain.begin());
                }else{
					primeiroPar++;
                	primeiroPar %= height.size();
                	counter++;
					i--;
				}
			 }else{
                break;
             }
        }
		
		if(remain.empty()){
        	cout << total << endl;
		}else{	
				cout << "Loowater is doomed! - Remains" << remain.size() << " Total " << total	<< endl;
				
		}
		
		}
			
        }
        cin >> h;
        cin >> k;
    }


    return 0;
}
