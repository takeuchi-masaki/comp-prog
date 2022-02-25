#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin >> s;
    vector<bool> haveKey(26);
    for(char c : s){
        if(c > 'a'){
            haveKey[c - 'a'] = true;
        } else {
            if(!haveKey[c - 'A']){
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}