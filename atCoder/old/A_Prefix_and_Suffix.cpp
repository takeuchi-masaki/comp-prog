#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s, t;
    cin >> n >> s >> t;
    int res = 2*n;
    bool match = false;
    while(!match){
        if(s == t){
            match = true;
        } else {
            s=s.substr(1);
            t.pop_back();
        }
    }
    res-=s.length();
    cout << res << endl;
}