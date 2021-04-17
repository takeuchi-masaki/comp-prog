#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int total_time = 0;
    int correct = 0;
    int penalty[26] = {};
    bool solved[26] = {};
    while(1){
        int time;
        cin >> time;
        if(time == -1) break;
        char prob;
        string ans;
        cin >> prob >> ans;
        int letter = (int) prob - (int) 'A';
        if(ans == "right"){
            if(!solved[letter]){
                ++correct;
                total_time += time;
                total_time += penalty[letter];      
                solved[letter] = 1;
            }
        } else {
            penalty[letter] += 20;
        }
    }
    cout << correct << " " << total_time;
}

