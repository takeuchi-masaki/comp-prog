#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int>a(n);
    for(int&i:a) cin >> i;
    sort(a.begin(), a.end());
    long long add = 0, ans = a[0];
    for(int i = 1; i < n; i++){
        // if((a[i]+add)-(a[i-1]+add) < ans) break;
        add -= a[i-1]+add;
        ans = max(ans, a[i]+add);
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