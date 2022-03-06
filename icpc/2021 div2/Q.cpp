#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin >> s;
    set<char> S;
    int pt1End = 0;
    for(int i = 0; i < s.size(); i++){
        if(!S.insert(s[i]).second){
            S.clear();
            pt1End = i;
            break;
        }
    }
    for(int i = pt1End; i < s.size(); i++){
        if(S.size() == 7) S.clear();
        if(!S.insert(s[i]).second){
            cout << "0\n";
            return;
        }
    }
    cout << "1\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}