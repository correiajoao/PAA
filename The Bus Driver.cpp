#include <bits/stdc++.h>

using namespace std;

int main(){
    int input;
    int n, d, r;

    cin >> n;
    cin >> d;
    cin >> r;
    while(n!=0 && d!=0 && r!=0){
        vector<int> manha;
        vector<int> tarde;

            for(int j = 0; j<n; j++){
                cin >> input;
                manha.push_back(input);
            }

            for(int j = 0; j<n; j++){
                cin >> input;
                tarde.push_back(input);
            }

        sort(manha.begin(), manha.end());
        sort(tarde.rbegin(), tarde.rend());
        
        int horas = 0;
        for(int i = 0; i<n; i++){
            if(manha.at(i) + tarde.at(i) > d){
                horas += manha.at(i) + tarde.at(i) - d;
            }
        }

        cout << horas*r << endl;

        cin >> n;
        cin >> d;
        cin >> r;
    }


    return 0;
}
