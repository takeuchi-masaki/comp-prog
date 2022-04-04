#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int& i : a) cin >> i;
    int l = 0, r = n - 1;
    while(l < n && a[l + 1] == 1) l++;
    while(r > 0 && a[r - 1] == 1) r--;
    cout << max(r - l, 0) << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}