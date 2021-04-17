#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;
    int currPassed = 0, bPass = 0;
    for(int i = 0; i < n; i++){
        bool pass = false;
        if(currPassed < (a+b)){
            switch(s[i]){
                case 'a':
                    pass = true;
                    currPassed++;
                    break;
                case 'b':
                    if(bPass < b){
                        pass = true;
                        ++bPass;
                        ++currPassed;
                    }
                    break;
                default:
                    // do nothing
                    break;
            }
        }
        cout << (pass?"Yes":"No") << endl;
    }
}

