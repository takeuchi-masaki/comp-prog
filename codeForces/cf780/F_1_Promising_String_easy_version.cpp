#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int plus = 0, minus = 0, cons_minus = 0;
        for(int j = i; j < n; j++){
            if(s[j] == '+') {
                plus++;
            } else {
                minus++;
                if(j + 1 < n && s[j + 1] == '-'){
                    cons_minus++;
                }
            }
            if(plus == minus){
                ans++;
            } else if(minus > plus && (minus - plus) % 3 == 0){
                ans++;
            }
        }
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