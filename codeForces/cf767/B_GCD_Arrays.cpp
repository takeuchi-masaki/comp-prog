#include <bits/stdc++.h>
using namespace std;

void solve(){
    int l, r, k; cin >> l >> r >> k;
    if(l == r){
        if(l != 1) cout << "YES\n";
        else cout << "NO\n";
        return;
    }

    int odd = r - l + 1;
    odd = ((odd&1) && (l&1)) + (odd>>1);
    // cout << odd << '\n';
    if(odd <= k){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}