#include <bits/stdc++.h>
using namespace std;

void solve(){
    int l, r; cin >> l >> r;
    int n = r - l + 1;
    vector<int> a(n);
    for(int& i : a) cin >> i;
    int x = a[0];
    for(int i = 1; i < n; i++) x ^= a[i];
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}