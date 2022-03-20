#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s, t; cin >> s >> t;
    int idx = 0, ans = 0;
    for(char c : s){
        while(idx < t.size() && t[idx] != c){
            ans++;
            idx++;
        }
        if(idx >= t.size()){
            cout << "IMPOSSIBLE\n";
            return;
        }
        idx++;
    }
    ans += t.size() - idx;
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}