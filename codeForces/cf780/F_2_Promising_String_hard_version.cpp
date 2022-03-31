#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    vector<int> pref_plus(n+1), pref_minus(n+1), cons_minus(n+1);
    
    for(int i = 0; i < n; i++){
        pref_plus[i + 1] = pref_plus[i];
        pref_minus[i + 1] = pref_minus[i];
        cons_minus[i + 1] = cons_minus[i];
        if(s[i] == '+'){
            pref_plus[i + 1]++;
        } else {
            pref_minus[i + 1]++;
            if(i + 1 < n && s[i + 1] == '-'){
                cons_minus[i + 1]++;
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