#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin >> s;

    // pt1: non-decreasing
    cout << s[0];
    int idx = 1, n = s.size();
    for( ; idx < n; idx++){
        if(s[idx] < s[idx - 1]) break;
        cout << s[idx];
    }

    // pt2: non-increasing
    if(idx < n) cout << s[idx];
    idx++;
    for( ; idx < n; idx++){
        if(s[idx] == s[idx - 1]
        || s[idx] < s[idx - 1]){
            cout << s[idx];
        } else {
            char curr = s[idx - 1];
            cout << string(n - idx, curr);
            break;
        }
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}