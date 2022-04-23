#include <bits/stdc++.h>
using namespace std;

void ans(bool ok){
    cout << (ok ? "YES\n" : "NO\n");
}

void solve(){
    int n;
    string s;
    cin >> n >> s;
    vector<int> idx_white;
    for(int i = 0; i < n; i++){
        if(s[i] == 'W'){
            idx_white.push_back(i);
        }
    }
    if((int)idx_white.size() == n){
        ans(true);
        return;
    }

    int start = 0;
    for(int i = 0; i < (int)idx_white.size(); i++){
        int end = idx_white[i];
        if(end - start == 0){
            start = end + 1;
            continue;
        }
        int cntB = 0, cntR = 0;
        for(int j = start; j < end; j++){
            if(s[j] == 'B'){
                cntB++;
            } else {
                cntR++;
            }
        }
        if(!cntB || !cntR){
            ans(false);
            return;
        }
        start = end + 1;
    }
    if(start == n){
        ans(true);
        return;
    }
    int cntB = 0, cntR = 0;
    for(int j = start; j < n; j++){
        if(s[j] == 'B'){
            cntB++;
        } else {
            cntR++;
        }
    }
    ans(cntB && cntR);
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve();
    }
}