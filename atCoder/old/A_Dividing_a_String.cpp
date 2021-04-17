#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length(), res = 0, pt = 0;
    bool one = false;
    // divide into non-equal consecutive sub-arrays
    while(pt < n){
        // at 2nd to last position, if last two chars are the same
        // add one to the necessary partisions
        if(pt == n-2 && s[pt] == s[pt+1]){
            res++;
            break;
        }
        // default divide into blocks of 1
        // if equal to the previous, get a block of 2 instead
        // never need consecutive blocks of 2 or a block of 3
        if(one && s[pt] == s[pt-1]){
            res++;
            pt+=2;
            one = false;
        } else {
            res++;
            pt++;
            one = true;
        }
    }
    cout << res << endl;
}