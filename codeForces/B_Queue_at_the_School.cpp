#include <bits/stdc++.h>
using namespace std;
int n, t;

// bggbg
// gbggb
// ggbgb

string reorder(string & s){
    string next = s;
    for(int i = 0; i < n-1; i++){
        if(s[i] == 'B' && s[i + 1] == 'G'){
            next[i] = 'G', next[i + 1] = 'B';
        }
    }
    return next;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> t;
    string s; cin >> s;
    while(t--){
        s = reorder(s);
    }
    cout << s << '\n';
}