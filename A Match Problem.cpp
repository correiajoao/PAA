#include <bits/stdc++.h>

using namespace std;

int main()
{
    int input;
    int b = -1, s = -1, globalCounter = 1;

    while(s != 0 && b != 0){
        vector<int> bachelor;
        vector<int> spinster;

        cin >> b;
        cin >> s;

        if(s == 0 && b == 0)
            break;

        for(int i=0; i<b;i++){
            cin >> input;
            bachelor.push_back(input);
        }

        for(int i=0; i<s; i++){
            cin >> input;
            spinster.push_back(input);
        }

        sort(bachelor.begin(),bachelor.end());
        reverse(bachelor.begin(),bachelor.end());

        sort(spinster.begin(),spinster.end());
        reverse(spinster.begin(),spinster.end());
		
        int mini = INFINITY;
        int primeiroPar = -1;
        for(int i = 0; i<spinster.size();i++){
            if(abs(bachelor.at(0) - spinster.at(i)) < mini){
                 mini = abs(bachelor.at(0) - spinster.at(i));
                 primeiroPar = i;
            }
        }

        int counter = 0;
        int size = bachelor.size();
        for(int i=0; i<size; i++){
            if(counter != spinster.size()){
                bachelor.erase(bachelor.begin());

                primeiroPar++;
                primeiroPar %= spinster.size();
                counter++;
            }else{
                break;
            }
        }

        if(!bachelor.empty()){
            cout << "Case " << globalCounter << ": " << bachelor.size() << " " << bachelor.back() << endl;
        }else{
            cout << "Case " << globalCounter << ": 0" << endl;
        }
        globalCounter++;
    }
    return 0;
}
