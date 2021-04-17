#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    bool diff = true;
    for(int i = 0; i < s.length(); i++){
        if((i & 1) == 0){
            // lowercase [97-122]
            if((int)s[i] < 97) {
                diff = false; 
                break;
            }
        } else {
            // uppercase [65-90]
            if((int)s[i] > 90) {
                diff = false; 
                break;
            }
        }
    }
    if(diff){
        cout << "Yes";
    } else {
        cout << "No";
    }
}

