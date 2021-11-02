#include <bits/stdc++.h>
using namespace std;

void solve(){
    string keyboard, s; cin >> keyboard >> s;
    map<char, int> m;
    for(int i = 0; i < keyboard.size(); i++){
        m[keyboard[i]] = i;
    }
    int prev = m[s[0]], ans = 0;
    for(int i = 1; i < s.size(); i++){
        int next = m[s[i]];
        ans += abs(next-prev);
        prev = next;
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}